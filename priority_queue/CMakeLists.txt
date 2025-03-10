include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/data)
add_executable(one ${CMAKE_CURRENT_SOURCE_DIR}/data/one/code.cpp)
add_executable(two ${CMAKE_CURRENT_SOURCE_DIR}/data/two/code.cpp)
add_executable(three ${CMAKE_CURRENT_SOURCE_DIR}/data/three/code.cpp)
add_executable(four ${CMAKE_CURRENT_SOURCE_DIR}/data/four/code.cpp)
add_executable(five ${CMAKE_CURRENT_SOURCE_DIR}/data/five/code.cpp)
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