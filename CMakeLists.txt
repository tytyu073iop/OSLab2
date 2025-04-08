# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 4.0)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("OSLab2")

set(CMAKE_CXX_STANDARD 98)



add_library(addons src/interface.cpp src/comunication.cpp)
target_include_directories(addons PUBLIC ${CMAKE_SOURCE_DIR}/include)



# Включите подпроекты.
add_executable(Main src/main.cpp)
target_link_libraries(Main addons)

add_subdirectory(tests/interface)



# set(BOOST_ROOT "C:\\Program Files\\boost\\boost_1_87_0\\tools\\boost_install")
# set(Boost_DIR "C:\\Program\ Files\\boost\\boost_1_87_0")
# set(Boost_DIR "C:\\Program Files\\boost\\boost_1_87_0\\tools\\cmake\\config")
# set(Boost_DIR "C:\\Program Files\\boost\\boost_1_87_0\\tools\\boost_install")


# sets install default path to current repository
set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}")
set(BIN_PATH bin)

install(TARGETS DESTINATION ${BIN_PATH}) # P.S. install dir do not work