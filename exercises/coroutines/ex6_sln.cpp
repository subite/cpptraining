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

std::array<cppcoro::single_consumer_event, 10> events;

cppcoro::task<> consumer(size_t i)
{
  auto start = std::chrono::high_resolution_clock::now();
  co_await events[i];  // suspended until some thread calls event.set()
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  std::cout << "Consumer " << i << " waited for " << elapsed.count() << " seconds." << std::endl;
}

void producer(size_t i)
{
  using namespace std::chrono_literals;
  std::this_thread::sleep_for(1s);
  events[i].set();  // resumes the consumer  
}

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
  std::cout << std::endl;
  std::vector<cppcoro::task<> > tasks;
  for (size_t i = 0; i < events.size(); ++i)
  {
    tasks.emplace_back(consumer(i));
  }

  for (size_t i = 0; i < events.size(); ++i)
  {
    std::thread t([i](){ producer(i); });
    t.detach();
  }
  cppcoro::sync_wait(cppcoro::when_all(std::move(tasks)));
  std::cout << std::endl;
}

}

void coroutines_ex6()
{    
  std::cout << "coroutines_ex6" << std::endl;
  test_1();  
}

