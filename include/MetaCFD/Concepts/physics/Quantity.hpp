/*! \file cocepts/physics/Quantity.hpp
\brief Concept of real valued dimensional quantity */
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
#ifndef METACFD_CONCEPTS_PHYSICS_QUANTITY_HPP_
#define METACFD_CONCEPTS_PHYSICS_QUANTITY_HPP_

#include <metacfd\metacfd.hpp>

//Include required concepts
#include <metacfd\concepts\physics\Unit.hpp>
#include <metacfd\concepts\algebra\RealNumber.hpp>

namespace metacfd
{
  //! A Quantity is a real number value with an associated Unit
  template<typename U>
  struct Quantity {
    RealNumber val;
    explicit Quantity(RealNumber d) : val{ d } {}
  };

  //! Addition operation
  template<typename U>
  Quantity<U> operator+(Quantity<U> x, Quantity<U> y) // same dimension
  {
    return Quantity<U>{x.val + y.val};
  }

  //template<typename U1, typename U2>
  //std::common_type<U1, U2> operator+(Quantity<U1> x, Quantity<U2> y)  // error : different dimensions 
  //{
  //  static_assert(std::typeid(U1) != std::typeid(U2), "Incompatible units.\n");
  //  using U = std::common_type<U1, U2>;
  //  return Quantity<U>{x.val + y.val};
  //}

  //! Subtraction operation
  template<typename U>
  Quantity<U> operator-(Quantity<U> x, Quantity<U> y) // same dimension
  {
    return Quantity<U>{x.val - y.val};
  }

  //! Multiplication operation
  template<typename U1, typename U2>
  Quantity<Unit_plus<U1, U2>> operator*(Quantity<U1> x, Quantity<U2> y)
  {
    return Quantity<Unit_plus<U1, U2>>{x.val*y.val};
  }

  template<typename U>
  Quantity<U> operator*(Quantity<U> x, RealNumber y)
  {
    return Quantity<U>{x.val*y};
  }

  template<typename U>
  Quantity<U> operator*(RealNumber x, Quantity<U> y)
  {
    return Quantity<U>{x*y.val};
  }

  //! Division operation
  template<typename U1, typename U2>
  Quantity<Unit_minus<U1, U2>> operator/ (Quantity<U1> x, Quantity<U2> y)
  {
    return Quantity<Unit_minus<U1, U2>>{x.val / y.val};
  }

  template<typename U>
  Quantity<U> operator/ (Quantity<U> x, RealNumber y)
  {
    return Quantity<U>{x.val*y};
  }

  template<typename U>
  Quantity<U> operator/ (RealNumber x, Quantity<U> y)
  {
    return Quantity<U>{x*y.val};
  }
}

#endif