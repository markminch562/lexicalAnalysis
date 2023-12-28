cmake_minimum_required(VERSION 3.21)
project(Parsing_Analysis_Tests)
set(CMAKE_CXX_STANDARD 17)

#[[
set(current_dir ${CMAKE_CURRENT_LIST_DIR})
add_executable(test_byte test_script/file_write_byte.cpp)
add_test(NAME basic_test COMMAND test_byte
        ${current_dir}/sample_text byte_write.bin)

add_executable(test_string tests/stringTest.cpp)
target_link_libraries(test_string parsing)

add_test(NAME StringTest COMMAND test_string)
]]#

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.8.1
)
FetchContent_MakeAvailable(googletest)


add_executable(
        hello_test
        test_script/file_write_byte.cpp
)

target_link_libraries(
        hello_test PUBLIC
        parsing
        gtest_main
)

include(GoogleTest)

add_test(NAME AllocatorTest COMMAND hello_test)


