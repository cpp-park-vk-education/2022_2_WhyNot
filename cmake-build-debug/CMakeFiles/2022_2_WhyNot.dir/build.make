# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = \\wsl$$\Ubuntu-20.04\home\dsa\2022_2_WhyNot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = \\wsl$$\Ubuntu-20.04\home\dsa\2022_2_WhyNot\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/2022_2_WhyNot.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/2022_2_WhyNot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2022_2_WhyNot.dir/flags.make

CMakeFiles/2022_2_WhyNot.dir/main.cpp.obj: CMakeFiles/2022_2_WhyNot.dir/flags.make
CMakeFiles/2022_2_WhyNot.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=\\wsl$$\Ubuntu-20.04\home\dsa\2022_2_WhyNot\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2022_2_WhyNot.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2022_2_WhyNot.dir\main.cpp.obj -c \\wsl$$\Ubuntu-20.04\home\dsa\2022_2_WhyNot\main.cpp

CMakeFiles/2022_2_WhyNot.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2022_2_WhyNot.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E \\wsl$$\Ubuntu-20.04\home\dsa\2022_2_WhyNot\main.cpp > CMakeFiles\2022_2_WhyNot.dir\main.cpp.i

CMakeFiles/2022_2_WhyNot.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2022_2_WhyNot.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S \\wsl$$\Ubuntu-20.04\home\dsa\2022_2_WhyNot\main.cpp -o CMakeFiles\2022_2_WhyNot.dir\main.cpp.s

# Object files for target 2022_2_WhyNot
2022_2_WhyNot_OBJECTS = \
"CMakeFiles/2022_2_WhyNot.dir/main.cpp.obj"

# External object files for target 2022_2_WhyNot
2022_2_WhyNot_EXTERNAL_OBJECTS =

2022_2_WhyNot.exe: CMakeFiles/2022_2_WhyNot.dir/main.cpp.obj
2022_2_WhyNot.exe: CMakeFiles/2022_2_WhyNot.dir/build.make
2022_2_WhyNot.exe: CMakeFiles/2022_2_WhyNot.dir/linklibs.rsp
2022_2_WhyNot.exe: CMakeFiles/2022_2_WhyNot.dir/objects1.rsp
2022_2_WhyNot.exe: CMakeFiles/2022_2_WhyNot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=\\wsl$$\Ubuntu-20.04\home\dsa\2022_2_WhyNot\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 2022_2_WhyNot.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\2022_2_WhyNot.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2022_2_WhyNot.dir/build: 2022_2_WhyNot.exe
.PHONY : CMakeFiles/2022_2_WhyNot.dir/build

CMakeFiles/2022_2_WhyNot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\2022_2_WhyNot.dir\cmake_clean.cmake
.PHONY : CMakeFiles/2022_2_WhyNot.dir/clean

CMakeFiles/2022_2_WhyNot.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" \\wsl$$\Ubuntu-20.04\home\dsa\2022_2_WhyNot \\wsl$$\Ubuntu-20.04\home\dsa\2022_2_WhyNot \\wsl$$\Ubuntu-20.04\home\dsa\2022_2_WhyNot\cmake-build-debug \\wsl$$\Ubuntu-20.04\home\dsa\2022_2_WhyNot\cmake-build-debug \\wsl$$\Ubuntu-20.04\home\dsa\2022_2_WhyNot\cmake-build-debug\CMakeFiles\2022_2_WhyNot.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2022_2_WhyNot.dir/depend

