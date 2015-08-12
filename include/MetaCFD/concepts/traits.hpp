/*! \file cocepts/traits.hpp
\brief Template metaprogramming specific magic */
/*
MetaCFD library
Copyright (C) 2015, Ilya Eriklintsev

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

Contact information :
e-mail : erik.lite@gmail.com
*/
#ifndef METACFD_CONCEPTS_TRAITS_HPP_
#define METACFD_CONCEPTS_TRAITS_HPP_

#include <type_traits>
#include <typeindex>

namespace metacfd
{
  namespace traits
  {
    using yes = std::true_type;
    using no = std::false_type;

    namespace detail
    {
      // ######################################################################
      //! Used to delay a static_assert until template instantiation
      template <class T>
      struct delay_static_assert : std::false_type {};

      // ######################################################################
      // SFINAE Helpers

      //! Return type for SFINAE Enablers
      enum class sfinae {};

      // ######################################################################
      // Helper functionality for boolean integral constants and Enable/DisableIf
      template <bool H, bool ... T> struct meta_bool_and : std::integral_constant<bool, H && meta_bool_and<T...>::value> {};
      template <bool B> struct meta_bool_and<B> : std::integral_constant<bool, B>{};

      template <bool H, bool ... T> struct meta_bool_or : std::integral_constant<bool, H || meta_bool_or<T...>::value> {};
      template <bool B> struct meta_bool_or<B> : std::integral_constant<bool, B>{};

      // workaround needed due to bug in MSVC 2013, see
      // http://connect.microsoft.com/VisualStudio/feedback/details/800231/c-11-alias-template-issue
      template <bool ... Conditions>
      struct EnableIfHelper : std::enable_if<meta_bool_and<Conditions...>::value, sfinae> {};

      template <bool ... Conditions>
      struct DisableIfHelper : std::enable_if<!meta_bool_or<Conditions...>::value, sfinae> {};
    } // namespace detail

    //! Used as the default value for EnableIf and DisableIf template parameters
    /*! @relates EnableIf
    @relates DisableIf */
    static const detail::sfinae sfinae = {};

    // ######################################################################
    //! Provides a way to enable a function if conditions are met
    /*! This is intended to be used in a near identical fashion to std::enable_if
    while being significantly easier to read at the cost of not allowing for as
    complicated of a condition.

    This will compile (allow the function) if every condition evaluates to true.
    at compile time.  This should be used with SFINAE to ensure that at least
    one other candidate function works when one fails due to an EnableIf.

    This should be used as the las template parameter to a function as
    an unnamed parameter with a default value of cereal::traits::sfinae:

    @code{cpp}
    // using by making the last template argument variadic
    template <class T, EnableIf<std::is_same<T, bool>::value> = sfinae>
    void func(T t );
    @endcode

    Note that this performs a logical AND of all conditions, so you will need
    to construct more complicated requirements with this fact in mind.

    @relates DisableIf
    @relates sfinae
    @tparam Conditions The conditions which will be logically ANDed to enable the function. */
    template <bool ... Conditions>
    using EnableIf = typename detail::EnableIfHelper<Conditions...>::type;

    // ######################################################################
    //! Provides a way to disable a function if conditions are met
    /*! This is intended to be used in a near identical fashion to std::enable_if
    while being significantly easier to read at the cost of not allowing for as
    complicated of a condition.

    This will compile (allow the function) if every condition evaluates to false.
    This should be used with SFINAE to ensure that at least one other candidate
    function works when one fails due to a DisableIf.

    This should be used as the las template parameter to a function as
    an unnamed parameter with a default value of cereal::traits::sfinae:

    @code{cpp}
    // using by making the last template argument variadic
    template <class T, DisableIf<std::is_same<T, bool>::value> = sfinae>
    void func(T t );
    @endcode

    This is often used in conjunction with EnableIf to form an enable/disable pair of
    overloads.

    Note that this performs a logical AND of all conditions, so you will need
    to construct more complicated requirements with this fact in mind.  If all conditions
    hold, the function will be disabled.

    @relates EnableIf
    @relates sfinae
    @tparam Conditions The conditions which will be logically ANDed to disable the function. */
    template <bool ... Conditions>
    using DisableIf = typename detail::DisableIfHelper<Conditions...>::type;    

    //! Provides ability to choose type on conditional basis
    /*!
    @tparam B Expression that evaluates to boolean and on which depends return type. 
    @tparam T Return type in case that B were true.
    @tparam F Return type in case that B were false.
    */
    template<bool B, typename T, typename F>
    using Conditional = typename std::conditional<B, T, F>::type;

    
  } //namespace traits
} //namespace metacfd

#endif