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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/aleksandrakarpova/CLionProjects/Contest_15/Task_02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/aleksandrakarpova/CLionProjects/Contest_15/Task_02/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Task_02.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Task_02.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task_02.dir/flags.make

CMakeFiles/Task_02.dir/main.cpp.o: CMakeFiles/Task_02.dir/flags.make
CMakeFiles/Task_02.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aleksandrakarpova/CLionProjects/Contest_15/Task_02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Task_02.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Task_02.dir/main.cpp.o -c /Users/aleksandrakarpova/CLionProjects/Contest_15/Task_02/main.cpp

CMakeFiles/Task_02.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task_02.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aleksandrakarpova/CLionProjects/Contest_15/Task_02/main.cpp > CMakeFiles/Task_02.dir/main.cpp.i

CMakeFiles/Task_02.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task_02.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aleksandrakarpova/CLionProjects/Contest_15/Task_02/main.cpp -o CMakeFiles/Task_02.dir/main.cpp.s

# Object files for target Task_02
Task_02_OBJECTS = \
"CMakeFiles/Task_02.dir/main.cpp.o"

# External object files for target Task_02
Task_02_EXTERNAL_OBJECTS =

Task_02: CMakeFiles/Task_02.dir/main.cpp.o
Task_02: CMakeFiles/Task_02.dir/build.make
Task_02: CMakeFiles/Task_02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/aleksandrakarpova/CLionProjects/Contest_15/Task_02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Task_02"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Task_02.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task_02.dir/build: Task_02

.PHONY : CMakeFiles/Task_02.dir/build

CMakeFiles/Task_02.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Task_02.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Task_02.dir/clean

CMakeFiles/Task_02.dir/depend:
	cd /Users/aleksandrakarpova/CLionProjects/Contest_15/Task_02/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/aleksandrakarpova/CLionProjects/Contest_15/Task_02 /Users/aleksandrakarpova/CLionProjects/Contest_15/Task_02 /Users/aleksandrakarpova/CLionProjects/Contest_15/Task_02/cmake-build-debug /Users/aleksandrakarpova/CLionProjects/Contest_15/Task_02/cmake-build-debug /Users/aleksandrakarpova/CLionProjects/Contest_15/Task_02/cmake-build-debug/CMakeFiles/Task_02.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Task_02.dir/depend

