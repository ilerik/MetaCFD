#include <iostream>
#include <vector>

#include <MetaCFD/Concepts/Manifold.hpp>
#include <MetaCFD/Concepts/OutputProvider.hpp>

#include <MetaCFD/BuildingBlocks/CFDSolvers/MOOD_Solver.hpp>

using namespace metacfd;
using namespace std;

int main() {
  try {
    //Specify geometry points and predicate
    double eps = 0.1;
    double alpha = 0.1;
    double h = 0.1;
    double lambda = 0.1;
    double size = 3*h;
    double dL = std::min(h / std::tan(alpha), (-eps + lambda) / 4.0);

    std::vector<Manifold<2>::Point> points{ };

    //Origin and corners
    points.push_back(Manifold<2>::Point{ 0.0, 0.0 });
    points.push_back(Manifold<2>::Point{ (eps + lambda) / 2.0, size });
    points.push_back(Manifold<2>::Point{ (eps + lambda) / 2.0, -size });
    points.push_back(Manifold<2>::Point{ -(eps + lambda) / 2.0, size });
    points.push_back(Manifold<2>::Point{ -(eps + lambda) / 2.0, -size });

    //Front
    points.push_back(Manifold<2>::Point{ +(eps + lambda) / 2.0, h });
    points.push_back(Manifold<2>::Point{ 0.0, h });
    points.push_back(Manifold<2>::Point{ -(eps + lambda) / 2.0, h });

    //Right side  
    points.push_back(Manifold<2>::Point{ 0.0 + eps / 2.0, 0.0 });
    points.push_back(Manifold<2>::Point{ 0.0 + eps / 2.0 + dL, 0.0 + h });
    points.push_back(Manifold<2>::Point{ (eps + lambda) / 2.0, 0.0 });
    points.push_back(Manifold<2>::Point{ (eps + lambda) / 2.0 - eps / 2.0, 0.0 });
    points.push_back(Manifold<2>::Point{ (eps + lambda) / 2.0 - eps / 2.0 - dL, 0.0 + h });

    //Left side
    points.push_back(Manifold<2>::Point{ 0.0 - eps / 2.0, 0.0 });
    points.push_back(Manifold<2>::Point{ 0.0 - eps / 2.0 - dL, 0.0 - h });
    points.push_back(Manifold<2>::Point{ -(eps + lambda) / 2.0, 0.0 });
    points.push_back(Manifold<2>::Point{ -(eps + lambda) / 2.0 + eps / 2.0, 0.0 });
    points.push_back(Manifold<2>::Point{ -(eps + lambda) / 2.0 + eps / 2.0 + dL, 0.0 - h });
    
    //Construct manifold with mesh
    Manifold<2> Omega(points);

    { //Output initial mesh
      OutputProvider op("initial_mesh.dat");
      op << Omega;
    };

    { //Output refined mesh
      OutputProvider op("refined_mesh.dat");
      op << Omega;
    };


   MOOD_CFDSolver<100,
      IdealGas<1>,
      HLLCRiemannSolver,
      bool,
      bool
    > solver{     
      IdealGas<1>{ 1.4, 1.0 },
      HLLCRiemannSolver {}
    };

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
