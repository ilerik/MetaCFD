# MetaCFD sandbox project
project(metacfd_sandbox CXX)

# check CMake version
cmake_minimum_required(VERSION 2.6.2)
if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" VERSION_GREATER 2.6)
  if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION}" VERSION_GREATER 2.8.3)
    cmake_policy(VERSION 2.8.4)
  else()
    cmake_policy(VERSION 2.6)
  endif()
endif()

set( CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS true )

if ( COMMAND cmake_policy )
  cmake_policy( SET CMP0003 NEW )
endif()

# set(CMAKE_CXX_COMPILER "mpicxx")
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS                "-std=c++11 -w")
set(CMAKE_CXX_FLAGS_DEBUG          "-g")
set(CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE        "-O4 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

#parse src/ directory for headers and source files 
#file(GLOB_RECURSE src_SOURCES "src/*.cpp")
#file(GLOB_RECURSE src_HEADERS "src/*.h")

#set (src_INCLUDE_DIRS "")
#foreach (_headerFile ${src_HEADERS})
#    get_filename_component(_dir ${_headerFile} PATH)
#    list (APPEND src_INCLUDE_DIRS ${_dir})
#endforeach()
#list(REMOVE_DUPLICATES src_INCLUDE_DIRS)
#include_directories(${src_INCLUDE_DIRS})

## external dependencies
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# CGAL and its components
find_package( CGAL QUIET COMPONENTS  )
if ( NOT CGAL_FOUND )
  message(STATUS "This project requires the CGAL library, and will not be compiled.")
  return()  
endif()

# include helper file
include( ${CGAL_USE_FILE} )

# Boost and its components
find_package( Boost REQUIRED )
if ( NOT Boost_FOUND )
  message(STATUS "This project requires the Boost library, and will not be compiled.")
  return()
endif()

# Eigen3 header only library
find_package(Eigen3 3.1.0) #(requires 3.1.0 or greater)
if (EIGEN3_FOUND)
   include( ${EIGEN3_USE_FILE} )
else()
  message(STATUS "This project requires the Eigen3 library, and will not be compiled.")
  return()
endif() 
include_directories("${EIGEN3_INCLUDE_DIR}")

# local project include directories
include_directories ("${PROJECT_SOURCE_DIR}/include")
include_directories ("${PROJECT_SOURCE_DIR}/libs")

# Creating entries for target: testproj
# ############################

add_executable(metacfd_sandbox "vs2015/sandbox/main.cpp")

add_to_cached_list( CGAL_EXECUTABLE_TARGETS metacfd_sandbox )

# Link the executable to CGAL and third-party libraries
target_link_libraries(metacfd_sandbox  ${CGAL_LIBRARIES} ${CGAL_3RD_PARTY_LIBRARIES} )

# Other libraries to link
# target_link_libraries(TurboStructured)




