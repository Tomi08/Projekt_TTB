# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Adatszerkezetek\Projekt_TTB

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Adatszerkezetek\Projekt_TTB\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Projekt_TTB.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Projekt_TTB.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Projekt_TTB.dir/flags.make

CMakeFiles/Projekt_TTB.dir/main.c.obj: CMakeFiles/Projekt_TTB.dir/flags.make
CMakeFiles/Projekt_TTB.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Adatszerkezetek\Projekt_TTB\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Projekt_TTB.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Projekt_TTB.dir\main.c.obj   -c E:\Adatszerkezetek\Projekt_TTB\main.c

CMakeFiles/Projekt_TTB.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Projekt_TTB.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\Adatszerkezetek\Projekt_TTB\main.c > CMakeFiles\Projekt_TTB.dir\main.c.i

CMakeFiles/Projekt_TTB.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Projekt_TTB.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\Adatszerkezetek\Projekt_TTB\main.c -o CMakeFiles\Projekt_TTB.dir\main.c.s

CMakeFiles/Projekt_TTB.dir/functions.c.obj: CMakeFiles/Projekt_TTB.dir/flags.make
CMakeFiles/Projekt_TTB.dir/functions.c.obj: ../functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Adatszerkezetek\Projekt_TTB\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Projekt_TTB.dir/functions.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Projekt_TTB.dir\functions.c.obj   -c E:\Adatszerkezetek\Projekt_TTB\functions.c

CMakeFiles/Projekt_TTB.dir/functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Projekt_TTB.dir/functions.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\Adatszerkezetek\Projekt_TTB\functions.c > CMakeFiles\Projekt_TTB.dir\functions.c.i

CMakeFiles/Projekt_TTB.dir/functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Projekt_TTB.dir/functions.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\Adatszerkezetek\Projekt_TTB\functions.c -o CMakeFiles\Projekt_TTB.dir\functions.c.s

# Object files for target Projekt_TTB
Projekt_TTB_OBJECTS = \
"CMakeFiles/Projekt_TTB.dir/main.c.obj" \
"CMakeFiles/Projekt_TTB.dir/functions.c.obj"

# External object files for target Projekt_TTB
Projekt_TTB_EXTERNAL_OBJECTS =

Projekt_TTB.exe: CMakeFiles/Projekt_TTB.dir/main.c.obj
Projekt_TTB.exe: CMakeFiles/Projekt_TTB.dir/functions.c.obj
Projekt_TTB.exe: CMakeFiles/Projekt_TTB.dir/build.make
Projekt_TTB.exe: CMakeFiles/Projekt_TTB.dir/linklibs.rsp
Projekt_TTB.exe: CMakeFiles/Projekt_TTB.dir/objects1.rsp
Projekt_TTB.exe: CMakeFiles/Projekt_TTB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Adatszerkezetek\Projekt_TTB\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Projekt_TTB.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Projekt_TTB.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Projekt_TTB.dir/build: Projekt_TTB.exe

.PHONY : CMakeFiles/Projekt_TTB.dir/build

CMakeFiles/Projekt_TTB.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Projekt_TTB.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Projekt_TTB.dir/clean

CMakeFiles/Projekt_TTB.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Adatszerkezetek\Projekt_TTB E:\Adatszerkezetek\Projekt_TTB E:\Adatszerkezetek\Projekt_TTB\cmake-build-debug E:\Adatszerkezetek\Projekt_TTB\cmake-build-debug E:\Adatszerkezetek\Projekt_TTB\cmake-build-debug\CMakeFiles\Projekt_TTB.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Projekt_TTB.dir/depend

