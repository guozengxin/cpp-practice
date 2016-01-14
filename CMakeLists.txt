# 项目信息

# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.6)

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# 指定生成目标 
add_executable(t-string "string.cpp")

add_executable(fwrite "fwrite.cpp")

add_executable(fread "fread.cpp")

add_executable(mutable_member "mutable_member.cpp")

add_executable(initializer "initializer.cpp")

add_executable(bsearch "binary_search.cpp")

add_executable(print_array "print_array.cpp")

add_executable(calc "calculator.cpp")

add_executable(valist "valist.cpp")

add_executable(a "a.cpp")
