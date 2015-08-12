/*! \file cocepts/physical/Unit.hpp
\brief Concept of physical (dimesioned) unit and related operations */
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
#ifndef METACFD_CONCEPTS_PHYSICS_UNIT_HPP_
#define METACFD_CONCEPTS_PHYSICS_UNIT_HPP_

#include <metacfd\metacfd.hpp>

namespace metacfd
{
  //Physical unit of measurement in SI
  template<int M_, int Kg_, int S_, int A_>
  struct Unit {
    enum { m = M_, kg = Kg_, s = S_, A = A_ };
  };

  //Template type function for units addition (e.g. after multiplication)
  template<typename U1, typename U2>
  struct Uplus {
    using type = Unit<U1::m + U2::m, U1::kg + U2::kg, U1::s + U2::s, U1::A + U2::A>;
  };

  template<typename U1, typename U2>
  using Unit_plus = typename Uplus<U1, U2>::type;

  //Template type function for units subtraction (e.g. after division) 
  template<typename U1, typename U2>
  struct Uminus {
    using type = Unit<U1::m - U2::m, U1::kg - U2::kg, U1::s - U2::s, U1::A - U2::A>;
  };

  template<typename U1, typename U2>
  using Unit_minus = typename Uminus<U1, U2>::type;

  //Aliases for physical quatity types
  namespace units {
    //Base units
    using LengthUnit = Unit<1, 0, 0, 0>;    //length
    using MassUnit = Unit<0, 1, 0, 0>;      //mass
    using TimeUnit = Unit<0, 0, 1, 0>;      //time
    using ElectricalCurrentUnit = Unit<0, 0, 0, 1>;   //electrical current

    //Derived units
    using VelocityUnit = Unit<1, 0, -1, 0>; //velocity
  };
};

#endif