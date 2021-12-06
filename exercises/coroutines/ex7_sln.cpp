#include <cppcoro/single_consumer_event.hpp>
#include <cppcoro/generator.hpp>
#include <cppcoro/task.hpp>
#include <cppcoro/sync_wait.hpp>
#include <cppcoro/when_all.hpp>

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <global.h>

namespace
{

cppcoro::single_consumer_event event;

cppcoro::task<> f1()
{
  std::cout << "start f1\n";
  co_await event;
  std::cout << "end f1\n";
}

cppcoro::task<> f2()
{
  std::cout << "start f2\n";
  co_await f1();
  std::cout << "end f2\n";
}

void producer()
{
  using namespace std::chrono_literals;
  std::this_thread::sleep_for(1s);
  std::cout << "producer set\n";
  event.set();
}


/**
 * tasks can wait on other tasks
 * 1) create a coroutine "f2" that waits on another coroutine "f1"
 * 2) let task "f1" wait for a "single_consumer_event"
 * 3) in test_1 instantiate task f2
 * 4) spawn a thread that set the event that "f1" is waiting for
 * 5) wait for "f2" to complete
 * 
 * Add some traces before and after the co_await in "f1" and "f2"
 * Add some traces in test_1
 * What order do you see?
 * On what threads did the code run?
 */
void test_1()
{
  std::cout << "test_1\n";
  auto h = f2();
  std::cout << "h created\n";
  std::thread t([](){ producer(); });
  t.detach();
  std::cout << "before sync wait\n";
  cppcoro::sync_wait(h);
  std::cout << "after sync wait\n";
  std::cout << std::endl;
}

}

void coroutines_ex7()
{    
  std::cout << "coroutines_ex7" << std::endl;
  test_1();  
}

