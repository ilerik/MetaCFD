/*! \file cocepts/algebra/RealNumber.hpp
\brief Concept of real number */
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
#ifndef METACFD_CONCEPTS_ALGEBRA_DIRECTEDGRAPH_HPP_
#define METACFD_CONCEPTS_ALGEBRA_DIRECTEDGRAPH_HPP_

#include <metacfd\metacfd.hpp>

namespace metacfd
{
  template< class VertexType , class EdgeType > 
  class DirectedGraph {
  public:
    void add_vertex(const VertexType& vertex); //add vertex by copying it
    void add_vertex(VertexType&& vertex); // add vertex by moving
    void add_edge(const Vertex& v1, const Vertex& v2, const EdgeType& edge); //add edge by copying it
    void add_edge(const Vertex& v1, const Vertex& v2, EdgeType&& edge); //add edge by moving it
    std::vector<EdgeType&> get_edges(const Vertex& vertex); //get edges
    std::vector<VertexType&> operator[](const Vertex& vertex); //get neighbours
  private:
    //Vertex wrapper
    template< class VertexType, class EdgeType >
    struct VertexWrapper {
      std::unique_ptr<VertexType> data;
      std::list<EdgeType&> edges;
    };

    //Edge wrapper
    template< class VertexType, class EdgeType >
    struct EdgeWrapper {
      std::unique_ptr<EdgeType> data;
      std::pair<VertexType&, VertexType&> vertices;
    };

    //Internal data
    std::unordered_set< VertexWrapper > vertices_{};
    std::unordered_set< EdgeWrapper > edges_{};
  };

  namespace DirectedGraph_impl {

  } // namespace DirectedGraph_impl

} //namespace metacfd

#endif