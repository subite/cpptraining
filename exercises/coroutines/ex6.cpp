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
 * 1) using cppcoro, write a task "consumer" that waits for an event to be set (use cppcoro::single_consumer_event)
      and prints how long it took for the event to complete.
 * 2) write a producer function that waits 1s and sets that event
 * 3) in test_1 instatntiate our task by calling our consumer() function
 * 4) spawn a thread that runs the producer function
 * 5) wait for the task to complete
 * 
 * Print on what thread the consumer started and on what thread it was resumed. Are they the same?
 * Modify your code to spawn more consumers (you will also need more single_consumer_event instances)
 * Spawn multiple producers our let the single producer set all the events
 * Wait for all the coroutines to finish.
 * On what thread did they run?
 * https://github.com/MTDEVGIT/cppcoro
 */
void test_1()
{
}

}

void coroutines_ex6()
{    
  std::cout << "coroutines_ex6" << std::endl;
  test_1();  
}

