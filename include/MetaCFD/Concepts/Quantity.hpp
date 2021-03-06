﻿/*! \file Concepts/Quantity.hpp
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
#ifndef MetaCFD_Concepts_Quantity_hpp_
#define MetaCFD_Concepts_Quantity_hpp_

#include <MetaCFD/metacfd.hpp>

//Include required concepts
#include <MetaCFD/Concepts/Unit.hpp>

namespace metacfd
{
  //! A Quantity is a real number value with an associated Unit
  template<typename U>
  struct Quantity {
    double val;
    explicit Quantity(double d) : val{ d } {}
  };

  //! Addition operation
  template<typename U>
  Quantity<U> operator+(Quantity<U> x, Quantity<U> y) // same dimension
  {
    return Quantity<U>{x.val + y.val};
  }

  //! Compilation time units check
  template<typename U1, typename U2>
  std::common_type<U1, U2> operator+(Quantity<U1> x, Quantity<U2> y)  // error : different dimensions 
  {
    using U = std::common_type<U1, U2>;
    return Quantity<U>{x.val + y.val};
  }

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
  Quantity<U> operator*(Quantity<U> x, double y)
  {
    return Quantity<U>{x.val*y};
  }

  template<typename U>
  Quantity<U> operator*(double x, Quantity<U> y)
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
  Quantity<U> operator/ (Quantity<U> x, double y)
  {
    return Quantity<U>{x.val*y};
  }

  template<typename U>
  Quantity<U> operator/ (double x, Quantity<U> y)
  {
    return Quantity<U>{x*y.val};
  }
}

#endif
