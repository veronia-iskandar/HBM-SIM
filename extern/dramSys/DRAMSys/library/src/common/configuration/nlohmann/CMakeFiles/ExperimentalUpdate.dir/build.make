# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/veronia/toHector

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/veronia/toHector

# Utility rule file for ExperimentalUpdate.

# Include any custom commands dependencies for this target.
include extern/dramSys/DRAMSys/library/src/common/configuration/nlohmann/CMakeFiles/ExperimentalUpdate.dir/compiler_depend.make

# Include the progress variables for this target.
include extern/dramSys/DRAMSys/library/src/common/configuration/nlohmann/CMakeFiles/ExperimentalUpdate.dir/progress.make

extern/dramSys/DRAMSys/library/src/common/configuration/nlohmann/CMakeFiles/ExperimentalUpdate:
	cd /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/configuration/nlohmann && /usr/local/bin/ctest -D ExperimentalUpdate

ExperimentalUpdate: extern/dramSys/DRAMSys/library/src/common/configuration/nlohmann/CMakeFiles/ExperimentalUpdate
ExperimentalUpdate: extern/dramSys/DRAMSys/library/src/common/configuration/nlohmann/CMakeFiles/ExperimentalUpdate.dir/build.make
.PHONY : ExperimentalUpdate

# Rule to build all files generated by this target.
extern/dramSys/DRAMSys/library/src/common/configuration/nlohmann/CMakeFiles/ExperimentalUpdate.dir/build: ExperimentalUpdate
.PHONY : extern/dramSys/DRAMSys/library/src/common/configuration/nlohmann/CMakeFiles/ExperimentalUpdate.dir/build

extern/dramSys/DRAMSys/library/src/common/configuration/nlohmann/CMakeFiles/ExperimentalUpdate.dir/clean:
	cd /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/configuration/nlohmann && $(CMAKE_COMMAND) -P CMakeFiles/ExperimentalUpdate.dir/cmake_clean.cmake
.PHONY : extern/dramSys/DRAMSys/library/src/common/configuration/nlohmann/CMakeFiles/ExperimentalUpdate.dir/clean

extern/dramSys/DRAMSys/library/src/common/configuration/nlohmann/CMakeFiles/ExperimentalUpdate.dir/depend:
	cd /home/veronia/toHector && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/veronia/toHector /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/nlohmann /home/veronia/toHector /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/configuration/nlohmann /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/configuration/nlohmann/CMakeFiles/ExperimentalUpdate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : extern/dramSys/DRAMSys/library/src/common/configuration/nlohmann/CMakeFiles/ExperimentalUpdate.dir/depend

