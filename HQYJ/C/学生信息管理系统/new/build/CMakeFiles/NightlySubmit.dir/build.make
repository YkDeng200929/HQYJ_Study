# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = E:\CMake\cmake-3.24.2-windows-x86_64\bin\cmake.exe

# The command to remove a file.
RM = E:\CMake\cmake-3.24.2-windows-x86_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\onedrive\ykdeng_ttdhx\OneDrive - ttdhx\Laptop\Desktop\git_workspace\HQYJ_Study\HQYJ\C\学生信息管理系统\new"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\onedrive\ykdeng_ttdhx\OneDrive - ttdhx\Laptop\Desktop\git_workspace\HQYJ_Study\HQYJ\C\学生信息管理系统\new\build"

# Utility rule file for NightlySubmit.

# Include any custom commands dependencies for this target.
include CMakeFiles/NightlySubmit.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/NightlySubmit.dir/progress.make

CMakeFiles/NightlySubmit:
	E:\CMake\cmake-3.24.2-windows-x86_64\bin\ctest.exe -D NightlySubmit

NightlySubmit: CMakeFiles/NightlySubmit
NightlySubmit: CMakeFiles/NightlySubmit.dir/build.make
.PHONY : NightlySubmit

# Rule to build all files generated by this target.
CMakeFiles/NightlySubmit.dir/build: NightlySubmit
.PHONY : CMakeFiles/NightlySubmit.dir/build

CMakeFiles/NightlySubmit.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\NightlySubmit.dir\cmake_clean.cmake
.PHONY : CMakeFiles/NightlySubmit.dir/clean

CMakeFiles/NightlySubmit.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\onedrive\ykdeng_ttdhx\OneDrive - ttdhx\Laptop\Desktop\git_workspace\HQYJ_Study\HQYJ\C\学生信息管理系统\new" "D:\onedrive\ykdeng_ttdhx\OneDrive - ttdhx\Laptop\Desktop\git_workspace\HQYJ_Study\HQYJ\C\学生信息管理系统\new" "D:\onedrive\ykdeng_ttdhx\OneDrive - ttdhx\Laptop\Desktop\git_workspace\HQYJ_Study\HQYJ\C\学生信息管理系统\new\build" "D:\onedrive\ykdeng_ttdhx\OneDrive - ttdhx\Laptop\Desktop\git_workspace\HQYJ_Study\HQYJ\C\学生信息管理系统\new\build" "D:\onedrive\ykdeng_ttdhx\OneDrive - ttdhx\Laptop\Desktop\git_workspace\HQYJ_Study\HQYJ\C\学生信息管理系统\new\build\CMakeFiles\NightlySubmit.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/NightlySubmit.dir/depend

