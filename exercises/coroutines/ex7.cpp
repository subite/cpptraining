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
 *
 * Do you know how you could implement tasks waiting for other tasks?
 * Try to figure it out from the cppcoro code
 */
void test_1()
{
}

}

void coroutines_ex7()
{    
  std::cout << "coroutines_ex7" << std::endl;
  test_1();  
}

