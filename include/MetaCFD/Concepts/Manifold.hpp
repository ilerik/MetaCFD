/*! \file MetaCFD/Concepts/Manifold.hpp
\brief Concept of pseudoriemann smooth manifold */
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
#ifndef MetaCFD_Concepts_Manifold_hpp
#define MetaCFD_Concepts_Manifold_hpp

#include <MetaCFD/metacfd.hpp>
#include <MetaCFD/Concepts/Vector.hpp>

#include <CGAL/Epick_d.h>
#include <CGAL/Triangulation.h>
#include <CGAL/algorithm.h>

namespace metacfd
{
  //! Concept of smooth manifold embeded into euclidean physical space
  template< int _NDims >
  class Manifold {    
    using K = CGAL::Epick_d<CGAL::Dynamic_dimension_tag>;
    using Triangulation = CGAL::Triangulation<K>;
    using Face = Triangulation::Face;
    using Node = Triangulation::Point;//!< Type that represents a point in Euclidian space
  private:
    constexpr static int ndims_ { _NDims };  //!< Number of dimensions
    Triangulation TCurrent_;          //!< Current triangulation
  public:    
    Manifold(const std::vector< Node >& points) : TCurrent_(_NDims) {
      // insert points
      CGAL_assertion(TCurrent_.empty());
      TCurrent_.insert(points.begin(), points.end());  // compute triangulation
      CGAL_assertion(TCurrent_.is_valid());

      // extract boundary faces
      using Faces = std::vector<Face>;
      Faces edges;
      std::back_insert_iterator<Faces> out(edges);
      TCurrent_.tds().incident_faces(TCurrent_.infinite_vertex(), 1, out);
      // collect faces of dimension 1 (edges) incident to the infinite vertex
      std::cout << "There are " << edges.size()
        << " vertices on the convex hull." << std::endl;
    };

    bool IsInside(const Vector<_NDims>& point) { return true; };
  };
} //namepace metacfd

#endif
