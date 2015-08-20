/*! \file BuildingBlocks\CFDSolvers\MOOD_Solver.hpp
\brief MOOD loop based CFD solver */

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
#ifndef MetaCFD_BuildingBlocks_Mediums_IdealGas_hpp
#define MetaCFD_BuildingBlocks_Mediums_IdealGas_hpp

#include <metacfd\metacfd.hpp>

//Include required concepts
#include <Metacfd\Concepts\Vector.hpp>
#include <Metacfd\Concepts\Quantity.hpp>

//Include required headers
#include <valarray>

namespace metacfd
{
  template< int NDims_ >
  class IdealGas {
    //Ideal gas parameters
    static constexpr int ndims{ NDims_ };
    static constexpr int num_variables{ ndims + 2 };
    double gamma_{ 1.4 };
    double Cv_{ 1.0 };
    double Cp_{ gamma_ * Cv_ };
  public:
    //Constructor
    template< int NDims_ >
    constexpr IdealGas(double Gamma, double Cv) :
      gamma_{ Gamma },
      Cv_{ Cv },
      Cp_{ Gamma * Cv }
    {};

    IdealGas(double Gamma, double Cv) :
      gamma_{ Gamma },
      Cv_{ Cv },
      Cp_{ Gamma * Cv }
    {};

    //! EquationOfState 
    constexpr double GetPressure(double density, double internal_energy) { return (gamma_ - 1.0) * density * internal_energy; };

    //! Get velocity
    template < typename = typename std::enable_if<  ndims == 1, Vector<ndims> >::type >
    Vector<ndims> GetVelocity(const std::valarray<RealNumber> values) { return values[1] / values[0]; };
  };

  //! Predefined medium models
  namespace mediums {
    //! Air
    template<int _NDims>
    class Air : public metacfd::IdealGas<_NDims>(1, 1) {
      //Constructor
      Air() : IdealGas(1, 1) {};
    };
  }; //namespace mediums

} //namespace metacfd

#endif