# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ratatouille/2d_platformer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ratatouille/2d_platformer/out/build

# Include any dependencies generated for this target.
include CMakeFiles/2DPLATFORMER.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/2DPLATFORMER.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/2DPLATFORMER.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2DPLATFORMER.dir/flags.make

CMakeFiles/2DPLATFORMER.dir/main.cpp.o: CMakeFiles/2DPLATFORMER.dir/flags.make
CMakeFiles/2DPLATFORMER.dir/main.cpp.o: ../../main.cpp
CMakeFiles/2DPLATFORMER.dir/main.cpp.o: CMakeFiles/2DPLATFORMER.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ratatouille/2d_platformer/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2DPLATFORMER.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/2DPLATFORMER.dir/main.cpp.o -MF CMakeFiles/2DPLATFORMER.dir/main.cpp.o.d -o CMakeFiles/2DPLATFORMER.dir/main.cpp.o -c /home/ratatouille/2d_platformer/main.cpp

CMakeFiles/2DPLATFORMER.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2DPLATFORMER.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ratatouille/2d_platformer/main.cpp > CMakeFiles/2DPLATFORMER.dir/main.cpp.i

CMakeFiles/2DPLATFORMER.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2DPLATFORMER.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ratatouille/2d_platformer/main.cpp -o CMakeFiles/2DPLATFORMER.dir/main.cpp.s

# Object files for target 2DPLATFORMER
2DPLATFORMER_OBJECTS = \
"CMakeFiles/2DPLATFORMER.dir/main.cpp.o"

# External object files for target 2DPLATFORMER
2DPLATFORMER_EXTERNAL_OBJECTS =

2DPLATFORMER: CMakeFiles/2DPLATFORMER.dir/main.cpp.o
2DPLATFORMER: CMakeFiles/2DPLATFORMER.dir/build.make
2DPLATFORMER: external/glfw/src/libglfw3.a
2DPLATFORMER: external/glad/libglad.a
2DPLATFORMER: /usr/lib/x86_64-linux-gnu/librt.a
2DPLATFORMER: /usr/lib/x86_64-linux-gnu/libm.so
2DPLATFORMER: CMakeFiles/2DPLATFORMER.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ratatouille/2d_platformer/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 2DPLATFORMER"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2DPLATFORMER.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2DPLATFORMER.dir/build: 2DPLATFORMER
.PHONY : CMakeFiles/2DPLATFORMER.dir/build

CMakeFiles/2DPLATFORMER.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2DPLATFORMER.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2DPLATFORMER.dir/clean

CMakeFiles/2DPLATFORMER.dir/depend:
	cd /home/ratatouille/2d_platformer/out/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ratatouille/2d_platformer /home/ratatouille/2d_platformer /home/ratatouille/2d_platformer/out/build /home/ratatouille/2d_platformer/out/build /home/ratatouille/2d_platformer/out/build/CMakeFiles/2DPLATFORMER.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2DPLATFORMER.dir/depend

