cmake_minimum_required(VERSION 4.0)
project(TestMinMax)

set(CXX_STANDARD 14)
set(CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()



add_executable(min_max_test min_max.cpp)

target_link_libraries(min_max_test addons)

# kolhoz
include_directories(${CMAKE_SOURCE_DIR}/include)

target_link_libraries(min_max_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(min_max_test)