cmake_minimum_required(VERSION 3.4.3)

project (finesse_interest_calc)
find_package(Threads)
enable_testing()

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" . WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
execute_process(COMMAND ${CMAKE_COMMAND} --build . WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)

set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src ${CMAKE_BINARY_DIR}/googletest-build)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/lib)

include_directories("${CMAKE_SOURCE_DIR}/src/lib/include")

file(GLOB SOURCE "src/*.cc")
file(GLOB TEST "test/*.cc")

message("${CMAKE_SOURCE_DIR}/src/lib/include")
add_executable(interest_calc ${SOURCE})
target_link_libraries(interest_calc interest_calc_lib)

add_executable(interest_calc_test ${TEST})
target_link_libraries(interest_calc_test interest_calc_lib)

set_target_properties(interest_calc PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(interest_calc_test PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(interest_calc_lib PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(interest_calc_test gtest)
target_link_libraries(interest_calc_test gtest_main)

if(EXISTS ${CMAKE_BINARY_DIR}/compile_commands.json)
  execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR}/compile_commands.json)
endif()
