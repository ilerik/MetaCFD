# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/erik/Science/GitHub/MetaCFD

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/erik/Science/GitHub/MetaCFD

# Include any dependencies generated for this target.
include CMakeFiles/TurboStructured.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TurboStructured.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TurboStructured.dir/flags.make

CMakeFiles/TurboStructured.dir/vs2015/sandbox/main.cpp.o: CMakeFiles/TurboStructured.dir/flags.make
CMakeFiles/TurboStructured.dir/vs2015/sandbox/main.cpp.o: vs2015/sandbox/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erik/Science/GitHub/MetaCFD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TurboStructured.dir/vs2015/sandbox/main.cpp.o"
	g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TurboStructured.dir/vs2015/sandbox/main.cpp.o -c /home/erik/Science/GitHub/MetaCFD/vs2015/sandbox/main.cpp

CMakeFiles/TurboStructured.dir/vs2015/sandbox/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TurboStructured.dir/vs2015/sandbox/main.cpp.i"
	g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/erik/Science/GitHub/MetaCFD/vs2015/sandbox/main.cpp > CMakeFiles/TurboStructured.dir/vs2015/sandbox/main.cpp.i

CMakeFiles/TurboStructured.dir/vs2015/sandbox/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TurboStructured.dir/vs2015/sandbox/main.cpp.s"
	g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/erik/Science/GitHub/MetaCFD/vs2015/sandbox/main.cpp -o CMakeFiles/TurboStructured.dir/vs2015/sandbox/main.cpp.s

CMakeFiles/TurboStructured.dir/vs2015/sandbox/main.cpp.o.requires:

.PHONY : CMakeFiles/TurboStructured.dir/vs2015/sandbox/main.cpp.o.requires

CMakeFiles/TurboStructured.dir/vs2015/sandbox/main.cpp.o.provides: CMakeFiles/TurboStructured.dir/vs2015/sandbox/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/TurboStructured.dir/build.make CMakeFiles/TurboStructured.dir/vs2015/sandbox/main.cpp.o.provides.build
.PHONY : CMakeFiles/TurboStructured.dir/vs2015/sandbox/main.cpp.o.provides

CMakeFiles/TurboStructured.dir/vs2015/sandbox/main.cpp.o.provides.build: CMakeFiles/TurboStructured.dir/vs2015/sandbox/main.cpp.o


# Object files for target TurboStructured
TurboStructured_OBJECTS = \
"CMakeFiles/TurboStructured.dir/vs2015/sandbox/main.cpp.o"

# External object files for target TurboStructured
TurboStructured_EXTERNAL_OBJECTS =

TurboStructured: CMakeFiles/TurboStructured.dir/vs2015/sandbox/main.cpp.o
TurboStructured: CMakeFiles/TurboStructured.dir/build.make
TurboStructured: /usr/lib/x86_64-linux-gnu/libmpfr.so
TurboStructured: /usr/lib/x86_64-linux-gnu/libgmp.so
TurboStructured: /usr/lib/libCGAL.so
TurboStructured: /usr/lib/x86_64-linux-gnu/libboost_thread.so
TurboStructured: /usr/lib/x86_64-linux-gnu/libboost_system.so
TurboStructured: /usr/lib/x86_64-linux-gnu/libpthread.so
TurboStructured: CMakeFiles/TurboStructured.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/erik/Science/GitHub/MetaCFD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TurboStructured"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TurboStructured.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TurboStructured.dir/build: TurboStructured

.PHONY : CMakeFiles/TurboStructured.dir/build

CMakeFiles/TurboStructured.dir/requires: CMakeFiles/TurboStructured.dir/vs2015/sandbox/main.cpp.o.requires

.PHONY : CMakeFiles/TurboStructured.dir/requires

CMakeFiles/TurboStructured.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TurboStructured.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TurboStructured.dir/clean

CMakeFiles/TurboStructured.dir/depend:
	cd /home/erik/Science/GitHub/MetaCFD && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/erik/Science/GitHub/MetaCFD /home/erik/Science/GitHub/MetaCFD /home/erik/Science/GitHub/MetaCFD /home/erik/Science/GitHub/MetaCFD /home/erik/Science/GitHub/MetaCFD/CMakeFiles/TurboStructured.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TurboStructured.dir/depend

