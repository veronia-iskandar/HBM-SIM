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

# Include any dependencies generated for this target.
include extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/compiler_depend.make

# Include the progress variables for this target.
include extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/progress.make

# Include the compile flags for this target's objects.
include extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/flags.make

extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/main.cpp.o: extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/flags.make
extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/main.cpp.o: extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/main.cpp
extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/main.cpp.o: extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veronia/toHector/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/main.cpp.o"
	cd /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/main.cpp.o -MF CMakeFiles/fft_fxpt.dir/main.cpp.o.d -o CMakeFiles/fft_fxpt.dir/main.cpp.o -c /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/main.cpp

extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fft_fxpt.dir/main.cpp.i"
	cd /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/main.cpp > CMakeFiles/fft_fxpt.dir/main.cpp.i

extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fft_fxpt.dir/main.cpp.s"
	cd /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/main.cpp -o CMakeFiles/fft_fxpt.dir/main.cpp.s

extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/source.cpp.o: extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/flags.make
extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/source.cpp.o: extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/source.cpp
extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/source.cpp.o: extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veronia/toHector/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/source.cpp.o"
	cd /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/source.cpp.o -MF CMakeFiles/fft_fxpt.dir/source.cpp.o.d -o CMakeFiles/fft_fxpt.dir/source.cpp.o -c /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/source.cpp

extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fft_fxpt.dir/source.cpp.i"
	cd /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/source.cpp > CMakeFiles/fft_fxpt.dir/source.cpp.i

extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fft_fxpt.dir/source.cpp.s"
	cd /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/source.cpp -o CMakeFiles/fft_fxpt.dir/source.cpp.s

extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/fft.cpp.o: extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/flags.make
extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/fft.cpp.o: extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/fft.cpp
extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/fft.cpp.o: extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veronia/toHector/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/fft.cpp.o"
	cd /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/fft.cpp.o -MF CMakeFiles/fft_fxpt.dir/fft.cpp.o.d -o CMakeFiles/fft_fxpt.dir/fft.cpp.o -c /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/fft.cpp

extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/fft.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fft_fxpt.dir/fft.cpp.i"
	cd /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/fft.cpp > CMakeFiles/fft_fxpt.dir/fft.cpp.i

extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/fft.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fft_fxpt.dir/fft.cpp.s"
	cd /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/fft.cpp -o CMakeFiles/fft_fxpt.dir/fft.cpp.s

extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/sink.cpp.o: extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/flags.make
extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/sink.cpp.o: extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/sink.cpp
extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/sink.cpp.o: extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veronia/toHector/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/sink.cpp.o"
	cd /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/sink.cpp.o -MF CMakeFiles/fft_fxpt.dir/sink.cpp.o.d -o CMakeFiles/fft_fxpt.dir/sink.cpp.o -c /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/sink.cpp

extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/sink.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fft_fxpt.dir/sink.cpp.i"
	cd /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/sink.cpp > CMakeFiles/fft_fxpt.dir/sink.cpp.i

extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/sink.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fft_fxpt.dir/sink.cpp.s"
	cd /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/sink.cpp -o CMakeFiles/fft_fxpt.dir/sink.cpp.s

# Object files for target fft_fxpt
fft_fxpt_OBJECTS = \
"CMakeFiles/fft_fxpt.dir/main.cpp.o" \
"CMakeFiles/fft_fxpt.dir/source.cpp.o" \
"CMakeFiles/fft_fxpt.dir/fft.cpp.o" \
"CMakeFiles/fft_fxpt.dir/sink.cpp.o"

# External object files for target fft_fxpt
fft_fxpt_EXTERNAL_OBJECTS =

extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/fft_fxpt: extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/main.cpp.o
extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/fft_fxpt: extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/source.cpp.o
extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/fft_fxpt: extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/fft.cpp.o
extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/fft_fxpt: extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/sink.cpp.o
extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/fft_fxpt: extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/build.make
extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/fft_fxpt: extern/dramSys/DRAMSys/library/src/common/third_party/systemc/src/libsystemc.a
extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/fft_fxpt: extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/veronia/toHector/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable fft_fxpt"
	cd /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fft_fxpt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/build: extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/fft_fxpt
.PHONY : extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/build

extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/clean:
	cd /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt && $(CMAKE_COMMAND) -P CMakeFiles/fft_fxpt.dir/cmake_clean.cmake
.PHONY : extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/clean

extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/depend:
	cd /home/veronia/toHector && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/veronia/toHector /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt /home/veronia/toHector /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : extern/dramSys/DRAMSys/library/src/common/third_party/systemc/examples/sysc/fft/fft_fxpt/CMakeFiles/fft_fxpt.dir/depend

