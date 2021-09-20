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

set(VALUES_SOURCES values/main.cpp values/ex1.cpp values/ex2.cpp values/ex3.cpp values/ex4.cpp values/ex5.cpp values/ex6.cpp)
add_executable(values ${COMMON_SOURCES} ${VALUES_SOURCES})
# target_compile_options(values PRIVATE -Wall -Wextra -Wpedantic)
target_link_libraries(values ${CMAKE_THREAD_LIBS_INIT} )

set(CPP_CORO_SOURCES common/lib/lightweight_manual_reset_event.cpp common/lib/async_auto_reset_event.cpp common/lib/async_manual_reset_event.cpp common/lib/async_mutex.cpp common/lib/auto_reset_event.cpp common/lib/cancellation_registration.cpp common/lib/cancellation_source.cpp common/lib/cancellation_state.cpp common/lib/cancellation_token.cpp common/lib/spin_mutex.cpp common/lib/spin_wait.cpp)

set(COROUTINES_SOURCES coroutines/main.cpp coroutines/ex1.cpp coroutines/ex2.cpp coroutines/ex3.cpp coroutines/ex4.cpp coroutines/ex5.cpp coroutines/ex6.cpp coroutines/ex7.cpp)
add_executable(coroutines ${COMMON_SOURCES} ${COROUTINES_SOURCES} ${CPP_CORO_SOURCES})
target_compile_options(coroutines PRIVATE -Wall -Wextra -Wpedantic)
target_link_libraries(coroutines ${CMAKE_THREAD_LIBS_INIT} )
