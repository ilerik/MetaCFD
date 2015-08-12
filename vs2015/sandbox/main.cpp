#include <iostream>

#include <metacfd\metacfd.hpp>
#include <metacfd\concepts\algebra\RationalNumber.hpp>
#include <metacfd\concepts\physics\Quantity.hpp>
#include <metacfd\buildingblocks\mediums\IdealGas.hpp>
#include <metacfd\buildingblocks\riemannsolvers\HLLCRiemannSolver.hpp>
#include <metacfd\buildingblocks\methods\FiniteVolumeSolver.hpp>

using namespace metacfd;
using namespace std;

int main() {
  Quantity < units::MassUnit > m1{ 10 };
  Quantity < units::MassUnit > m2{ 20 };
  Quantity < units::MassUnit > m = m1 - m2;
  std::cout << m.val;  

  EulerianStructuredSolver<100,
    IdealGas<1>,
    HLLCRiemannSolver,
    bool,
    bool
  > solver{     
    IdealGas<1>{ 1.4, 1.0 },
    HLLCRiemannSolver {}
  };

  //Matrix<RealNumber, 2> A();  
  return 0; 
};