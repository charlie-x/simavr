cmake_minimum_required(VERSION 3.10)

# Project name and version (derived from Makefile variables)
project(simavr VERSION 1.0)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type (default Release)" FORCE)
endif()

#/System/Volumes/Data/opt/homebrew/Cellar/libelf/0.8.13_1/include/

if(APPLE)
message("APPLE Build")
set(CMAKE_C_FLAGS "-funsigned-char -DHAVE_LIBELF -I/System/Volumes/Data/opt/homebrew/Cellar/libelf/0.8.13_1/include/ -I/System/Volumes/Data/opt/homebrew/Cellar/libelf/0.8.13_1/include/libelf/ -L/System/Volumes/Data/opt/homebrew/Cellar/libelf/0.8.13_1/lib/ -lelf")
set(CMAKE_C_FLAGS_RELEASE "-mtune=generic -O2 -Wall -pedantic -mstackrealign -flto -fomit-frame-pointer -DNDEBUG -Wno-unknown-pragmas -fexceptions -fstack-clash-protection")
set(CMAKE_CXX_FLAGS_RELEASE "-mtune=generic -O2 -Wall -pedantic -mstackrealign -flto -fomit-frame-pointer -DNDEBUG -Wno-unknown-pragmas -fexceptions -fstack-clash-protection")

set(CMAKE_CXX_FLAGS "-funsigned-char -DHAVE_LIBELF")

else()

set(CMAKE_C_FLAGS "-funsigned-char -static-libgcc -DCONFIG_SIMAVR_TRACE=1" )
set(CMAKE_C_FLAGS_RELEASE "-mtune=native -O2 -ftree-loop-vectorize -Wall -pedantic -mstackrealign -flto -fomit-frame-pointer -DNDEBUG -fcf-protection -Wno-unknown-pragmas -fexceptions -fstack-clash-protection -fpie -Wl,-pie -Wl,-z,relro -Wl,-z,defs -Wl,-z,now")
set(CMAKE_CXX_FLAGS_RELEASE "-mtune=native -O2 -ftree-loop-vectorize -Wall -pedantic -mstackrealign -flto -fomit-frame-pointer -DNDEBUG -fcf-protection -Wno-unknown-pragmas -fexceptions -fstack-clash-protection -fpie -Wl,-z,relro -Wl,-z,defs -Wl,-z,now ")

set(CMAKE_CXX_FLAGS "-funsigned-char -static-libgcc -static-libstdc++ -DCONFIG_SIMAVR_TRACE=1")

endif()

set(CMAKE_C_FLAGS_DEBUG "-O0 -ggdb -fasynchronous-unwind-tables")

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb -fasynchronous-unwind-tables")

message(CMAKE_BUILD_TYPE="${CMAKE_BUILD_TYPE}")

# Include directories
include_directories(sim)
include_directories(.)
include_directories(cores)

# Source files (derived from 'sim' variable in Makefile)
file(GLOB_RECURSE SIM_SOURCES "sim/sim_*.c" "sim/avr_*.c")

# Additional sources from 'cores' directory
file(GLOB CORES_SOURCES "cores/*.c")

# Create static library 'libsimavr'
add_library(simavr STATIC ${SIM_SOURCES} ${CORES_SOURCES})

# Target 'run_avr' (exact source files and dependencies need to be defined)
add_executable(run_avr ${SIM_SOURCES} ${CORES_SOURCES}  sim/run_avr.c)
target_link_libraries(run_avr simavr)

# Installation rules (need to be adjusted based on Makefile's install commands)
install(TARGETS run_avr simavr
	RUNTIME DESTINATION bin
	ARCHIVE DESTINATION lib)

# Additional custom commands and configurations need to be added here

