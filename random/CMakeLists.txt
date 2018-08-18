project(Boost_random)

cmake_minimum_required(VERSION 2.8)

set(Boost_INCLUDE_DIR "c:/mingw/boost32/include/boost-1_64/")	# Directory containing Boost headers (32bit)
set(Boost_LIBRARY_DIR "c:/mingw/boost32/lib/") 					# Default value for Boost_LIBRARY_DIR_RELEASE and Boost_LIBRARY_DIR_DEBUG.

set( Boost_USE_STATIC_LIBS ON ) # !uses .a files, NOT .dll's
set( Boost_USE_MULTITHREADED ON ) # Set to OFF to use the non-multithreaded libraries ('mt' tag).  Default is ON.

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -pedantic -fdiagnostics-show-option -O2 -static-libgcc -static-libstdc++ -static -lpthread") 

find_package( Boost 1.64.0 REQUIRED QUIET 
			COMPONENTS random system )				#  Boost libraries by their canonical name
	
if(Boost_FOUND)										
	message(STATUS "<> [${PROJECT_NAME}]")
	message(STATUS "<> '${Boost_INCLUDE_DIRS}'") 
	message(STATUS "<> '${Boost_LIBRARY_DIRS}'") 
	message(STATUS "<>  ${Boost_LIBRARIES}")
	
	include_directories(${Boost_INCLUDE_DIRS}) 		
	add_executable(${PROJECT_NAME} random.cpp)
	target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()

