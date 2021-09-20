#include <coroutine>
#include <iostream>
#include <optional>
#include <vector>
#include <fstream>
#include <global.h>

namespace
{

/**
 * Uncomment the generator below
 */
/*
template<typename T>
class Generator
{
public:
  struct promise_type
  {
    Generator<T> get_return_object()
    {
      return Generator{std::coroutine_handle<promise_type>::from_promise(*this)};
    }
    std::suspend_always initial_suspend() noexcept
    {
      return {}; 
    }
    std::suspend_always final_suspend() noexcept
    { 
      return {}; 
    }
    std::suspend_always yield_value(T value) noexcept
    {
      current_value = std::move(value);
      return {};
    }
    // Disallow co_await in generator coroutines.
    void await_transform() = delete;
    void unhandled_exception()
    {
      throw;
    }
 
    std::optional<T> current_value;
  };
 
  explicit Generator(const std::coroutine_handle<promise_type> coroutine)
    : m_coroutine{coroutine}
  {}
 
  Generator() = default;
  ~Generator()
  { 
    if (m_coroutine)
    {
      m_coroutine.destroy(); 
    }
  }
 
  Generator(const Generator&) = delete;
  Generator& operator=(const Generator&) = delete;
 
  Generator(Generator&& other) noexcept
    : m_coroutine{other.m_coroutine}
  { 
    other.m_coroutine = {}; 
  }
  Generator& operator=(Generator&& other) noexcept
  {
    if (this != &other)
    {
      if (m_coroutine)
      {
        m_coroutine.destroy();
      }
      m_coroutine = other.m_coroutine;
      other.m_coroutine = {};
    }
    return *this;
  }
 
  // Range-based for loop support.
  class Iter
  {
  public:
    void operator++()
    {
      m_coroutine.resume(); 
    }
    const T& operator*() const
    {
      return *m_coroutine.promise().current_value;
    }        
    bool operator==(std::default_sentinel_t) const
    {
      return !m_coroutine || m_coroutine.done(); 
    }
 
    explicit Iter(const std::coroutine_handle<promise_type> coroutine)
      : m_coroutine{coroutine}
    {}
 
  private:
    std::coroutine_handle<promise_type> m_coroutine;
  };
 
  Iter begin()
  {
    if (m_coroutine)
    {
      m_coroutine.resume();
    } 
    return Iter{m_coroutine};
  }
  std::default_sentinel_t end()
  {
    return {};
  }
 
private:
  std::coroutine_handle<promise_type> m_coroutine;
}; 
*/

/**
 * Given the generator from ex3.cpp
 * write a coroutine that reads a file and returns it line by line
 * You may need to change the filename path depending on where you build you executables
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

void coroutines_ex4()
{
  std::cout << "coroutines_ex4" << std::endl;
  test_1();
}

