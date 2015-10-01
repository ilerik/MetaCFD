/*! \file MetaCFD/Concepts/Manifold.hpp
\brief Concept of pseudoriemann smooth manifold */
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
#ifndef MetaCFD_Concepts_OutputProvider_hpp
#define MetaCFD_Concepts_OutputProvider_hpp

#include <MetaCFD/metacfd.hpp>
#include <MetaCFD/Concepts/Manifold.hpp>

namespace metacfd
{  

  using OutputProvider = std::ofstream;

  //class OutputProvider {
  //  std::ofstream ofs_; //!< Output file stream
  //public:
  //  //Alloc file stream on construction
  //  OutputProvider(std::string fname) : ofs_(fname) { };
  //  
  //  //The non-member function operator<< will have access to OutputProvider's private members
  //  template< typename T >
  //  friend OutputProvider& operator<<(const OutputProvider& os, const T& x);
  //};

  //template< typename T >
  //OutputProvider& operator<<(const OutputProvider& os, const T& x)
  //{
  //  os.ofs_ << x;
  //}
  
  //Basic types support
  //operator<<(OutputProvider& os, const int& x) { return os << x; };
  //const OutputProvider& operator<<(const double& x) { ofs_ << x; };
  //const OutputProvider& operator<<(const std::string& str) { ofs_ << str; };
 
}

#endif