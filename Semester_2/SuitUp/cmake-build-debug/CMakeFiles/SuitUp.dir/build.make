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
CMAKE_COMMAND = /cygdrive/c/Users/Aleksandra/AppData/Local/JetBrains/CLion2020.1/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Aleksandra/AppData/Local/JetBrains/CLion2020.1/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Aleksandra/C-scripts/Semester_2/SuitUp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Aleksandra/C-scripts/Semester_2/SuitUp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SuitUp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SuitUp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SuitUp.dir/flags.make

CMakeFiles/SuitUp.dir/main.cpp.o: CMakeFiles/SuitUp.dir/flags.make
CMakeFiles/SuitUp.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Aleksandra/C-scripts/Semester_2/SuitUp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SuitUp.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SuitUp.dir/main.cpp.o -c /cygdrive/c/Users/Aleksandra/C-scripts/Semester_2/SuitUp/main.cpp

CMakeFiles/SuitUp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SuitUp.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Aleksandra/C-scripts/Semester_2/SuitUp/main.cpp > CMakeFiles/SuitUp.dir/main.cpp.i

CMakeFiles/SuitUp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SuitUp.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Aleksandra/C-scripts/Semester_2/SuitUp/main.cpp -o CMakeFiles/SuitUp.dir/main.cpp.s

# Object files for target SuitUp
SuitUp_OBJECTS = \
"CMakeFiles/SuitUp.dir/main.cpp.o"

# External object files for target SuitUp
SuitUp_EXTERNAL_OBJECTS =

SuitUp.exe: CMakeFiles/SuitUp.dir/main.cpp.o
SuitUp.exe: CMakeFiles/SuitUp.dir/build.make
SuitUp.exe: CMakeFiles/SuitUp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Aleksandra/C-scripts/Semester_2/SuitUp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SuitUp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SuitUp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SuitUp.dir/build: SuitUp.exe

.PHONY : CMakeFiles/SuitUp.dir/build

CMakeFiles/SuitUp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SuitUp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SuitUp.dir/clean

CMakeFiles/SuitUp.dir/depend:
	cd /cygdrive/c/Users/Aleksandra/C-scripts/Semester_2/SuitUp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Aleksandra/C-scripts/Semester_2/SuitUp /cygdrive/c/Users/Aleksandra/C-scripts/Semester_2/SuitUp /cygdrive/c/Users/Aleksandra/C-scripts/Semester_2/SuitUp/cmake-build-debug /cygdrive/c/Users/Aleksandra/C-scripts/Semester_2/SuitUp/cmake-build-debug /cygdrive/c/Users/Aleksandra/C-scripts/Semester_2/SuitUp/cmake-build-debug/CMakeFiles/SuitUp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SuitUp.dir/depend

