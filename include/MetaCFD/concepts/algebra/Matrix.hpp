/*! \file cocepts/algebra/RealNumber.hpp
\brief Concept of matrix composed of arbitrary elements */
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
#ifndef METACFD_CONCEPTS_ALGEBRA_MATRIX_HPP_
#define METACFD_CONCEPTS_ALGEBRA_MATRIX_HPP_

#include <metacfd\metacfd.hpp>

namespace metacfd
{
  template<typename T, size_t N>
  class Matrix {
  public:
    static constexpr size_t order = N;
    using value_type = T;
    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_iterator;

    Matrix() = default;
    Matrix(Matrix&&) = default; // move
    Matrix& operator=(Matrix&&) = default;
    Matrix(Matrix const&) = default; // copy
    Matrix& operator=(Matrix const&) = default;
    ~Matrix() = default;

    template<typename U>
    Matrix(const Matrix_ref<U, N>&); // construct from Matrix_ref
    template<typename U>
    Matrix& operator=(const Matrix_ref<U, N>&); // assign from Matrix_ref

    template<typename...Exts> //specify the extents
    explicit Matrix(Exts... exts);
    Matrix(Matrix_initializer<T, N>); //initialize from list
    Matrix& operator=(Matrix_initializer<T, N>); // assign from list
    template<typename U>
    Matrix(initializer_list<U>) = delete; //don’t use {} except for elements
    template<typename U>
    Matrix& operator=(initializer_list<U>) = delete;
    static constexpr size_t order() { return N; } // number of dimensions
    size_t extent(size_t n) const { return desc.extents[n]; } // #elements in the nth dimension
    size_t size() const { return elems.size(); } // total number of elements
    const Matrix_slice<N>& descriptor() const { return desc; } // the slice defining subscripting
    T* data() { return elems.data(); } // ‘‘flat’’ element access
    const T* data() const { return elems.data(); }
    // ...
  private:
    Matrix_slice<N> desc; // slice defining extents in the N dimensions
    std::vector<T> elems; // the elements
  };

  template<typename T, size_t N>
  template<typename... Exts>
  Matrix<T, N>::Matrix(Exts... exts)
    :desc{ exts... }, // copy extents
    elems(desc.size) // allocate desc.size elements and default initialize them
  { };

  template<typename T, size_t N>
  Matrix<T, N>::Matrix(Matrix_initializer<T, N> init)
  {
    Matrix_impl::derive_extents(init, desc.extents); // deduce extents from initializer list (§29.4.4)
    elems.reserve(desc.size); // make room for slices
    Matrix_impl::insert_flat(init, elems); // initialize from initializer list (§29.4.4)
    assert(elems.size() == desc.size);
  }

}; // namespace metacfd

#endif