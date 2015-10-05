#include <iostream>
#include <fstream>
#include <vector>

#include <MetaCFD/metacfd.hpp>

//Geometric kernel
#include <CGAL/Epick_d.h>

//Exact geometric objects from CGAL kernel
//#include <CGAL/Kernel_d/Sphere_d.h>
//#include <CGAL/Kernel_d/Iso_box_d.h>

//#include <MetaCFD/Concepts/Manifold.hpp>
//#include <MetaCFD/Concepts/OutputProvider.hpp>

#include <MetaCFD/Concepts/Default.hpp>
#include <MetaCFD/Concepts/CellComplex.hpp>

using namespace metacfd;
using namespace std;

class CSGStructure {
public:  
};

int main() {
  try {
    //Geometry kernel and associated entities types
    using GeometryKernel = CGAL::Epick_d<CGAL::Dimension_tag<2>>; //! Geometry kernel traits    
    using Point = GeometryKernel::Point_d;
    using Vector = GeometryKernel::Vector_d;

    //Availible CSG primitives
    //using Sphere = GeometryKernel::Sphere_d;
    //using Iso_box = GeometryKernel::Iso_box_d;

    //CGAL::Wrap::Point_d<GeometryKernel>

    //Define geometry   
    using CCTraits = CellComplexTraits<2>;  //Specify traits for 2D calclulation
    //GeometryKernel::Point_d p1{ 0.0, 0.0 };
    //GeometryKernel::Point_d p2{ 1.0, 1.0 };
    //GeometryKernel::Point_d p3{ 1.0, 2.0 };
    //auto iso_box = GeometryKernel::Iso_box_d::Iso_box(p1, p2);
    //std::cout << iso_box.max;    

    //Create initial mesh   
    CCTraits::Point_d p1{ 0.0, 0.0 };
    CCTraits::Point_d p2{ 1.0, 1.0 };
    CCTraits::Iso_box_d box{ p1, p2 };

    CellComplex<CCTraits> mesh(box);             // Instantiate mesh
  /*  CellComplex<CCTraits>::Delaunay_triangulation t(2);
    CellComplex<CCTraits>::Delaunay_triangulation::Finite_facet_iterator it;
    t.tds().face;*/
  
    
    
    //Output initial mesh
    {
      std::ofstream op("init.dat");
      op << mesh;
    }

    //Move borders
  }
  catch (std::exception e) {
    std::cout << e.what() << std::endl;
  }
  catch (...) {
    std::cout << "Fatal error." << std::endl;
    std::terminate();
  }
  return 0;
  
};
