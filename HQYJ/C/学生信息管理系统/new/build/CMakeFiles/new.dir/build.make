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

# Include any dependencies generated for this target.
include CMakeFiles/new.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/new.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/new.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/new.dir/flags.make

CMakeFiles/new.dir/stu_manage.c.obj: CMakeFiles/new.dir/flags.make
CMakeFiles/new.dir/stu_manage.c.obj: D:/onedrive/ykdeng_ttdhx/OneDrive\ -\ ttdhx/Laptop/Desktop/git_workspace/HQYJ_Study/HQYJ/C/学生信息管理系统/new/stu_manage.c
CMakeFiles/new.dir/stu_manage.c.obj: CMakeFiles/new.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\onedrive\ykdeng_ttdhx\OneDrive - ttdhx\Laptop\Desktop\git_workspace\HQYJ_Study\HQYJ\C\学生信息管理系统\new\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/new.dir/stu_manage.c.obj"
	E:\Qt\Tools\mingw810_64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/new.dir/stu_manage.c.obj -MF CMakeFiles\new.dir\stu_manage.c.obj.d -o CMakeFiles\new.dir\stu_manage.c.obj -c "D:\onedrive\ykdeng_ttdhx\OneDrive - ttdhx\Laptop\Desktop\git_workspace\HQYJ_Study\HQYJ\C\学生信息管理系统\new\stu_manage.c"

CMakeFiles/new.dir/stu_manage.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/new.dir/stu_manage.c.i"
	E:\Qt\Tools\mingw810_64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\onedrive\ykdeng_ttdhx\OneDrive - ttdhx\Laptop\Desktop\git_workspace\HQYJ_Study\HQYJ\C\学生信息管理系统\new\stu_manage.c" > CMakeFiles\new.dir\stu_manage.c.i

CMakeFiles/new.dir/stu_manage.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/new.dir/stu_manage.c.s"
	E:\Qt\Tools\mingw810_64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\onedrive\ykdeng_ttdhx\OneDrive - ttdhx\Laptop\Desktop\git_workspace\HQYJ_Study\HQYJ\C\学生信息管理系统\new\stu_manage.c" -o CMakeFiles\new.dir\stu_manage.c.s

# Object files for target new
new_OBJECTS = \
"CMakeFiles/new.dir/stu_manage.c.obj"

# External object files for target new
new_EXTERNAL_OBJECTS =

libnew.a: CMakeFiles/new.dir/stu_manage.c.obj
libnew.a: CMakeFiles/new.dir/build.make
libnew.a: CMakeFiles/new.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\onedrive\ykdeng_ttdhx\OneDrive - ttdhx\Laptop\Desktop\git_workspace\HQYJ_Study\HQYJ\C\学生信息管理系统\new\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libnew.a"
	$(CMAKE_COMMAND) -P CMakeFiles\new.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\new.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/new.dir/build: libnew.a
.PHONY : CMakeFiles/new.dir/build

CMakeFiles/new.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\new.dir\cmake_clean.cmake
.PHONY : CMakeFiles/new.dir/clean

CMakeFiles/new.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\onedrive\ykdeng_ttdhx\OneDrive - ttdhx\Laptop\Desktop\git_workspace\HQYJ_Study\HQYJ\C\学生信息管理系统\new" "D:\onedrive\ykdeng_ttdhx\OneDrive - ttdhx\Laptop\Desktop\git_workspace\HQYJ_Study\HQYJ\C\学生信息管理系统\new" "D:\onedrive\ykdeng_ttdhx\OneDrive - ttdhx\Laptop\Desktop\git_workspace\HQYJ_Study\HQYJ\C\学生信息管理系统\new\build" "D:\onedrive\ykdeng_ttdhx\OneDrive - ttdhx\Laptop\Desktop\git_workspace\HQYJ_Study\HQYJ\C\学生信息管理系统\new\build" "D:\onedrive\ykdeng_ttdhx\OneDrive - ttdhx\Laptop\Desktop\git_workspace\HQYJ_Study\HQYJ\C\学生信息管理系统\new\build\CMakeFiles\new.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/new.dir/depend

