cmake_minimum_required(VERSION 3.14)
project(oj-problem-solutions)

set(CMAKE_CXX_STANDARD 14)

add_executable(Solution leetcode/031.\ Next\ Permutation/Solution.cpp)

#[[
file( GLOB_RECURSE APP_SOURCES leetcode/*/*.c leetcode/*/*.cpp)
foreach( sourcefile ${APP_SOURCES} )
    file(RELATIVE_PATH relative "${CMAKE_CURRENT_SOURCE_DIR}" "${sourcefile}")
#     message(${relative})

    string(REGEX MATCH "/[0-9a-zA-Z]+.c(pp)?$" filename ${relative})
    string(REGEX REPLACE ".c(pp)?$" "" filename ${filename})
    string(REGEX REPLACE "[ /]" "" filename ${filename})
#    message(${filename})

    string( REGEX MATCH "[0-9]+(.*)?/" problem ${relative} )
    string( REGEX REPLACE "[ /]" "" problem ${problem} )
#    message(${problem})

    string(CONCAT fullname ${problem}; -; ${filename})
#    message(${fullname})

    add_executable( ${fullname} ${sourcefile} )
endforeach( sourcefile ${APP_SOURCES} )
]]
