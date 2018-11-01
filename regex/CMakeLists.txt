cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(boost_regex LANGUAGES CXX)

find_package(Boost 1.64.0 REQUIRED 
COMPONENTS 
	regex
)
list(APPEND examples
	regex.cpp
	regex_match.cpp
	regex_search.cpp
	regex_token_iterator.cpp
)
foreach(_source IN LISTS examples)
	get_filename_component(exe_name ${_source} NAME_WE )
	add_executable(${exe_name} ${_source})
	set_target_properties(${exe_name}
	PROPERTIES
		CXX_STANDARD 17
		CXX_EXTENSIONS OFF
		CXX_STANDARD_REQUIRED ON	
		POSITION_INDEPENDENT_CODE 1
	)
	target_link_libraries(${exe_name} 
	PUBLIC
		Boost::boost
		Boost::regex
	)
endforeach()