# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /mnt/d/PI_Backup/PI/P10

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/PI_Backup/PI/P10/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/P10.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/P10.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/P10.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/P10.dir/flags.make

CMakeFiles/P10.dir/getnum.c.o: CMakeFiles/P10.dir/flags.make
CMakeFiles/P10.dir/getnum.c.o: /mnt/d/PI_Backup/PI/P10/getnum.c
CMakeFiles/P10.dir/getnum.c.o: CMakeFiles/P10.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/d/PI_Backup/PI/P10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/P10.dir/getnum.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/P10.dir/getnum.c.o -MF CMakeFiles/P10.dir/getnum.c.o.d -o CMakeFiles/P10.dir/getnum.c.o -c /mnt/d/PI_Backup/PI/P10/getnum.c

CMakeFiles/P10.dir/getnum.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/P10.dir/getnum.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/PI_Backup/PI/P10/getnum.c > CMakeFiles/P10.dir/getnum.c.i

CMakeFiles/P10.dir/getnum.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/P10.dir/getnum.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/PI_Backup/PI/P10/getnum.c -o CMakeFiles/P10.dir/getnum.c.s

CMakeFiles/P10.dir/random.c.o: CMakeFiles/P10.dir/flags.make
CMakeFiles/P10.dir/random.c.o: /mnt/d/PI_Backup/PI/P10/random.c
CMakeFiles/P10.dir/random.c.o: CMakeFiles/P10.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/d/PI_Backup/PI/P10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/P10.dir/random.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/P10.dir/random.c.o -MF CMakeFiles/P10.dir/random.c.o.d -o CMakeFiles/P10.dir/random.c.o -c /mnt/d/PI_Backup/PI/P10/random.c

CMakeFiles/P10.dir/random.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/P10.dir/random.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/PI_Backup/PI/P10/random.c > CMakeFiles/P10.dir/random.c.i

CMakeFiles/P10.dir/random.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/P10.dir/random.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/PI_Backup/PI/P10/random.c -o CMakeFiles/P10.dir/random.c.s

CMakeFiles/P10.dir/utillist.c.o: CMakeFiles/P10.dir/flags.make
CMakeFiles/P10.dir/utillist.c.o: /mnt/d/PI_Backup/PI/P10/utillist.c
CMakeFiles/P10.dir/utillist.c.o: CMakeFiles/P10.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/d/PI_Backup/PI/P10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/P10.dir/utillist.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/P10.dir/utillist.c.o -MF CMakeFiles/P10.dir/utillist.c.o.d -o CMakeFiles/P10.dir/utillist.c.o -c /mnt/d/PI_Backup/PI/P10/utillist.c

CMakeFiles/P10.dir/utillist.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/P10.dir/utillist.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/PI_Backup/PI/P10/utillist.c > CMakeFiles/P10.dir/utillist.c.i

CMakeFiles/P10.dir/utillist.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/P10.dir/utillist.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/PI_Backup/PI/P10/utillist.c -o CMakeFiles/P10.dir/utillist.c.s

CMakeFiles/P10.dir/Ej9.c.o: CMakeFiles/P10.dir/flags.make
CMakeFiles/P10.dir/Ej9.c.o: /mnt/d/PI_Backup/PI/P10/Ej9.c
CMakeFiles/P10.dir/Ej9.c.o: CMakeFiles/P10.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/d/PI_Backup/PI/P10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/P10.dir/Ej9.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/P10.dir/Ej9.c.o -MF CMakeFiles/P10.dir/Ej9.c.o.d -o CMakeFiles/P10.dir/Ej9.c.o -c /mnt/d/PI_Backup/PI/P10/Ej9.c

CMakeFiles/P10.dir/Ej9.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/P10.dir/Ej9.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/PI_Backup/PI/P10/Ej9.c > CMakeFiles/P10.dir/Ej9.c.i

CMakeFiles/P10.dir/Ej9.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/P10.dir/Ej9.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/PI_Backup/PI/P10/Ej9.c -o CMakeFiles/P10.dir/Ej9.c.s

# Object files for target P10
P10_OBJECTS = \
"CMakeFiles/P10.dir/getnum.c.o" \
"CMakeFiles/P10.dir/random.c.o" \
"CMakeFiles/P10.dir/utillist.c.o" \
"CMakeFiles/P10.dir/Ej9.c.o"

# External object files for target P10
P10_EXTERNAL_OBJECTS =

P10: CMakeFiles/P10.dir/getnum.c.o
P10: CMakeFiles/P10.dir/random.c.o
P10: CMakeFiles/P10.dir/utillist.c.o
P10: CMakeFiles/P10.dir/Ej9.c.o
P10: CMakeFiles/P10.dir/build.make
P10: CMakeFiles/P10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/d/PI_Backup/PI/P10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable P10"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/P10.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/P10.dir/build: P10
.PHONY : CMakeFiles/P10.dir/build

CMakeFiles/P10.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/P10.dir/cmake_clean.cmake
.PHONY : CMakeFiles/P10.dir/clean

CMakeFiles/P10.dir/depend:
	cd /mnt/d/PI_Backup/PI/P10/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/PI_Backup/PI/P10 /mnt/d/PI_Backup/PI/P10 /mnt/d/PI_Backup/PI/P10/cmake-build-debug /mnt/d/PI_Backup/PI/P10/cmake-build-debug /mnt/d/PI_Backup/PI/P10/cmake-build-debug/CMakeFiles/P10.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/P10.dir/depend

