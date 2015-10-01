/*! \file MetaCFD/Concepts/CellComplex.hpp
\brief Concept of cell complex */
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
#ifndef MetaCFD_Concepts_CellComplex_hpp
#define MetaCFD_Concepts_CellComplex_hpp

#include <MetaCFD/metacfd.hpp>
#include <MetaCFD/Concepts/OutputProvider.hpp>

namespace metacfd {
  //! Cell
  class Cell {

  };

  //! Face
  class Face {

  };

  //! Vertex
  class Face {

  };

  //! Cell complex traits
  template<>
  struct CellComplexTraits {
    typedef Cell Cell;
  };

  //! Cell complex concept class
  template<typename CellComplexTraits>
  class CellComplex {
  public:
    //Related types
    using index_t = size_t; //!< Index type
    using Face = CellComplexTraits::Cell;
  private:
    //Internal representation
    std::unordered_map<index_t, Vertex> vertices_;
    std::unordered_map<index_t> cells_;
    std::unordered_map<index_t> faces_;
  public:
    //! Constructor
    CellComplex() {};
  };

}

#endif