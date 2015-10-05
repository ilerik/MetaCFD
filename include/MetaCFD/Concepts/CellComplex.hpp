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

#include <CGAL/Kernel_d/Iso_box_d.h>
#include <CGAL/Kernel_d/Point_d.h>
#include <CGAL/Epick_d.h>

namespace metacfd {

  namespace metacfd_internal {
    //! Cell
    template< int Dims_, typename GeometryKernel = CGAL::Epick_d<CGAL::Dimension_tag<Dims_> > >
    class Cell {

    };

    //! Face
    template< int Dims_, typename GeometryKernel = CGAL::Epick_d<CGAL::Dimension_tag<Dims_> > >
    class Face {

    };

    //! Vertex
    template< int Dims_, typename GeometryKernel_ = CGAL::Epick_d<CGAL::Dimension_tag<Dims_> > >
    class Vertex : public GeometryKernel_::Point_d {

    };
  };

  //! Cell complex traits 
  template< int Dims_, typename GeometryKernel_ = CGAL::Epick_d<CGAL::Dimension_tag<Dims_> > >
  struct CellComplexTraits {    
  public:
    constexpr static int dims_{ Dims_ };
  public:
    typedef typename GeometryKernel_ GeometryKernel;
    typedef typename GeometryKernel::Point Point;
    typedef typename GeometryKernel::Point_d Point_d;
    typedef typename metacfd_internal::Cell<Dims_> Cell;
    typedef typename metacfd_internal::Face<Dims_> Face;
    typedef typename metacfd_internal::Vertex<Dims_> Vertex;

    //TO DO Move to CSGTraits    
    //typedef CGAL::Iso_box_d<GeometryKernel> Iso_box_d;
    typedef typename GeometryKernel::Iso_box_d Iso_box_d;
  };

  //! Cell complex concept class
  template<typename CellComplexTraits_ = Default, typename CSGTraits_ = Default>
  class CellComplex {
  private:
    //Parameters
    constexpr static int dims_{ CellComplexTraits_::dims_ };
  public:
    typedef typename CellComplex<CellComplexTraits_, CSGTraits_> Self_;
  public:
    //Associated types
    using index_t = size_t; //!< Index type    
    typedef typename CellComplexTraits_::GeometryKernel GeometryKernel;
    typedef typename CellComplexTraits_::Cell Cell;
    typedef typename CellComplexTraits_::Face Face;
    typedef typename CellComplexTraits_::Vertex Vertex;
    typedef typename CellComplexTraits_::Point Point;
    typedef typename CellComplexTraits_::Point_d Point_d;

    //CSG Primiteves
    typedef typename CellComplexTraits_::Iso_box_d Iso_box_d;

  private:
    //! Triangulation data structure with indexes
    using TDS = CGAL::Triangulation_data_structure<
      CGAL::Dimension_tag< dims_ >,
      CGAL::Triangulation_vertex<GeometryKernel, index_t>,
      CGAL::Triangulation_full_cell<GeometryKernel, index_t>
    >;
  public:
    //!Triangulation type
    typedef typename CGAL::Delaunay_triangulation<GeometryKernel, TDS> Delaunay_triangulation;

  private:
    //Internal representation
    std::unordered_map<index_t, Vertex> vertices_{ };
    std::unordered_map<index_t, Cell> cells_{ };
    std::unordered_map<index_t, Face> faces_{ };

  private:
    //! Delaunay triangulation
    Delaunay_triangulation current_triangulation_{ dims_ };    

    //! Helper function that initializes cell complex as Delaunay triangulation of given set of points
    void init_convex_from_points(const std::vector<Point_d>& points) {
      //Create triangulation object and insert points      
      current_triangulation_.clear();
      current_triangulation_.insert(std::begin(points), std::end(points));
            
      //Numerate vertices
      index_t idx{ 0 };
      for (auto it = current_triangulation_.finite_vertices_begin(); it != current_triangulation_.finite_vertices_end(); it++) {
        auto& v = *it;        
        v.data() = idx++;
      };

      //Numerate cells
      idx = 0;
      for (auto it = current_triangulation_.finite_full_cells_begin(); it != current_triangulation_.finite_full_cells_end(); it++) {
        auto& v = *it;
        v.data() = idx++;
      };

      //Store triangulation to internal datastructure            
    };

