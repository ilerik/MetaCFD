#include <iostream>

#include <MetaCFD/Concepts/Quantity.hpp>
#include <MetaCFD/Concepts/Vector.hpp>
#include <MetaCFD/Concepts/Manifold.hpp>

using namespace metacfd;
using namespace std;

int main() {
  try {
    Quantity < units::MassUnit > m1{ 10 };
    Quantity < units::MassUnit > m2{ 20 };
    Quantity < units::MassUnit > m = m1 - m2;
    std::cout << m.val;

    Vector<2> A{ 0.0, 0.0 };
    Vector<2> B{ 1.0, 0.0 };
    Vector<2> C{ 1.0, 1.0 };
    Vector<2> D{ 0.0, 1.0 };

    using K = CGAL::Epick_d<CGAL::Dynamic_dimension_tag>;
    using Triangulation = CGAL::Triangulation<K>;
    vector<Triangulation::Point> points{};

    Manifold<2> Omega(points);

   /* MOOD_CFDSolver<100,
      IdealGas<1>,
      HLLCRiemannSolver,
      bool,
      bool
    > solver{     
      IdealGas<1>{ 1.4, 1.0 },
      HLLCRiemannSolver {}
    };*/

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
