/*! \file cocepts/algebra/RealNumber.hpp
\brief Concept of Euclidian vector space element Vector */
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
#ifndef METACFD_CONCEPTS_GEOMETRY_VECTOR_HPP_
#define METACFD_CONCEPTS_GEOMETRY_VECTOR_HPP_

#include <metacfd\metacfd.hpp>
#include <metacfd\concepts\algebra\RealNumber.hpp>

namespace metacfd
{
  //template < class VectorSpace_, // vector space
  //>
  template< int _NDims >
  struct Vector {    
    static constexpr int n_dims_ = _NDims;    
    //std::valarray<double> coords_(0.0, _NDims);
  public:
    
  };
}

#endif