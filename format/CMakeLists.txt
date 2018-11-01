cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(test_boost_format LANGUAGES CXX)

find_package(Boost 1.64.0 REQUIRED 
#COMPONENTS 

)
if(Boost_FOUND)											
	message(STATUS "<> '${Boost_INCLUDE_DIRS}'") 
	message(STATUS "<> '${Boost_LIBRARY_DIRS}'") 
	message(STATUS "<> '${Boost_LIBRARIES}'")
endif()

add_executable(format format.cpp)
set_target_properties(format
PROPERTIES
	CXX_STANDARD 17
	CXX_EXTENSIONS OFF
	CXX_STANDARD_REQUIRED ON	
	POSITION_INDEPENDENT_CODE 1
)
target_link_libraries(format 
PUBLIC
	Boost::boost
)
