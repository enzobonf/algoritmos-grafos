# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/main.cpp.obj: main.cpp
CMakeFiles/main.dir/main.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/main.cpp.obj"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/main.cpp.obj -MF CMakeFiles\main.dir\main.cpp.obj.d -o CMakeFiles\main.dir\main.cpp.obj -c C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos\main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos\main.cpp > CMakeFiles\main.dir\main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos\main.cpp -o CMakeFiles\main.dir\main.cpp.s

CMakeFiles/main.dir/grafo.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/grafo.cpp.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/grafo.cpp.obj: grafo.cpp
CMakeFiles/main.dir/grafo.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/grafo.cpp.obj"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/grafo.cpp.obj -MF CMakeFiles\main.dir\grafo.cpp.obj.d -o CMakeFiles\main.dir\grafo.cpp.obj -c C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos\grafo.cpp

CMakeFiles/main.dir/grafo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/grafo.cpp.i"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos\grafo.cpp > CMakeFiles\main.dir\grafo.cpp.i

CMakeFiles/main.dir/grafo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/grafo.cpp.s"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos\grafo.cpp -o CMakeFiles\main.dir\grafo.cpp.s

CMakeFiles/main.dir/algoritmos.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/algoritmos.cpp.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/algoritmos.cpp.obj: algoritmos.cpp
CMakeFiles/main.dir/algoritmos.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/algoritmos.cpp.obj"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/algoritmos.cpp.obj -MF CMakeFiles\main.dir\algoritmos.cpp.obj.d -o CMakeFiles\main.dir\algoritmos.cpp.obj -c C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos\algoritmos.cpp

CMakeFiles/main.dir/algoritmos.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/algoritmos.cpp.i"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos\algoritmos.cpp > CMakeFiles\main.dir\algoritmos.cpp.i

CMakeFiles/main.dir/algoritmos.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/algoritmos.cpp.s"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos\algoritmos.cpp -o CMakeFiles\main.dir\algoritmos.cpp.s

CMakeFiles/main.dir/arquivo.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/arquivo.cpp.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/arquivo.cpp.obj: arquivo.cpp
CMakeFiles/main.dir/arquivo.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/arquivo.cpp.obj"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/arquivo.cpp.obj -MF CMakeFiles\main.dir\arquivo.cpp.obj.d -o CMakeFiles\main.dir\arquivo.cpp.obj -c C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos\arquivo.cpp

CMakeFiles/main.dir/arquivo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/arquivo.cpp.i"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos\arquivo.cpp > CMakeFiles\main.dir\arquivo.cpp.i

CMakeFiles/main.dir/arquivo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/arquivo.cpp.s"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos\arquivo.cpp -o CMakeFiles\main.dir\arquivo.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.obj" \
"CMakeFiles/main.dir/grafo.cpp.obj" \
"CMakeFiles/main.dir/algoritmos.cpp.obj" \
"CMakeFiles/main.dir/arquivo.cpp.obj"

# External object files for target main
main_EXTERNAL_OBJECTS =

main.exe: CMakeFiles/main.dir/main.cpp.obj
main.exe: CMakeFiles/main.dir/grafo.cpp.obj
main.exe: CMakeFiles/main.dir/algoritmos.cpp.obj
main.exe: CMakeFiles/main.dir/arquivo.cpp.obj
main.exe: CMakeFiles/main.dir/build.make
main.exe: C:/Program\ Files\ (x86)/Graphviz/lib/gvc.lib
main.exe: C:/Program\ Files\ (x86)/Graphviz/lib/cgraph.lib
main.exe: CMakeFiles/main.dir/linkLibs.rsp
main.exe: CMakeFiles/main.dir/objects1.rsp
main.exe: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable main.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main.exe
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\main.dir\cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos C:\Users\enzob\OneDrive\Documentos\Projetos\PAA\algoritmos-grafos\CMakeFiles\main.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

