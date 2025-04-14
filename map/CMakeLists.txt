include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/data)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/corner_data)
add_executable(one ${CMAKE_CURRENT_SOURCE_DIR}/data/one/code.cpp)
add_executable(two ${CMAKE_CURRENT_SOURCE_DIR}/data/two/code.cpp)
add_executable(three ${CMAKE_CURRENT_SOURCE_DIR}/data/three/code.cpp)
add_executable(four ${CMAKE_CURRENT_SOURCE_DIR}/data/four/code.cpp)
add_executable(five ${CMAKE_CURRENT_SOURCE_DIR}/data/five/code.cpp)
add_executable(1 ${CMAKE_CURRENT_SOURCE_DIR}/corner_data/1.cpp)
add_executable(2 ${CMAKE_CURRENT_SOURCE_DIR}/corner_data/2.cpp)
add_executable(3 ${CMAKE_CURRENT_SOURCE_DIR}/corner_data/3.cpp)
add_test(NAME one COMMAND sh -c "${CMAKE_CURRENT_BINARY_DIR}/one >/tmp/one_out.txt\
        && diff -u ${CMAKE_CURRENT_SOURCE_DIR}/data/one/answer.txt /tmp/one_out.txt>/tmp/one_diff.txt")
add_test(NAME two COMMAND sh -c "${CMAKE_CURRENT_BINARY_DIR}/two >/tmp/two_out.txt\
        && diff -u ${CMAKE_CURRENT_SOURCE_DIR}/data/two/answer.txt /tmp/two_out.txt>/tmp/two_diff.txt")
add_test(NAME three COMMAND sh -c "${CMAKE_CURRENT_BINARY_DIR}/three >/tmp/three_out.txt\
        && diff -u ${CMAKE_CURRENT_SOURCE_DIR}/data/three/answer.txt /tmp/three_out.txt>/tmp/three_diff.txt")
add_test(NAME four COMMAND sh -c "${CMAKE_CURRENT_BINARY_DIR}/four >/tmp/four_out.txt\
        && diff -u ${CMAKE_CURRENT_SOURCE_DIR}/data/four/answer.txt /tmp/four_out.txt>/tmp/four_diff.txt")
add_test(NAME five COMMAND sh -c "${CMAKE_CURRENT_BINARY_DIR}/five >/tmp/five_out.txt\
        && diff -u ${CMAKE_CURRENT_SOURCE_DIR}/data/five/answer.txt /tmp/five_out.txt>/tmp/five_diff.txt")
add_test(NAME corner_data1 COMMAND sh -c "${CMAKE_CURRENT_BINARY_DIR}/1 >/tmp/1_out.txt\
        && diff -u ${CMAKE_CURRENT_SOURCE_DIR}/corner_data/1.ans /tmp/1_out.txt>/tmp/1_diff.txt")
add_test(NAME corner_data2 COMMAND sh -c "${CMAKE_CURRENT_BINARY_DIR}/2 >/tmp/2_out.txt\
        && diff -u ${CMAKE_CURRENT_SOURCE_DIR}/corner_data/2.ans /tmp/2_out.txt>/tmp/2_diff.txt")
add_test(NAME corner_data3 COMMAND sh -c "${CMAKE_CURRENT_BINARY_DIR}/3 >/tmp/3_out.txt\
        && diff -u ${CMAKE_CURRENT_SOURCE_DIR}/corner_data/3.ans /tmp/3_out.txt>/tmp/3_diff.txt")