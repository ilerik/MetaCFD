/*! \file cocepts/algebra/RealNumber.hpp
\brief Concept of Euclidian vector space */
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
#ifndef METACFD_CONCEPTS_GEOMETRY_EUCLIDIANSPACE_HPP_
#define METACFD_CONCEPTS_GEOMETRY_EUCLIDIANSPACE_HPP_

#include <metacfd\metacfd.hpp>
#include <metacfd\concepts\algebra\RealNumber.hpp>

namespace metacfd
{
  template < size_t Dims_,  // number of dimensions
  >
  class EuclidianSpace {
  public:
    static const size_t dims = Dims_; 
  };
}

#endif