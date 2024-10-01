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
include src/CMakeFiles/GameLibrary.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/GameLibrary.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/GameLibrary.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/GameLibrary.dir/flags.make

src/CMakeFiles/GameLibrary.dir/game.cpp.o: src/CMakeFiles/GameLibrary.dir/flags.make
src/CMakeFiles/GameLibrary.dir/game.cpp.o: ../src/game.cpp
src/CMakeFiles/GameLibrary.dir/game.cpp.o: src/CMakeFiles/GameLibrary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ratatouille/2dplatformer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/GameLibrary.dir/game.cpp.o"
	cd /home/ratatouille/2dplatformer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/GameLibrary.dir/game.cpp.o -MF CMakeFiles/GameLibrary.dir/game.cpp.o.d -o CMakeFiles/GameLibrary.dir/game.cpp.o -c /home/ratatouille/2dplatformer/src/game.cpp

src/CMakeFiles/GameLibrary.dir/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameLibrary.dir/game.cpp.i"
	cd /home/ratatouille/2dplatformer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ratatouille/2dplatformer/src/game.cpp > CMakeFiles/GameLibrary.dir/game.cpp.i

src/CMakeFiles/GameLibrary.dir/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameLibrary.dir/game.cpp.s"
	cd /home/ratatouille/2dplatformer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ratatouille/2dplatformer/src/game.cpp -o CMakeFiles/GameLibrary.dir/game.cpp.s

src/CMakeFiles/GameLibrary.dir/resource_manager.cpp.o: src/CMakeFiles/GameLibrary.dir/flags.make
src/CMakeFiles/GameLibrary.dir/resource_manager.cpp.o: ../src/resource_manager.cpp
src/CMakeFiles/GameLibrary.dir/resource_manager.cpp.o: src/CMakeFiles/GameLibrary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ratatouille/2dplatformer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/GameLibrary.dir/resource_manager.cpp.o"
	cd /home/ratatouille/2dplatformer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/GameLibrary.dir/resource_manager.cpp.o -MF CMakeFiles/GameLibrary.dir/resource_manager.cpp.o.d -o CMakeFiles/GameLibrary.dir/resource_manager.cpp.o -c /home/ratatouille/2dplatformer/src/resource_manager.cpp

src/CMakeFiles/GameLibrary.dir/resource_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameLibrary.dir/resource_manager.cpp.i"
	cd /home/ratatouille/2dplatformer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ratatouille/2dplatformer/src/resource_manager.cpp > CMakeFiles/GameLibrary.dir/resource_manager.cpp.i

src/CMakeFiles/GameLibrary.dir/resource_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameLibrary.dir/resource_manager.cpp.s"
	cd /home/ratatouille/2dplatformer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ratatouille/2dplatformer/src/resource_manager.cpp -o CMakeFiles/GameLibrary.dir/resource_manager.cpp.s

src/CMakeFiles/GameLibrary.dir/shader.cpp.o: src/CMakeFiles/GameLibrary.dir/flags.make
src/CMakeFiles/GameLibrary.dir/shader.cpp.o: ../src/shader.cpp
src/CMakeFiles/GameLibrary.dir/shader.cpp.o: src/CMakeFiles/GameLibrary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ratatouille/2dplatformer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/GameLibrary.dir/shader.cpp.o"
	cd /home/ratatouille/2dplatformer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/GameLibrary.dir/shader.cpp.o -MF CMakeFiles/GameLibrary.dir/shader.cpp.o.d -o CMakeFiles/GameLibrary.dir/shader.cpp.o -c /home/ratatouille/2dplatformer/src/shader.cpp

src/CMakeFiles/GameLibrary.dir/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameLibrary.dir/shader.cpp.i"
	cd /home/ratatouille/2dplatformer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ratatouille/2dplatformer/src/shader.cpp > CMakeFiles/GameLibrary.dir/shader.cpp.i

src/CMakeFiles/GameLibrary.dir/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameLibrary.dir/shader.cpp.s"
	cd /home/ratatouille/2dplatformer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ratatouille/2dplatformer/src/shader.cpp -o CMakeFiles/GameLibrary.dir/shader.cpp.s

src/CMakeFiles/GameLibrary.dir/stb_image.cpp.o: src/CMakeFiles/GameLibrary.dir/flags.make
src/CMakeFiles/GameLibrary.dir/stb_image.cpp.o: ../src/stb_image.cpp
src/CMakeFiles/GameLibrary.dir/stb_image.cpp.o: src/CMakeFiles/GameLibrary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ratatouille/2dplatformer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/GameLibrary.dir/stb_image.cpp.o"
	cd /home/ratatouille/2dplatformer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/GameLibrary.dir/stb_image.cpp.o -MF CMakeFiles/GameLibrary.dir/stb_image.cpp.o.d -o CMakeFiles/GameLibrary.dir/stb_image.cpp.o -c /home/ratatouille/2dplatformer/src/stb_image.cpp

src/CMakeFiles/GameLibrary.dir/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameLibrary.dir/stb_image.cpp.i"
	cd /home/ratatouille/2dplatformer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ratatouille/2dplatformer/src/stb_image.cpp > CMakeFiles/GameLibrary.dir/stb_image.cpp.i

src/CMakeFiles/GameLibrary.dir/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameLibrary.dir/stb_image.cpp.s"
	cd /home/ratatouille/2dplatformer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ratatouille/2dplatformer/src/stb_image.cpp -o CMakeFiles/GameLibrary.dir/stb_image.cpp.s

