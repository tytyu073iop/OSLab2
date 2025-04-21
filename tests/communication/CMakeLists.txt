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

add_executable(communication_test comm.cpp)
target_link_libraries(communication_test addons)
target_link_libraries(communication_test GTest::gtest_main)
set_property(TARGET communication_test PROPERTY CXX_STANDARD 14)

include(GoogleTest)
gtest_discover_tests(communication_test)