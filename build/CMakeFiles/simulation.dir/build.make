# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project/build

# Include any dependencies generated for this target.
include CMakeFiles/simulation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/simulation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simulation.dir/flags.make

CMakeFiles/simulation.dir/neuron.cpp.o: CMakeFiles/simulation.dir/flags.make
CMakeFiles/simulation.dir/neuron.cpp.o: ../neuron.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/simulation.dir/neuron.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/simulation.dir/neuron.cpp.o -c /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project/neuron.cpp

CMakeFiles/simulation.dir/neuron.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulation.dir/neuron.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project/neuron.cpp > CMakeFiles/simulation.dir/neuron.cpp.i

CMakeFiles/simulation.dir/neuron.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulation.dir/neuron.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project/neuron.cpp -o CMakeFiles/simulation.dir/neuron.cpp.s

CMakeFiles/simulation.dir/neuron.cpp.o.requires:
.PHONY : CMakeFiles/simulation.dir/neuron.cpp.o.requires

CMakeFiles/simulation.dir/neuron.cpp.o.provides: CMakeFiles/simulation.dir/neuron.cpp.o.requires
	$(MAKE) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/neuron.cpp.o.provides.build
.PHONY : CMakeFiles/simulation.dir/neuron.cpp.o.provides

CMakeFiles/simulation.dir/neuron.cpp.o.provides.build: CMakeFiles/simulation.dir/neuron.cpp.o

CMakeFiles/simulation.dir/brain.cpp.o: CMakeFiles/simulation.dir/flags.make
CMakeFiles/simulation.dir/brain.cpp.o: ../brain.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/simulation.dir/brain.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/simulation.dir/brain.cpp.o -c /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project/brain.cpp

CMakeFiles/simulation.dir/brain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulation.dir/brain.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project/brain.cpp > CMakeFiles/simulation.dir/brain.cpp.i

CMakeFiles/simulation.dir/brain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulation.dir/brain.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project/brain.cpp -o CMakeFiles/simulation.dir/brain.cpp.s

CMakeFiles/simulation.dir/brain.cpp.o.requires:
.PHONY : CMakeFiles/simulation.dir/brain.cpp.o.requires

CMakeFiles/simulation.dir/brain.cpp.o.provides: CMakeFiles/simulation.dir/brain.cpp.o.requires
	$(MAKE) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/brain.cpp.o.provides.build
.PHONY : CMakeFiles/simulation.dir/brain.cpp.o.provides

CMakeFiles/simulation.dir/brain.cpp.o.provides.build: CMakeFiles/simulation.dir/brain.cpp.o

CMakeFiles/simulation.dir/simulation.cpp.o: CMakeFiles/simulation.dir/flags.make
CMakeFiles/simulation.dir/simulation.cpp.o: ../simulation.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/simulation.dir/simulation.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/simulation.dir/simulation.cpp.o -c /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project/simulation.cpp

CMakeFiles/simulation.dir/simulation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulation.dir/simulation.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project/simulation.cpp > CMakeFiles/simulation.dir/simulation.cpp.i

CMakeFiles/simulation.dir/simulation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulation.dir/simulation.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project/simulation.cpp -o CMakeFiles/simulation.dir/simulation.cpp.s

CMakeFiles/simulation.dir/simulation.cpp.o.requires:
.PHONY : CMakeFiles/simulation.dir/simulation.cpp.o.requires

CMakeFiles/simulation.dir/simulation.cpp.o.provides: CMakeFiles/simulation.dir/simulation.cpp.o.requires
	$(MAKE) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/simulation.cpp.o.provides.build
.PHONY : CMakeFiles/simulation.dir/simulation.cpp.o.provides

CMakeFiles/simulation.dir/simulation.cpp.o.provides.build: CMakeFiles/simulation.dir/simulation.cpp.o

CMakeFiles/simulation.dir/main.cpp.o: CMakeFiles/simulation.dir/flags.make
CMakeFiles/simulation.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/simulation.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/simulation.dir/main.cpp.o -c /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project/main.cpp

CMakeFiles/simulation.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulation.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project/main.cpp > CMakeFiles/simulation.dir/main.cpp.i

CMakeFiles/simulation.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulation.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project/main.cpp -o CMakeFiles/simulation.dir/main.cpp.s

CMakeFiles/simulation.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/simulation.dir/main.cpp.o.requires

CMakeFiles/simulation.dir/main.cpp.o.provides: CMakeFiles/simulation.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/simulation.dir/build.make CMakeFiles/simulation.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/simulation.dir/main.cpp.o.provides

CMakeFiles/simulation.dir/main.cpp.o.provides.build: CMakeFiles/simulation.dir/main.cpp.o

# Object files for target simulation
simulation_OBJECTS = \
"CMakeFiles/simulation.dir/neuron.cpp.o" \
"CMakeFiles/simulation.dir/brain.cpp.o" \
"CMakeFiles/simulation.dir/simulation.cpp.o" \
"CMakeFiles/simulation.dir/main.cpp.o"

# External object files for target simulation
simulation_EXTERNAL_OBJECTS =

simulation: CMakeFiles/simulation.dir/neuron.cpp.o
simulation: CMakeFiles/simulation.dir/brain.cpp.o
simulation: CMakeFiles/simulation.dir/simulation.cpp.o
simulation: CMakeFiles/simulation.dir/main.cpp.o
simulation: CMakeFiles/simulation.dir/build.make
simulation: CMakeFiles/simulation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable simulation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simulation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simulation.dir/build: simulation
.PHONY : CMakeFiles/simulation.dir/build

CMakeFiles/simulation.dir/requires: CMakeFiles/simulation.dir/neuron.cpp.o.requires
CMakeFiles/simulation.dir/requires: CMakeFiles/simulation.dir/brain.cpp.o.requires
CMakeFiles/simulation.dir/requires: CMakeFiles/simulation.dir/simulation.cpp.o.requires
CMakeFiles/simulation.dir/requires: CMakeFiles/simulation.dir/main.cpp.o.requires
.PHONY : CMakeFiles/simulation.dir/requires

CMakeFiles/simulation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simulation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simulation.dir/clean

CMakeFiles/simulation.dir/depend:
	cd /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project/build /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project/build /home/INTRANET/fmagaud/myfiles/cpp/semestre3/neurons_project/build/CMakeFiles/simulation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simulation.dir/depend

