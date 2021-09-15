cmake_minimum_required(VERSION 3.0)

project(cpptraining)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(common)

find_package (Threads REQUIRED)

set(COMMON_SOURCES common/global.cpp)


set(MOVE_SOURCES move/main.cpp move/ex1.cpp move/ex2.cpp move/ex3.cpp move/ex4.cpp move/ex5.cpp move/ex6.cpp)
add_executable(move ${COMMON_SOURCES} ${MOVE_SOURCES})
target_compile_options(move PRIVATE -Wall -Wextra -Wpedantic -Wno-range-loop-construct)

set(LAMBDA_SOURCES lambda/main.cpp lambda/ex1.cpp lambda/ex2.cpp lambda/ex3.cpp)
add_executable(lambda ${COMMON_SOURCES} ${LAMBDA_SOURCES})
target_compile_options(lambda PRIVATE -Wall -Wextra -Wpedantic)

set(SMALL_SOURCES small/main.cpp small/ex1.cpp small/ex2.cpp)
add_executable(small ${COMMON_SOURCES} ${SMALL_SOURCES})
target_compile_options(small PRIVATE -Wall -Wextra -Wpedantic)

set(TYPE_SOURCES type_safe/main.cpp type_safe/ex1.cpp type_safe/ex2.cpp type_safe/ex3.cpp type_safe/ex4.cpp)
add_executable(type_safe ${COMMON_SOURCES} ${TYPE_SOURCES})
target_compile_options(type_safe PRIVATE -Wall -Wextra -Wpedantic)
target_link_libraries(type_safe ${CMAKE_THREAD_LIBS_INIT} )
