# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/tmp.lLEymK9Mk6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.lLEymK9Mk6/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/POS_semestral_klient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/POS_semestral_klient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/POS_semestral_klient.dir/flags.make

CMakeFiles/POS_semestral_klient.dir/main.c.o: CMakeFiles/POS_semestral_klient.dir/flags.make
CMakeFiles/POS_semestral_klient.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.lLEymK9Mk6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/POS_semestral_klient.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/POS_semestral_klient.dir/main.c.o   -c /tmp/tmp.lLEymK9Mk6/main.c

CMakeFiles/POS_semestral_klient.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/POS_semestral_klient.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.lLEymK9Mk6/main.c > CMakeFiles/POS_semestral_klient.dir/main.c.i

CMakeFiles/POS_semestral_klient.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/POS_semestral_klient.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.lLEymK9Mk6/main.c -o CMakeFiles/POS_semestral_klient.dir/main.c.s

CMakeFiles/POS_semestral_klient.dir/main.c.o.requires:

.PHONY : CMakeFiles/POS_semestral_klient.dir/main.c.o.requires

CMakeFiles/POS_semestral_klient.dir/main.c.o.provides: CMakeFiles/POS_semestral_klient.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/POS_semestral_klient.dir/build.make CMakeFiles/POS_semestral_klient.dir/main.c.o.provides.build
.PHONY : CMakeFiles/POS_semestral_klient.dir/main.c.o.provides

CMakeFiles/POS_semestral_klient.dir/main.c.o.provides.build: CMakeFiles/POS_semestral_klient.dir/main.c.o


# Object files for target POS_semestral_klient
POS_semestral_klient_OBJECTS = \
"CMakeFiles/POS_semestral_klient.dir/main.c.o"

# External object files for target POS_semestral_klient
POS_semestral_klient_EXTERNAL_OBJECTS =

POS_semestral_klient: CMakeFiles/POS_semestral_klient.dir/main.c.o
POS_semestral_klient: CMakeFiles/POS_semestral_klient.dir/build.make
POS_semestral_klient: CMakeFiles/POS_semestral_klient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.lLEymK9Mk6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable POS_semestral_klient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/POS_semestral_klient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/POS_semestral_klient.dir/build: POS_semestral_klient

.PHONY : CMakeFiles/POS_semestral_klient.dir/build

CMakeFiles/POS_semestral_klient.dir/requires: CMakeFiles/POS_semestral_klient.dir/main.c.o.requires

.PHONY : CMakeFiles/POS_semestral_klient.dir/requires

CMakeFiles/POS_semestral_klient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/POS_semestral_klient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/POS_semestral_klient.dir/clean

CMakeFiles/POS_semestral_klient.dir/depend:
	cd /tmp/tmp.lLEymK9Mk6/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.lLEymK9Mk6 /tmp/tmp.lLEymK9Mk6 /tmp/tmp.lLEymK9Mk6/cmake-build-debug /tmp/tmp.lLEymK9Mk6/cmake-build-debug /tmp/tmp.lLEymK9Mk6/cmake-build-debug/CMakeFiles/POS_semestral_klient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/POS_semestral_klient.dir/depend

