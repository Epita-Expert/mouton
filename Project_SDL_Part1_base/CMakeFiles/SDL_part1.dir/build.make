# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base

# Include any dependencies generated for this target.
include CMakeFiles/SDL_part1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SDL_part1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SDL_part1.dir/flags.make

CMakeFiles/SDL_part1.dir/main.cpp.o: CMakeFiles/SDL_part1.dir/flags.make
CMakeFiles/SDL_part1.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SDL_part1.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SDL_part1.dir/main.cpp.o -c /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/main.cpp

CMakeFiles/SDL_part1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL_part1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/main.cpp > CMakeFiles/SDL_part1.dir/main.cpp.i

CMakeFiles/SDL_part1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL_part1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/main.cpp -o CMakeFiles/SDL_part1.dir/main.cpp.s

CMakeFiles/SDL_part1.dir/application.cpp.o: CMakeFiles/SDL_part1.dir/flags.make
CMakeFiles/SDL_part1.dir/application.cpp.o: application.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SDL_part1.dir/application.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SDL_part1.dir/application.cpp.o -c /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/application.cpp

CMakeFiles/SDL_part1.dir/application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL_part1.dir/application.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/application.cpp > CMakeFiles/SDL_part1.dir/application.cpp.i

CMakeFiles/SDL_part1.dir/application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL_part1.dir/application.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/application.cpp -o CMakeFiles/SDL_part1.dir/application.cpp.s

CMakeFiles/SDL_part1.dir/animal.cpp.o: CMakeFiles/SDL_part1.dir/flags.make
CMakeFiles/SDL_part1.dir/animal.cpp.o: animal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SDL_part1.dir/animal.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SDL_part1.dir/animal.cpp.o -c /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/animal.cpp

CMakeFiles/SDL_part1.dir/animal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL_part1.dir/animal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/animal.cpp > CMakeFiles/SDL_part1.dir/animal.cpp.i

CMakeFiles/SDL_part1.dir/animal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL_part1.dir/animal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/animal.cpp -o CMakeFiles/SDL_part1.dir/animal.cpp.s

CMakeFiles/SDL_part1.dir/helper.cpp.o: CMakeFiles/SDL_part1.dir/flags.make
CMakeFiles/SDL_part1.dir/helper.cpp.o: helper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SDL_part1.dir/helper.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SDL_part1.dir/helper.cpp.o -c /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/helper.cpp

CMakeFiles/SDL_part1.dir/helper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL_part1.dir/helper.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/helper.cpp > CMakeFiles/SDL_part1.dir/helper.cpp.i

CMakeFiles/SDL_part1.dir/helper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL_part1.dir/helper.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/helper.cpp -o CMakeFiles/SDL_part1.dir/helper.cpp.s

CMakeFiles/SDL_part1.dir/wolf.cpp.o: CMakeFiles/SDL_part1.dir/flags.make
CMakeFiles/SDL_part1.dir/wolf.cpp.o: wolf.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SDL_part1.dir/wolf.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SDL_part1.dir/wolf.cpp.o -c /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/wolf.cpp

CMakeFiles/SDL_part1.dir/wolf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL_part1.dir/wolf.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/wolf.cpp > CMakeFiles/SDL_part1.dir/wolf.cpp.i

CMakeFiles/SDL_part1.dir/wolf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL_part1.dir/wolf.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/wolf.cpp -o CMakeFiles/SDL_part1.dir/wolf.cpp.s

CMakeFiles/SDL_part1.dir/sheep.cpp.o: CMakeFiles/SDL_part1.dir/flags.make
CMakeFiles/SDL_part1.dir/sheep.cpp.o: sheep.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SDL_part1.dir/sheep.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SDL_part1.dir/sheep.cpp.o -c /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/sheep.cpp

CMakeFiles/SDL_part1.dir/sheep.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL_part1.dir/sheep.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/sheep.cpp > CMakeFiles/SDL_part1.dir/sheep.cpp.i

CMakeFiles/SDL_part1.dir/sheep.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL_part1.dir/sheep.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/sheep.cpp -o CMakeFiles/SDL_part1.dir/sheep.cpp.s

CMakeFiles/SDL_part1.dir/ground.cpp.o: CMakeFiles/SDL_part1.dir/flags.make
CMakeFiles/SDL_part1.dir/ground.cpp.o: ground.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SDL_part1.dir/ground.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SDL_part1.dir/ground.cpp.o -c /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/ground.cpp

CMakeFiles/SDL_part1.dir/ground.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL_part1.dir/ground.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/ground.cpp > CMakeFiles/SDL_part1.dir/ground.cpp.i

CMakeFiles/SDL_part1.dir/ground.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL_part1.dir/ground.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/ground.cpp -o CMakeFiles/SDL_part1.dir/ground.cpp.s

# Object files for target SDL_part1
SDL_part1_OBJECTS = \
"CMakeFiles/SDL_part1.dir/main.cpp.o" \
"CMakeFiles/SDL_part1.dir/application.cpp.o" \
"CMakeFiles/SDL_part1.dir/animal.cpp.o" \
"CMakeFiles/SDL_part1.dir/helper.cpp.o" \
"CMakeFiles/SDL_part1.dir/wolf.cpp.o" \
"CMakeFiles/SDL_part1.dir/sheep.cpp.o" \
"CMakeFiles/SDL_part1.dir/ground.cpp.o"

# External object files for target SDL_part1
SDL_part1_EXTERNAL_OBJECTS =

SDL_part1: CMakeFiles/SDL_part1.dir/main.cpp.o
SDL_part1: CMakeFiles/SDL_part1.dir/application.cpp.o
SDL_part1: CMakeFiles/SDL_part1.dir/animal.cpp.o
SDL_part1: CMakeFiles/SDL_part1.dir/helper.cpp.o
SDL_part1: CMakeFiles/SDL_part1.dir/wolf.cpp.o
SDL_part1: CMakeFiles/SDL_part1.dir/sheep.cpp.o
SDL_part1: CMakeFiles/SDL_part1.dir/ground.cpp.o
SDL_part1: CMakeFiles/SDL_part1.dir/build.make
SDL_part1: CMakeFiles/SDL_part1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable SDL_part1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SDL_part1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SDL_part1.dir/build: SDL_part1

.PHONY : CMakeFiles/SDL_part1.dir/build

CMakeFiles/SDL_part1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SDL_part1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SDL_part1.dir/clean

CMakeFiles/SDL_part1.dir/depend:
	cd /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base /home/minaro/GitHub/epita/mouton/Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SDL_part1.dir/depend

