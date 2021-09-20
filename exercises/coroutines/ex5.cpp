
#include <cppcoro/generator.hpp>
#include <cppcoro/task.hpp>
#include <cppcoro/sync_wait.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <global.h>

namespace
{

/**
 * Convert the coroutine from ex4.cpp to cppcoro
 * https://github.com/MTDEVGIT/cppcoro
 */
void test_1()
{
/*
  size_t count = 0;
  for (const auto &line : file("../coroutines/names.txt"))
  {
    (void)line;
    count++;
  }
  ASSERT(count == 100);
*/
}

}

void coroutines_ex5()
{    
  std::cout << "coroutines_ex5" << std::endl;
  test_1();  
}