src/CMakeFiles/GameLibrary.dir/texture.cpp.o: src/CMakeFiles/GameLibrary.dir/flags.make
src/CMakeFiles/GameLibrary.dir/texture.cpp.o: ../src/texture.cpp
src/CMakeFiles/GameLibrary.dir/texture.cpp.o: src/CMakeFiles/GameLibrary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ratatouille/2dplatformer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/GameLibrary.dir/texture.cpp.o"
	cd /home/ratatouille/2dplatformer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/GameLibrary.dir/texture.cpp.o -MF CMakeFiles/GameLibrary.dir/texture.cpp.o.d -o CMakeFiles/GameLibrary.dir/texture.cpp.o -c /home/ratatouille/2dplatformer/src/texture.cpp

src/CMakeFiles/GameLibrary.dir/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameLibrary.dir/texture.cpp.i"
	cd /home/ratatouille/2dplatformer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ratatouille/2dplatformer/src/texture.cpp > CMakeFiles/GameLibrary.dir/texture.cpp.i

src/CMakeFiles/GameLibrary.dir/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameLibrary.dir/texture.cpp.s"
	cd /home/ratatouille/2dplatformer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ratatouille/2dplatformer/src/texture.cpp -o CMakeFiles/GameLibrary.dir/texture.cpp.s

src/CMakeFiles/GameLibrary.dir/sprite_renderer.cpp.o: src/CMakeFiles/GameLibrary.dir/flags.make
src/CMakeFiles/GameLibrary.dir/sprite_renderer.cpp.o: ../src/sprite_renderer.cpp
src/CMakeFiles/GameLibrary.dir/sprite_renderer.cpp.o: src/CMakeFiles/GameLibrary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ratatouille/2dplatformer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/GameLibrary.dir/sprite_renderer.cpp.o"
	cd /home/ratatouille/2dplatformer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/GameLibrary.dir/sprite_renderer.cpp.o -MF CMakeFiles/GameLibrary.dir/sprite_renderer.cpp.o.d -o CMakeFiles/GameLibrary.dir/sprite_renderer.cpp.o -c /home/ratatouille/2dplatformer/src/sprite_renderer.cpp

src/CMakeFiles/GameLibrary.dir/sprite_renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameLibrary.dir/sprite_renderer.cpp.i"
	cd /home/ratatouille/2dplatformer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ratatouille/2dplatformer/src/sprite_renderer.cpp > CMakeFiles/GameLibrary.dir/sprite_renderer.cpp.i

src/CMakeFiles/GameLibrary.dir/sprite_renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameLibrary.dir/sprite_renderer.cpp.s"
	cd /home/ratatouille/2dplatformer/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ratatouille/2dplatformer/src/sprite_renderer.cpp -o CMakeFiles/GameLibrary.dir/sprite_renderer.cpp.s

# Object files for target GameLibrary
GameLibrary_OBJECTS = \
"CMakeFiles/GameLibrary.dir/game.cpp.o" \
"CMakeFiles/GameLibrary.dir/resource_manager.cpp.o" \
"CMakeFiles/GameLibrary.dir/shader.cpp.o" \
"CMakeFiles/GameLibrary.dir/stb_image.cpp.o" \
"CMakeFiles/GameLibrary.dir/texture.cpp.o" \
"CMakeFiles/GameLibrary.dir/sprite_renderer.cpp.o"

# External object files for target GameLibrary
GameLibrary_EXTERNAL_OBJECTS =

src/libGameLibrary.a: src/CMakeFiles/GameLibrary.dir/game.cpp.o
src/libGameLibrary.a: src/CMakeFiles/GameLibrary.dir/resource_manager.cpp.o
src/libGameLibrary.a: src/CMakeFiles/GameLibrary.dir/shader.cpp.o
src/libGameLibrary.a: src/CMakeFiles/GameLibrary.dir/stb_image.cpp.o
src/libGameLibrary.a: src/CMakeFiles/GameLibrary.dir/texture.cpp.o
src/libGameLibrary.a: src/CMakeFiles/GameLibrary.dir/sprite_renderer.cpp.o
src/libGameLibrary.a: src/CMakeFiles/GameLibrary.dir/build.make
src/libGameLibrary.a: src/CMakeFiles/GameLibrary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ratatouille/2dplatformer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libGameLibrary.a"
	cd /home/ratatouille/2dplatformer/build/src && $(CMAKE_COMMAND) -P CMakeFiles/GameLibrary.dir/cmake_clean_target.cmake
	cd /home/ratatouille/2dplatformer/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GameLibrary.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/GameLibrary.dir/build: src/libGameLibrary.a
.PHONY : src/CMakeFiles/GameLibrary.dir/build

src/CMakeFiles/GameLibrary.dir/clean:
	cd /home/ratatouille/2dplatformer/build/src && $(CMAKE_COMMAND) -P CMakeFiles/GameLibrary.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/GameLibrary.dir/clean

src/CMakeFiles/GameLibrary.dir/depend:
	cd /home/ratatouille/2dplatformer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ratatouille/2dplatformer /home/ratatouille/2dplatformer/src /home/ratatouille/2dplatformer/build /home/ratatouille/2dplatformer/build/src /home/ratatouille/2dplatformer/build/src/CMakeFiles/GameLibrary.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/GameLibrary.dir/depend

