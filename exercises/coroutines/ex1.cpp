#include <concepts>
#include <coroutine>
#include <exception>
#include <iostream>

namespace
{
static uint32_t ctr = 0;

struct ReturnObject
{
  struct promise_type
  {
    ReturnObject get_return_object()
    {
      return {std::coroutine_handle<promise_type>::from_promise(*this)};
    }
    
    std::suspend_never initial_suspend() { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }
    void unhandled_exception() {}

    auto getHandle()
    {
      return std::coroutine_handle<promise_type>::from_promise(*this);
    }
  };
      
  std::coroutine_handle<> h_;

  ReturnObject(std::coroutine_handle<> h):h_{h}{ }

  operator std::coroutine_handle<>() const { return h_; }
};


//coroutine
ReturnObject foo()
{
  std::cout << ++ctr << ". hello from coroutine\n";
  co_await std::suspend_always{};
  std::cout << ++ctr << ". hello from coroutine\n";
  co_await std::suspend_always{};
  std::cout << ++ctr << ". hello from coroutine\n";
}

/**
 * - Change the number of resumes, what happens?
 * - Add your won co_await calls with suspend_always and suspend_never, what happens
 * - Remove a resume, what happens?
 * - Change the initial_suspend function to return suspend_always
 *   What changes?
 * - Can you write a while loop that runs the coroutine till the end?
 *   What happened?
 *   Does changing the 'final_suspend' make any difference?
 *   Can you explain what is going on?
 * - To understand what's going on add a constructor and destructor to the promise_type
 *   Add a trace to those functions
 *   Do you see the expected construct and destruct?
 *   What if you after the while loop called destroy on the handle?
 */
void test_1()
{
  std::coroutine_handle<> h =  foo();
  std::cout << ++ctr << ". resuming coroutine from main\n";
  h();
  std::cout << ++ctr << ". resuming coroutine from main\n";
  h.resume(); //same as h()
}

}

void coroutines_ex1()
{
  std::cout << "coroutines_ex1" << std::endl;
  test_1();
}
