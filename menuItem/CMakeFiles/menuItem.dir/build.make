# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/biniam/cs202/projects/cs202_sp23_pa2-1204-Gashaw-Biniam

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/biniam/cs202/projects/cs202_sp23_pa2-1204-Gashaw-Biniam

# Include any dependencies generated for this target.
include menuItem/CMakeFiles/menuItem.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include menuItem/CMakeFiles/menuItem.dir/compiler_depend.make

# Include the progress variables for this target.
include menuItem/CMakeFiles/menuItem.dir/progress.make

# Include the compile flags for this target's objects.
include menuItem/CMakeFiles/menuItem.dir/flags.make

menuItem/CMakeFiles/menuItem.dir/menuItem.o: menuItem/CMakeFiles/menuItem.dir/flags.make
menuItem/CMakeFiles/menuItem.dir/menuItem.o: menuItem/menuItem.cpp
menuItem/CMakeFiles/menuItem.dir/menuItem.o: menuItem/CMakeFiles/menuItem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/biniam/cs202/projects/cs202_sp23_pa2-1204-Gashaw-Biniam/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object menuItem/CMakeFiles/menuItem.dir/menuItem.o"
	cd /Users/biniam/cs202/projects/cs202_sp23_pa2-1204-Gashaw-Biniam/menuItem && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT menuItem/CMakeFiles/menuItem.dir/menuItem.o -MF CMakeFiles/menuItem.dir/menuItem.o.d -o CMakeFiles/menuItem.dir/menuItem.o -c /Users/biniam/cs202/projects/cs202_sp23_pa2-1204-Gashaw-Biniam/menuItem/menuItem.cpp

menuItem/CMakeFiles/menuItem.dir/menuItem.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/menuItem.dir/menuItem.i"
	cd /Users/biniam/cs202/projects/cs202_sp23_pa2-1204-Gashaw-Biniam/menuItem && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/biniam/cs202/projects/cs202_sp23_pa2-1204-Gashaw-Biniam/menuItem/menuItem.cpp > CMakeFiles/menuItem.dir/menuItem.i

menuItem/CMakeFiles/menuItem.dir/menuItem.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/menuItem.dir/menuItem.s"
	cd /Users/biniam/cs202/projects/cs202_sp23_pa2-1204-Gashaw-Biniam/menuItem && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/biniam/cs202/projects/cs202_sp23_pa2-1204-Gashaw-Biniam/menuItem/menuItem.cpp -o CMakeFiles/menuItem.dir/menuItem.s

# Object files for target menuItem
menuItem_OBJECTS = \
"CMakeFiles/menuItem.dir/menuItem.o"

# External object files for target menuItem
menuItem_EXTERNAL_OBJECTS =

menuItem/libmenuItem.a: menuItem/CMakeFiles/menuItem.dir/menuItem.o
menuItem/libmenuItem.a: menuItem/CMakeFiles/menuItem.dir/build.make
menuItem/libmenuItem.a: menuItem/CMakeFiles/menuItem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/biniam/cs202/projects/cs202_sp23_pa2-1204-Gashaw-Biniam/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmenuItem.a"
	cd /Users/biniam/cs202/projects/cs202_sp23_pa2-1204-Gashaw-Biniam/menuItem && $(CMAKE_COMMAND) -P CMakeFiles/menuItem.dir/cmake_clean_target.cmake
	cd /Users/biniam/cs202/projects/cs202_sp23_pa2-1204-Gashaw-Biniam/menuItem && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/menuItem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
menuItem/CMakeFiles/menuItem.dir/build: menuItem/libmenuItem.a
.PHONY : menuItem/CMakeFiles/menuItem.dir/build

menuItem/CMakeFiles/menuItem.dir/clean:
	cd /Users/biniam/cs202/projects/cs202_sp23_pa2-1204-Gashaw-Biniam/menuItem && $(CMAKE_COMMAND) -P CMakeFiles/menuItem.dir/cmake_clean.cmake
.PHONY : menuItem/CMakeFiles/menuItem.dir/clean

menuItem/CMakeFiles/menuItem.dir/depend:
	cd /Users/biniam/cs202/projects/cs202_sp23_pa2-1204-Gashaw-Biniam && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/biniam/cs202/projects/cs202_sp23_pa2-1204-Gashaw-Biniam /Users/biniam/cs202/projects/cs202_sp23_pa2-1204-Gashaw-Biniam/menuItem /Users/biniam/cs202/projects/cs202_sp23_pa2-1204-Gashaw-Biniam /Users/biniam/cs202/projects/cs202_sp23_pa2-1204-Gashaw-Biniam/menuItem /Users/biniam/cs202/projects/cs202_sp23_pa2-1204-Gashaw-Biniam/menuItem/CMakeFiles/menuItem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : menuItem/CMakeFiles/menuItem.dir/depend

