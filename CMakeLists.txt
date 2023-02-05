cmake_minimum_required(VERSION 3.25.1)
project(Histo)

# set flags for errors and warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -pedantic-errors -Wall -Wextra")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

option(HISTO_BUILD_EXAMPLES "Build the histo example" OFF)

file(GLOB srcs ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB headers ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

# create a shared library
add_library(${PROJECT_NAME} SHARED ${srcs} ${headers})
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)

if(HISTO_BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include DESTINATION ${CMAKE_INSTALL_PREFIX})
