# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/julie/repo/src/cinlinux/ex18

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/julie/repo/src/cinlinux/ex18

# Include any dependencies generated for this target.
include CMakeFiles/cvx.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cvx.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cvx.dir/flags.make

CMakeFiles/cvx.dir/main.c.o: CMakeFiles/cvx.dir/flags.make
CMakeFiles/cvx.dir/main.c.o: main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/julie/repo/src/cinlinux/ex18/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/cvx.dir/main.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/cvx.dir/main.c.o   -c /home/julie/repo/src/cinlinux/ex18/main.c

CMakeFiles/cvx.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cvx.dir/main.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/julie/repo/src/cinlinux/ex18/main.c > CMakeFiles/cvx.dir/main.c.i

CMakeFiles/cvx.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cvx.dir/main.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/julie/repo/src/cinlinux/ex18/main.c -o CMakeFiles/cvx.dir/main.c.s

CMakeFiles/cvx.dir/main.c.o.requires:
.PHONY : CMakeFiles/cvx.dir/main.c.o.requires

CMakeFiles/cvx.dir/main.c.o.provides: CMakeFiles/cvx.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/cvx.dir/build.make CMakeFiles/cvx.dir/main.c.o.provides.build
.PHONY : CMakeFiles/cvx.dir/main.c.o.provides

CMakeFiles/cvx.dir/main.c.o.provides.build: CMakeFiles/cvx.dir/main.c.o
.PHONY : CMakeFiles/cvx.dir/main.c.o.provides.build

CMakeFiles/cvx.dir/cvxfield.c.o: CMakeFiles/cvx.dir/flags.make
CMakeFiles/cvx.dir/cvxfield.c.o: cvxfield.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/julie/repo/src/cinlinux/ex18/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/cvx.dir/cvxfield.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/cvx.dir/cvxfield.c.o   -c /home/julie/repo/src/cinlinux/ex18/cvxfield.c

CMakeFiles/cvx.dir/cvxfield.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cvx.dir/cvxfield.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/julie/repo/src/cinlinux/ex18/cvxfield.c > CMakeFiles/cvx.dir/cvxfield.c.i

CMakeFiles/cvx.dir/cvxfield.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cvx.dir/cvxfield.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/julie/repo/src/cinlinux/ex18/cvxfield.c -o CMakeFiles/cvx.dir/cvxfield.c.s

CMakeFiles/cvx.dir/cvxfield.c.o.requires:
.PHONY : CMakeFiles/cvx.dir/cvxfield.c.o.requires

CMakeFiles/cvx.dir/cvxfield.c.o.provides: CMakeFiles/cvx.dir/cvxfield.c.o.requires
	$(MAKE) -f CMakeFiles/cvx.dir/build.make CMakeFiles/cvx.dir/cvxfield.c.o.provides.build
.PHONY : CMakeFiles/cvx.dir/cvxfield.c.o.provides

CMakeFiles/cvx.dir/cvxfield.c.o.provides.build: CMakeFiles/cvx.dir/cvxfield.c.o
.PHONY : CMakeFiles/cvx.dir/cvxfield.c.o.provides.build

CMakeFiles/cvx.dir/cvxnode.c.o: CMakeFiles/cvx.dir/flags.make
CMakeFiles/cvx.dir/cvxnode.c.o: cvxnode.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/julie/repo/src/cinlinux/ex18/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/cvx.dir/cvxnode.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/cvx.dir/cvxnode.c.o   -c /home/julie/repo/src/cinlinux/ex18/cvxnode.c

CMakeFiles/cvx.dir/cvxnode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cvx.dir/cvxnode.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/julie/repo/src/cinlinux/ex18/cvxnode.c > CMakeFiles/cvx.dir/cvxnode.c.i

CMakeFiles/cvx.dir/cvxnode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cvx.dir/cvxnode.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/julie/repo/src/cinlinux/ex18/cvxnode.c -o CMakeFiles/cvx.dir/cvxnode.c.s

CMakeFiles/cvx.dir/cvxnode.c.o.requires:
.PHONY : CMakeFiles/cvx.dir/cvxnode.c.o.requires