  public:
    //! Constructor    
    CellComplex(const Iso_box_d& box) {
      //Insert starting points      
      std::vector<double> max_coords{ };
      std::vector<double> min_coords{ };
      for (int i = 0; i < dims_; i++) {
        max_coords.push_back(box.max()[i]);
        min_coords.push_back(box.min()[i]);
      };

      //Recursively generate corner points
      std::vector<double> current_coords( static_cast<size_t>(dims_) );
      std::vector<Point_d> points{ };
      std::function<void(int)> generate_corner_points = [&](int i) {
        if (i == dims_) {
          points.push_back( Point_d(dims_, std::begin(current_coords), std::end(current_coords)) );
          return;
        };
        current_coords[i] = max_coords[i];
        generate_corner_points(i + 1);
        current_coords[i] = min_coords[i];
        generate_corner_points(i + 1);
        return;
      };      
      generate_corner_points(0);

      //Insert centroid
      for (int i = 0; i < dims_; i++) current_coords[i] = (max_coords[i] + min_coords[i]) / 2;
      points.push_back(Point_d(dims_, std::begin(current_coords), std::end(current_coords)));

      //Output points !Debug
      for (auto& point : points) std::cout << point << std::endl;
     
      //Init mesh from points
      init_convex_from_points(points);      
    };  

  public:
    //! Access to current triangulation
    const Delaunay_triangulation& triangulation() const { return current_triangulation_; };

    ////! Triangulation refinement procedure
    //void refine_triangulation(int max_cells_number = 100) {

    //  //Iterative refinement procedure
    //  while (current_triangulation_.number_of_finite_full_cells() <= max_cells_number) {
    //    //Sort faces array according to theirs measure value
    //    for (auto it = current_triangulation_.finite_facets_begin(); it != current_triangulation_.finite_facets_end(); ++it) {      
    //      it->
    //      current_triangulation_.insert_in_full_cell();
    //    };
    //  };

    //  return;
    //};

  }; // class CellComplex

  //! 2D Tecplot mesh output    
  template< typename traits >
  std::ostream& operator<<(std::ostream& os, const CellComplex<traits>& M)
  {
    //Get triangulation
    auto t = M.triangulation();
    auto nCells = t.number_of_finite_full_cells();
    auto nNodes = t.number_of_vertices();
  
    //Write header
    os << R"(TITLE = "2D Grid")" << std::endl;
    os << "FILETYPE = GRID" << std::endl;
    os << R"(VARIABLES = "X" "Y")" << std::endl;
    os << R"(ZONE T = "Coordinates", DATAPACKING = POINT, )" 
      << "NODES = " << nNodes << ", "
      << "ELEMENTS = " << nCells << ", "
      << "ZONETYPE = FETRIANGLE" << std::endl;
  
    //Iterate over nodes and output coords
    for (auto it = t.finite_vertices_begin(); it != t.finite_vertices_end(); it++) {
      auto& node = *it;
      auto& x = node.point()[0];
      auto& y = node.point()[1];
      os << x << " " << y << std::endl;
    };
  
    //Loop through cells and output connectivity
    for (auto it = t.finite_full_cells_begin(); it != t.finite_full_cells_end(); it++) {      
      auto& cell = *it;          
      for (auto it_vertex = cell.vertices_begin(); it_vertex != cell.vertices_end(); it_vertex++) {
        auto& node = *it_vertex;
        os << node->data()+1 << " ";
      };      
      os << std::endl;
    };
  
    //Write mesh to tecplot
    return os;
  }

}

#endif