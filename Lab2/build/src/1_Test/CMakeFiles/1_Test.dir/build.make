# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\code\C_and_C++\data_structure\Experiments\Lab2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\code\C_and_C++\data_structure\Experiments\Lab2\build

# Include any dependencies generated for this target.
include src/1_Test/CMakeFiles/1_Test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/1_Test/CMakeFiles/1_Test.dir/compiler_depend.make

# Include the progress variables for this target.
include src/1_Test/CMakeFiles/1_Test.dir/progress.make

# Include the compile flags for this target's objects.
include src/1_Test/CMakeFiles/1_Test.dir/flags.make

src/1_Test/CMakeFiles/1_Test.dir/codegen:
.PHONY : src/1_Test/CMakeFiles/1_Test.dir/codegen

src/1_Test/CMakeFiles/1_Test.dir/main.cpp.obj: src/1_Test/CMakeFiles/1_Test.dir/flags.make
src/1_Test/CMakeFiles/1_Test.dir/main.cpp.obj: src/1_Test/CMakeFiles/1_Test.dir/includes_CXX.rsp
src/1_Test/CMakeFiles/1_Test.dir/main.cpp.obj: D:/code/C_and_C++/data_structure/Experiments/Lab2/src/1_Test/main.cpp
src/1_Test/CMakeFiles/1_Test.dir/main.cpp.obj: src/1_Test/CMakeFiles/1_Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\code\C_and_C++\data_structure\Experiments\Lab2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/1_Test/CMakeFiles/1_Test.dir/main.cpp.obj"
	cd /d D:\code\C_and_C++\data_structure\Experiments\Lab2\build\src\1_Test && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/1_Test/CMakeFiles/1_Test.dir/main.cpp.obj -MF CMakeFiles\1_Test.dir\main.cpp.obj.d -o CMakeFiles\1_Test.dir\main.cpp.obj -c D:\code\C_and_C++\data_structure\Experiments\Lab2\src\1_Test\main.cpp

src/1_Test/CMakeFiles/1_Test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/1_Test.dir/main.cpp.i"
	cd /d D:\code\C_and_C++\data_structure\Experiments\Lab2\build\src\1_Test && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\C_and_C++\data_structure\Experiments\Lab2\src\1_Test\main.cpp > CMakeFiles\1_Test.dir\main.cpp.i

src/1_Test/CMakeFiles/1_Test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/1_Test.dir/main.cpp.s"
	cd /d D:\code\C_and_C++\data_structure\Experiments\Lab2\build\src\1_Test && C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\C_and_C++\data_structure\Experiments\Lab2\src\1_Test\main.cpp -o CMakeFiles\1_Test.dir\main.cpp.s

# Object files for target 1_Test
1_Test_OBJECTS = \
"CMakeFiles/1_Test.dir/main.cpp.obj"

# External object files for target 1_Test
1_Test_EXTERNAL_OBJECTS =

src/1_Test/1_Test.exe: src/1_Test/CMakeFiles/1_Test.dir/main.cpp.obj
src/1_Test/1_Test.exe: src/1_Test/CMakeFiles/1_Test.dir/build.make
src/1_Test/1_Test.exe: src/structures/libstructures.a
src/1_Test/1_Test.exe: src/1_Test/CMakeFiles/1_Test.dir/linkLibs.rsp
src/1_Test/1_Test.exe: src/1_Test/CMakeFiles/1_Test.dir/objects1.rsp
src/1_Test/1_Test.exe: src/1_Test/CMakeFiles/1_Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\code\C_and_C++\data_structure\Experiments\Lab2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1_Test.exe"
	cd /d D:\code\C_and_C++\data_structure\Experiments\Lab2\build\src\1_Test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\1_Test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/1_Test/CMakeFiles/1_Test.dir/build: src/1_Test/1_Test.exe
.PHONY : src/1_Test/CMakeFiles/1_Test.dir/build

src/1_Test/CMakeFiles/1_Test.dir/clean:
	cd /d D:\code\C_and_C++\data_structure\Experiments\Lab2\build\src\1_Test && $(CMAKE_COMMAND) -P CMakeFiles\1_Test.dir\cmake_clean.cmake
.PHONY : src/1_Test/CMakeFiles/1_Test.dir/clean

src/1_Test/CMakeFiles/1_Test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\code\C_and_C++\data_structure\Experiments\Lab2 D:\code\C_and_C++\data_structure\Experiments\Lab2\src\1_Test D:\code\C_and_C++\data_structure\Experiments\Lab2\build D:\code\C_and_C++\data_structure\Experiments\Lab2\build\src\1_Test D:\code\C_and_C++\data_structure\Experiments\Lab2\build\src\1_Test\CMakeFiles\1_Test.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/1_Test/CMakeFiles/1_Test.dir/depend

