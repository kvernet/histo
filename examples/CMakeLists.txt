cmake_minimum_required(VERSION 3.25.1)
project(Examples)

function(add_example_executable name)
	add_executable(${name} ${name}.cpp)
	target_link_libraries(${name} Histo)
	install(TARGETS ${name} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
endfunction()

# add examples
add_example_executable(exampleHisto1D)
add_example_executable(exampleHisto2D)
add_example_executable(exampleHisto3D)
