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
CMAKE_SOURCE_DIR = /home/ratatouille/2dplatformer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ratatouille/2dplatformer/build

# Include any dependencies generated for this target.
include external/glad/CMakeFiles/glad.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include external/glad/CMakeFiles/glad.dir/compiler_depend.make

# Include the progress variables for this target.
include external/glad/CMakeFiles/glad.dir/progress.make

# Include the compile flags for this target's objects.
include external/glad/CMakeFiles/glad.dir/flags.make

external/glad/CMakeFiles/glad.dir/src/glad.c.o: external/glad/CMakeFiles/glad.dir/flags.make
external/glad/CMakeFiles/glad.dir/src/glad.c.o: ../external/glad/src/glad.c
external/glad/CMakeFiles/glad.dir/src/glad.c.o: external/glad/CMakeFiles/glad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ratatouille/2dplatformer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object external/glad/CMakeFiles/glad.dir/src/glad.c.o"
	cd /home/ratatouille/2dplatformer/build/external/glad && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT external/glad/CMakeFiles/glad.dir/src/glad.c.o -MF CMakeFiles/glad.dir/src/glad.c.o.d -o CMakeFiles/glad.dir/src/glad.c.o -c /home/ratatouille/2dplatformer/external/glad/src/glad.c

external/glad/CMakeFiles/glad.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glad.dir/src/glad.c.i"
	cd /home/ratatouille/2dplatformer/build/external/glad && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ratatouille/2dplatformer/external/glad/src/glad.c > CMakeFiles/glad.dir/src/glad.c.i

external/glad/CMakeFiles/glad.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glad.dir/src/glad.c.s"
	cd /home/ratatouille/2dplatformer/build/external/glad && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ratatouille/2dplatformer/external/glad/src/glad.c -o CMakeFiles/glad.dir/src/glad.c.s

# Object files for target glad
glad_OBJECTS = \
"CMakeFiles/glad.dir/src/glad.c.o"

# External object files for target glad
glad_EXTERNAL_OBJECTS =

external/glad/libglad.a: external/glad/CMakeFiles/glad.dir/src/glad.c.o
external/glad/libglad.a: external/glad/CMakeFiles/glad.dir/build.make
external/glad/libglad.a: external/glad/CMakeFiles/glad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ratatouille/2dplatformer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libglad.a"
	cd /home/ratatouille/2dplatformer/build/external/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean_target.cmake
	cd /home/ratatouille/2dplatformer/build/external/glad && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/glad/CMakeFiles/glad.dir/build: external/glad/libglad.a
.PHONY : external/glad/CMakeFiles/glad.dir/build

external/glad/CMakeFiles/glad.dir/clean:
	cd /home/ratatouille/2dplatformer/build/external/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean.cmake
.PHONY : external/glad/CMakeFiles/glad.dir/clean

external/glad/CMakeFiles/glad.dir/depend:
	cd /home/ratatouille/2dplatformer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ratatouille/2dplatformer /home/ratatouille/2dplatformer/external/glad /home/ratatouille/2dplatformer/build /home/ratatouille/2dplatformer/build/external/glad /home/ratatouille/2dplatformer/build/external/glad/CMakeFiles/glad.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/glad/CMakeFiles/glad.dir/depend

