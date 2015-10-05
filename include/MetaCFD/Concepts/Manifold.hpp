///*! \file MetaCFD/Concepts/Manifold.hpp
//\brief Concept of pseudoriemann smooth manifold */
///*
//MetaCFD library
//Copyright (C) 2015, Ilya Eriklintsev
//
//This program is free software; you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation; either version 2 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License along
//with this program; if not, write to the Free Software Foundation, Inc.,
//51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
//Contact information :
//e-mail : erik.lite@gmail.com
//*/
//#ifndef MetaCFD_Concepts_Manifold_hpp
//#define MetaCFD_Concepts_Manifold_hpp
//
//#include <MetaCFD/metacfd.hpp>
//#include <MetaCFD/Concepts/OutputProvider.hpp>
//
//namespace metacfd
//{
//  //! Type that represents a vector in vector space space
//  using Vector = CGAL::Cartesian_d<double>::Vector_d;
//
//  //! Type that represents a point in Euclidian space  
//  //using Point = CGAL::Cartesian_d<double>::Point_d;  
//
//  //! Concept of smooth manifold embeded into euclidean physical space
//  template< int _NDims, typename VertexDT = CGAL::Default, typename CellDT = CGAL::Default >
//  class Manifold {    
//  private:
//    using index_t = size_t;
//    constexpr static int ndims_{ _NDims };   //!< Number of dimensions              
//  public:          
//    //! Geometric kernel type
//    using K = CGAL::Epick_d<CGAL::Dimension_tag<_NDims>>; 
//
//    //! Nested type for data stored at each vertex    
//    struct VertexData {
//    public:
//      VertexDT data;
//      index_t index;      
//    };
//
//    //! Nested type for data stored at each vertex
//    struct CellData {
//    public:
//      CellDT data;
//      index_t index;
//    };
//
//    //Triangulation traits and other concepts   
//
//    //! Data structure storing triangualation as cell complex   
//    using TDS = CGAL::Triangulation_data_structure<
//      CGAL::Dimension_tag<_NDims>,
//      CGAL::Triangulation_vertex<K, VertexData>,
//      CGAL::Triangulation_full_cell<K, CellData>
//    >; 
//    using T = CGAL::Delaunay_triangulation<K, TDS>; //!< Triangulation object type    
//
//    //Typedefs for convinience
//    typedef typename T::Point Point;
//    typedef typename T::Vertex Vertex;
//    typedef typename T::Face Face;
//    typedef typename T::Full_cell Cell;
//  private:
//    //! Convex cover
//    std::vector<T> convex_components_;
//
//    //! Cell complex and combinatorial structure
//
//    //! Vetices
//
//    //! Cells
//    std::vector<
//
//    //! Faces
//    
//    //! Boundaries
//
//    //! Construct convex components cover of given set of points
//    std::vector<T> ComputeConvexComponents(std::vector<Point> points) {
//      // create triangulation object
//      T t;
//
//      // insert points first      
//      for (auto& point : points) {
//        TCurrent_.insert(point);  // compute triangulation      
//      };
//
//      // count 
//    };
//  public:
//
//    //! Construct manifold as convex hull of set of points
//    Manifold(std::vector<Point> points) : TCurrent_(_NDims) {
//    
//
//      // numerate vertices
//      size_t idx{ 0 };
//      for (auto it = TCurrent_.finite_vertices_begin(); it != TCurrent_.finite_vertices_end(); it++) {
//        auto& v = *it;        
//        v.data().index = idx++;
//      };
//
//      // extract boundary faces
//      //using Faces = std::vector<Face>;
//      //Faces edges;
//      //std::back_insert_iterator<Faces> out(edges);
//      //TCurrent_.tds().incident_faces(TCurrent_.infinite_vertex(), 1, out);
//
//      // collect faces of dimension 1 (edges) incident to the infinite vertex
//      //std::cout << "There are " << edges.size() << " vertices on the convex hull." << std::endl;
//    };
//
//    //! Predicate that defines computational domain
//    bool IsInside(const Point& point) { return true; };
//
//    //! Access to current triangulation
//    const T& triangulation() const { return TCurrent_; };    
//  };
//  
//
//  //! 2D Tecplot mesh output  
//  OutputProvider& operator<<(OutputProvider& os, const Manifold<2>& M)
//  {
//    //Get triangulation
//    auto t = M.triangulation();
//    auto nCells = t.number_of_finite_full_cells();
//    auto nNodes = t.number_of_vertices();
//
//    //Write header
//    os << R"(TITLE = "2D Grid")" << std::endl;
//    os << "FILETYPE = GRID" << std::endl;
//    os << R"(VARIABLES = "X" "Y")" << std::endl;
//    os << R"(ZONE T = "Coordinates", DATAPACKING = POINT, )" 
//      << "NODES = " << nNodes << ", "
//      << "ELEMENTS = " << nCells << ", "
//      << "ZONETYPE = FETRIANGLE" << std::endl;
//
//    //Iterate over nodes and output coords
//    for (auto it = t.finite_vertices_begin(); it != t.finite_vertices_end(); it++) {
//      auto& node = *it;
//      auto& x = node.point()[0];
//      auto& y = node.point()[1];
//      os << x << " " << y << std::endl;
//    };
//
//    //Loop through cells and output connectivity
//    for (auto it = t.finite_full_cells_begin(); it != t.finite_full_cells_end(); it++) {      
//      auto& cell = *it;          
//      for (auto it_vertex = cell.vertices_begin(); it_vertex != cell.vertices_end(); it_vertex++) {
//        auto& node = *it_vertex;
//        os << node->data().index+1 << " ";
//      };      
//      os << std::endl;
//    };
//
//    //Write mesh to tecplot
//    return os;
//  }
//} //namepace metacfd
//
//#endif
