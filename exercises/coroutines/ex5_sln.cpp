
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

cppcoro::generator<const std::string> file(const std::string filename)
{
  std::string line;
  std::ifstream myfile(filename);
  if (myfile.is_open())
  {
    while (getline(myfile,line))
    {
      co_yield line;
    }
    myfile.close();
  }
  else
  {
    std::cerr << "Unable to open file " << filename << std::endl;
  }
}

/**
 * Convert the coroutine from ex4.cpp to cppcoro
 * https://github.com/MTDEVGIT/cppcoro
 */
void test_1()
{
  size_t count = 0;
  for (const auto &line : file("../coroutines/names.txt"))
  {
    (void)line;
    count++;
  }
  ASSERT(count == 100);
}

}

void coroutines_ex5()
{    
  std::cout << "coroutines_ex5" << std::endl;
  test_1();  
}

