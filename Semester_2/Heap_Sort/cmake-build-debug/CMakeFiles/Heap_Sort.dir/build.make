# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "/cygdrive/c/Users/Alexandra(Student)/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe"

# The command to remove a file.
RM = "/cygdrive/c/Users/Alexandra(Student)/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/Alexandra(Student)/Desktop/C++/Semester_2/Heap_Sort"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/Alexandra(Student)/Desktop/C++/Semester_2/Heap_Sort/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Heap_Sort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Heap_Sort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Heap_Sort.dir/flags.make

CMakeFiles/Heap_Sort.dir/main.cpp.o: CMakeFiles/Heap_Sort.dir/flags.make
CMakeFiles/Heap_Sort.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/Alexandra(Student)/Desktop/C++/Semester_2/Heap_Sort/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Heap_Sort.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Heap_Sort.dir/main.cpp.o -c "/cygdrive/c/Users/Alexandra(Student)/Desktop/C++/Semester_2/Heap_Sort/main.cpp"

CMakeFiles/Heap_Sort.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Heap_Sort.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/Alexandra(Student)/Desktop/C++/Semester_2/Heap_Sort/main.cpp" > CMakeFiles/Heap_Sort.dir/main.cpp.i

CMakeFiles/Heap_Sort.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Heap_Sort.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/Alexandra(Student)/Desktop/C++/Semester_2/Heap_Sort/main.cpp" -o CMakeFiles/Heap_Sort.dir/main.cpp.s

# Object files for target Heap_Sort
Heap_Sort_OBJECTS = \
"CMakeFiles/Heap_Sort.dir/main.cpp.o"

# External object files for target Heap_Sort
Heap_Sort_EXTERNAL_OBJECTS =

Heap_Sort.exe: CMakeFiles/Heap_Sort.dir/main.cpp.o
Heap_Sort.exe: CMakeFiles/Heap_Sort.dir/build.make
Heap_Sort.exe: CMakeFiles/Heap_Sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/Alexandra(Student)/Desktop/C++/Semester_2/Heap_Sort/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Heap_Sort.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Heap_Sort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Heap_Sort.dir/build: Heap_Sort.exe

.PHONY : CMakeFiles/Heap_Sort.dir/build

CMakeFiles/Heap_Sort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Heap_Sort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Heap_Sort.dir/clean

CMakeFiles/Heap_Sort.dir/depend:
	cd "/cygdrive/c/Users/Alexandra(Student)/Desktop/C++/Semester_2/Heap_Sort/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/Alexandra(Student)/Desktop/C++/Semester_2/Heap_Sort" "/cygdrive/c/Users/Alexandra(Student)/Desktop/C++/Semester_2/Heap_Sort" "/cygdrive/c/Users/Alexandra(Student)/Desktop/C++/Semester_2/Heap_Sort/cmake-build-debug" "/cygdrive/c/Users/Alexandra(Student)/Desktop/C++/Semester_2/Heap_Sort/cmake-build-debug" "/cygdrive/c/Users/Alexandra(Student)/Desktop/C++/Semester_2/Heap_Sort/cmake-build-debug/CMakeFiles/Heap_Sort.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Heap_Sort.dir/depend

