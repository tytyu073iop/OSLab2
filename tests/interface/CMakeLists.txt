# GoogleTest requires at least C++14

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

#test
enable_testing()

add_executable(min_max_test min_max.cpp)
target_link_libraries(min_max_test addons)
target_link_libraries(min_max_test GTest::gtest_main)
set_property(TARGET min_max_test PROPERTY CXX_STANDARD 14)

add_executable(avg_test avg.cpp)
target_link_libraries(avg_test addons)
target_link_libraries(avg_test GTest::gtest_main)
set_property(TARGET avg_test PROPERTY CXX_STANDARD 14)

include(GoogleTest)
gtest_discover_tests(min_max_test)
gtest_discover_tests(avg_test)