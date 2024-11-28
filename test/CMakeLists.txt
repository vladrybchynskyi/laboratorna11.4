cmake_minimum_required(VERSION 3.30.5)

set(This labor11_4test)

set(Sources
   labor11_4test.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    laborw11_4
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
