
namespace metacfd {

  template<typename CellComplex>
  CellComplex refine_mesh(const CellComplex& mesh, size_t max_cells) {
    CellComplex mesh_refined{ mesh };

    auto t = mesh_refined.triangulation();
    for (mesh_refined) {

    };

    return std::move(mesh_refined);
  };

}