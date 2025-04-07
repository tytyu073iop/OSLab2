cmake_minimum_required (VERSION 4.0)

project(Main)

add_executable(Main main.cpp comunication.cpp interface.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include)

# message(STATUS ${CMAKE_SOURCE_DIR})

#find_package(Boost REQUIRED COMPONENTS lambda)

# message(STATUS "Boost Include Dirs: ${Boost_INCLUDE_DIRS}")
# message(STATUS "Boost Libraries: ${Boost_LIBRARIES}")

#target_link_libraries(Main PUBLIC Boost::lambda)
#target_include_directories(Main PUBLIC "${PROJECT_BINARY_DIR}" "${}")