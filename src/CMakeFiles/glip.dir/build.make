# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/robert/ros_wokspace/src/glip

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/robert/ros_wokspace/src/glip/src

# Include any dependencies generated for this target.
include CMakeFiles/glip.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/glip.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/glip.dir/flags.make

CMakeFiles/glip.dir/glipColors.c.o: CMakeFiles/glip.dir/flags.make
CMakeFiles/glip.dir/glipColors.c.o: glipColors.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robert/ros_wokspace/src/glip/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/glip.dir/glipColors.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glip.dir/glipColors.c.o   -c /home/robert/ros_wokspace/src/glip/src/glipColors.c

CMakeFiles/glip.dir/glipColors.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glip.dir/glipColors.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/robert/ros_wokspace/src/glip/src/glipColors.c > CMakeFiles/glip.dir/glipColors.c.i

CMakeFiles/glip.dir/glipColors.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glip.dir/glipColors.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/robert/ros_wokspace/src/glip/src/glipColors.c -o CMakeFiles/glip.dir/glipColors.c.s

CMakeFiles/glip.dir/glipColors.c.o.requires:

.PHONY : CMakeFiles/glip.dir/glipColors.c.o.requires

CMakeFiles/glip.dir/glipColors.c.o.provides: CMakeFiles/glip.dir/glipColors.c.o.requires
	$(MAKE) -f CMakeFiles/glip.dir/build.make CMakeFiles/glip.dir/glipColors.c.o.provides.build
.PHONY : CMakeFiles/glip.dir/glipColors.c.o.provides

CMakeFiles/glip.dir/glipColors.c.o.provides.build: CMakeFiles/glip.dir/glipColors.c.o


CMakeFiles/glip.dir/glipImages.c.o: CMakeFiles/glip.dir/flags.make
CMakeFiles/glip.dir/glipImages.c.o: glipImages.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robert/ros_wokspace/src/glip/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/glip.dir/glipImages.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glip.dir/glipImages.c.o   -c /home/robert/ros_wokspace/src/glip/src/glipImages.c

CMakeFiles/glip.dir/glipImages.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glip.dir/glipImages.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/robert/ros_wokspace/src/glip/src/glipImages.c > CMakeFiles/glip.dir/glipImages.c.i

CMakeFiles/glip.dir/glipImages.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glip.dir/glipImages.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/robert/ros_wokspace/src/glip/src/glipImages.c -o CMakeFiles/glip.dir/glipImages.c.s

CMakeFiles/glip.dir/glipImages.c.o.requires:

.PHONY : CMakeFiles/glip.dir/glipImages.c.o.requires

CMakeFiles/glip.dir/glipImages.c.o.provides: CMakeFiles/glip.dir/glipImages.c.o.requires
	$(MAKE) -f CMakeFiles/glip.dir/build.make CMakeFiles/glip.dir/glipImages.c.o.provides.build
.PHONY : CMakeFiles/glip.dir/glipImages.c.o.provides

CMakeFiles/glip.dir/glipImages.c.o.provides.build: CMakeFiles/glip.dir/glipImages.c.o


CMakeFiles/glip.dir/glipDisplayImage.c.o: CMakeFiles/glip.dir/flags.make
CMakeFiles/glip.dir/glipDisplayImage.c.o: glipDisplayImage.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robert/ros_wokspace/src/glip/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/glip.dir/glipDisplayImage.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glip.dir/glipDisplayImage.c.o   -c /home/robert/ros_wokspace/src/glip/src/glipDisplayImage.c

CMakeFiles/glip.dir/glipDisplayImage.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glip.dir/glipDisplayImage.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/robert/ros_wokspace/src/glip/src/glipDisplayImage.c > CMakeFiles/glip.dir/glipDisplayImage.c.i

CMakeFiles/glip.dir/glipDisplayImage.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glip.dir/glipDisplayImage.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/robert/ros_wokspace/src/glip/src/glipDisplayImage.c -o CMakeFiles/glip.dir/glipDisplayImage.c.s

CMakeFiles/glip.dir/glipDisplayImage.c.o.requires:

.PHONY : CMakeFiles/glip.dir/glipDisplayImage.c.o.requires

CMakeFiles/glip.dir/glipDisplayImage.c.o.provides: CMakeFiles/glip.dir/glipDisplayImage.c.o.requires
	$(MAKE) -f CMakeFiles/glip.dir/build.make CMakeFiles/glip.dir/glipDisplayImage.c.o.provides.build
.PHONY : CMakeFiles/glip.dir/glipDisplayImage.c.o.provides

CMakeFiles/glip.dir/glipDisplayImage.c.o.provides.build: CMakeFiles/glip.dir/glipDisplayImage.c.o


# Object files for target glip
glip_OBJECTS = \
"CMakeFiles/glip.dir/glipColors.c.o" \
"CMakeFiles/glip.dir/glipImages.c.o" \
"CMakeFiles/glip.dir/glipDisplayImage.c.o"

# External object files for target glip
glip_EXTERNAL_OBJECTS =

libglip.a: CMakeFiles/glip.dir/glipColors.c.o
libglip.a: CMakeFiles/glip.dir/glipImages.c.o
libglip.a: CMakeFiles/glip.dir/glipDisplayImage.c.o
libglip.a: CMakeFiles/glip.dir/build.make
libglip.a: CMakeFiles/glip.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/robert/ros_wokspace/src/glip/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C static library libglip.a"
	$(CMAKE_COMMAND) -P CMakeFiles/glip.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glip.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/glip.dir/build: libglip.a

.PHONY : CMakeFiles/glip.dir/build

CMakeFiles/glip.dir/requires: CMakeFiles/glip.dir/glipColors.c.o.requires
CMakeFiles/glip.dir/requires: CMakeFiles/glip.dir/glipImages.c.o.requires
CMakeFiles/glip.dir/requires: CMakeFiles/glip.dir/glipDisplayImage.c.o.requires

.PHONY : CMakeFiles/glip.dir/requires

CMakeFiles/glip.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/glip.dir/cmake_clean.cmake
.PHONY : CMakeFiles/glip.dir/clean

CMakeFiles/glip.dir/depend:
	cd /home/robert/ros_wokspace/src/glip/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/robert/ros_wokspace/src/glip /home/robert/ros_wokspace/src/glip /home/robert/ros_wokspace/src/glip/src /home/robert/ros_wokspace/src/glip/src /home/robert/ros_wokspace/src/glip/src/CMakeFiles/glip.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/glip.dir/depend

