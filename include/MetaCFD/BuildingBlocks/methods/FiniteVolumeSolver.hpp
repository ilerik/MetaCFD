/*! \file buildingblocks\mesh\StructuredMesh.hpp
\brief Structured mesh class and implementation */
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
#ifndef METACFD_BUILDINGBLOCKS_METHODS_FINITEVOLUMESOLVER_HPP_
#define METACFD_BUILDINGBLOCKS_METHODS_FINITEVOLUMESOLVER_HPP_

#include <metacfd\metacfd.hpp>

//Include required concepts
#include <metacfd\concepts\geometry\Vector.hpp>
#include <metacfd\concepts\physics\Quantity.hpp>

//Include required headers
#include <valarray>
#include <functional>

//Template magic
template<bool B, typename T>
using Enable_if = typename std::enable_if<B, T>::type;

template<typename T> bool Is_class() {
  return std::is_class<T>::value;
};

namespace metacfd
{      
  //! Finite volume solver
  template < int NCells_, // number of uniform cells on [0.0, 1.0] //TO DO replace with mesh
    typename MediumModel, // medium model
    typename RiemannSolver, // riemann solver 
    typename TemporalIteration, // temporal iteration
    typename SpatialReconstruction
  >
  struct FiniteVolumeSolver {        
  public:
    using index_type = long;
    using ConservativeVariables = std::valarray<RealNumber>;

    //! Finite volume method cell struct
    struct FiniteVolumeCellData {
      std::slice values_slice;
      std::slice residual_slice;
    };

    //! Finite volume method face struct
    struct FiniteVolumeFaceData {      
      std::valarray<RealNumber> flux;      
    };    

    //! Constructor    
    template<typename... Types>
    FiniteVolumeSolver(Types... args);

    //! Destructor
    ~FiniteVolumeSolver() = default;

    //! Obtain solution through consecutive iterations
    auto Solve(std::function<std::valarray<RealNumber>(Vector<1> position)> initialSolution) -> void;
  private:    
    //===================================== Required entities ==============================================
    //! Computational mesh
    std::size_t n_cells{ NCells_ }; // number of cells
    std::valarray<double> x_center;
    std::valarray<double> x_left;
    std::valarray<double> x_right;

    //! Medium properties
    MediumModel medium_;    

    //! RiemannSolver
    RiemannSolver riemann_solver_;            

    //===================================== Internal data storage ==========================================
    std::valarray<RealNumber> cell_values_; // cell values stored in one valarray
    std::valarray<RealNumber> cell_residual_; // cell values stored in one valarray
    std::unordered_set<index_type> local_cells_indexes_; // indexes of local cells
    std::unordered_map<index_type, FiniteVolumeCellData > cell_data_; // cell related data
    std::unordered_map<index_type, FiniteVolumeFaceData > face_data_; // face related data 

    //! return number of local cells
    inline auto num_local_cells()->size_t { return local_cells_indexes_.size(); };

    //! Iteration info struct
    struct FiniteVolumeIteration {
      int iteration;
      double time;
      double time_step;
    } iteration_;

    //===================================== Solution algorithm details and helpers

    //! Update values according to residual and timestep
    auto UpdateValues(RealNumber time_step) -> void {
      for (auto& kv : cell_data_) {
        auto& cell = kv.second;
      };
    };

    //! Compute residual in each cell and compute time step
    auto ComputeResidual(const std::valarray<RealNumber>& cell_values_) -> std::valarray<RealNumber> {
      //Initialize data storage
      std::valarray<RealNumber> spectral_radius; // initialize temporary storage for spectral radius
      std::valarray<RealNumber> residual( 0.0, static_cast<size_t>(NCells_) ); // initialize temporary storage for residual

      //Compute convective flux for each face

      //Compute viscous flux for each face

      //Accumulate residual to cells
    };
  };

  template < int NCells_,
    typename MediumModel,
    typename RiemannSolver,
    typename TemporalIteration,
    typename SpatialReconstruction
  >
  template<>
  FiniteVolumeSolver< NCells_, MediumModel, RiemannSolver, TemporalIteration, SpatialReconstruction >::FiniteVolumeSolver(
    MediumModel medium,
    RiemannSolver riemann_solver
    ) : medium_{ medium }, riemann_solver_{ riemann_solver }
  { };

  template < int NCells_,
    typename MediumModel,
    typename RiemannSolver,
    typename TemporalIteration,
    typename SpatialReconstruction
  >
    auto FiniteVolumeSolver< NCells_, MediumModel, RiemannSolver, TemporalIteration, SpatialReconstruction >::
    Solve(std::function<std::valarray<RealNumber>(Vector<1> position)> initialSolution) -> void {
    //Fill initial conditions and initialize data structures
    for (auto& cell : cell_data_) {

    };

    //Run solution algorithm main cycle
  };

  //! Implementation details of FiniteVolumeSolver
  namespace FiniteVolumeSolver_impl {
    using namespace metacfd;    


   
  } // namespace FiniteVolumeSolver_impl

} // namespace metacfd

#endif