CMakeFiles/cvx.dir/cvxnode.c.o.provides: CMakeFiles/cvx.dir/cvxnode.c.o.requires
	$(MAKE) -f CMakeFiles/cvx.dir/build.make CMakeFiles/cvx.dir/cvxnode.c.o.provides.build
.PHONY : CMakeFiles/cvx.dir/cvxnode.c.o.provides

CMakeFiles/cvx.dir/cvxnode.c.o.provides.build: CMakeFiles/cvx.dir/cvxnode.c.o
.PHONY : CMakeFiles/cvx.dir/cvxnode.c.o.provides.build

CMakeFiles/cvx.dir/cvxnodelist.c.o: CMakeFiles/cvx.dir/flags.make
CMakeFiles/cvx.dir/cvxnodelist.c.o: cvxnodelist.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/julie/repo/src/cinlinux/ex18/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/cvx.dir/cvxnodelist.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/cvx.dir/cvxnodelist.c.o   -c /home/julie/repo/src/cinlinux/ex18/cvxnodelist.c

CMakeFiles/cvx.dir/cvxnodelist.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cvx.dir/cvxnodelist.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/julie/repo/src/cinlinux/ex18/cvxnodelist.c > CMakeFiles/cvx.dir/cvxnodelist.c.i

CMakeFiles/cvx.dir/cvxnodelist.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cvx.dir/cvxnodelist.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/julie/repo/src/cinlinux/ex18/cvxnodelist.c -o CMakeFiles/cvx.dir/cvxnodelist.c.s

CMakeFiles/cvx.dir/cvxnodelist.c.o.requires:
.PHONY : CMakeFiles/cvx.dir/cvxnodelist.c.o.requires

CMakeFiles/cvx.dir/cvxnodelist.c.o.provides: CMakeFiles/cvx.dir/cvxnodelist.c.o.requires
	$(MAKE) -f CMakeFiles/cvx.dir/build.make CMakeFiles/cvx.dir/cvxnodelist.c.o.provides.build
.PHONY : CMakeFiles/cvx.dir/cvxnodelist.c.o.provides

CMakeFiles/cvx.dir/cvxnodelist.c.o.provides.build: CMakeFiles/cvx.dir/cvxnodelist.c.o
.PHONY : CMakeFiles/cvx.dir/cvxnodelist.c.o.provides.build

# Object files for target cvx
cvx_OBJECTS = \
"CMakeFiles/cvx.dir/main.c.o" \
"CMakeFiles/cvx.dir/cvxfield.c.o" \
"CMakeFiles/cvx.dir/cvxnode.c.o" \
"CMakeFiles/cvx.dir/cvxnodelist.c.o"

# External object files for target cvx
cvx_EXTERNAL_OBJECTS =

cvx: CMakeFiles/cvx.dir/main.c.o
cvx: CMakeFiles/cvx.dir/cvxfield.c.o
cvx: CMakeFiles/cvx.dir/cvxnode.c.o
cvx: CMakeFiles/cvx.dir/cvxnodelist.c.o
cvx: CMakeFiles/cvx.dir/build.make
cvx: CMakeFiles/cvx.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable cvx"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cvx.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cvx.dir/build: cvx
.PHONY : CMakeFiles/cvx.dir/build

CMakeFiles/cvx.dir/requires: CMakeFiles/cvx.dir/main.c.o.requires
CMakeFiles/cvx.dir/requires: CMakeFiles/cvx.dir/cvxfield.c.o.requires
CMakeFiles/cvx.dir/requires: CMakeFiles/cvx.dir/cvxnode.c.o.requires
CMakeFiles/cvx.dir/requires: CMakeFiles/cvx.dir/cvxnodelist.c.o.requires
.PHONY : CMakeFiles/cvx.dir/requires

CMakeFiles/cvx.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cvx.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cvx.dir/clean

CMakeFiles/cvx.dir/depend:
	cd /home/julie/repo/src/cinlinux/ex18 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/julie/repo/src/cinlinux/ex18 /home/julie/repo/src/cinlinux/ex18 /home/julie/repo/src/cinlinux/ex18 /home/julie/repo/src/cinlinux/ex18 /home/julie/repo/src/cinlinux/ex18/CMakeFiles/cvx.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cvx.dir/depend
