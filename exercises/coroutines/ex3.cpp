#include <coroutine>
#include <iostream>
#include <optional>
#include <vector>

namespace
{
/**
 * Uncomment the generator class below
 * Implement the "???" so test_1 works
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
      return ???;
    }
    ??? initial_suspend() noexcept
    {
      return {};
    }
    ??? final_suspend() noexcept
    {
      return {};
    }
    ??? yield_value(T value) noexcept
    {
      current_value = std::move(value);
      return {};
    }
    // Disallow co_await in generator coroutines.
    void await_transform() = delete;
    void unhandled_exception() { throw; }
 
    std::optional<T> current_value;
  };
 
  explicit Generator(???)
    : ???
  {}
 
  Generator() = default;
  ~Generator()
  {
    ???
  }
 
  Generator(const Generator&) = delete;
  Generator& operator=(const Generator&) = delete;
 
  Generator(Generator&& other) noexcept
    : ???
  {
  }
    
  Generator& operator=(Generator&& other) noexcept
  {
    if (this != &other)
    {
      ???
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
 
    explicit Iter(const Handle coroutine)
      : m_coroutine{coroutine}
    {}
 
    private:
      Handle m_coroutine;
  };
 
  Iter begin()
  {
    if (m_coroutine)
    {
      m_coroutine.resume();
    } 
    return Iter{m_coroutine};
  }
  std::default_sentinel_t end() { 
    return {}; 
  }
 
private:
  Handle m_coroutine;
};
 
template<typename T>
Generator<T> range(T first, const T last)
{
  while (first < last)
  {
    co_yield first++;
  }
}

*/

/**
 * Uncomment the code in test_1, implement Genertator further
 * So the following code prints
 * 0123456789
 * ABCDEFGHIJKLMNOPQRSTUVWXYZ
 * 012345
 */
void test_1()
{
/*
  for (int i : range(0, 10))
    std::cout << i;
  std::cout << '\n';
  for (char i : range(65, 91))
    std::cout << i;
  std::cout << '\n';
  std::vector<int> v = {0, 1, 2, 3, 4, 5};
  for (auto i : range(v.begin(), v.end()))
    std::cout << *i;
  std::cout << '\n';
*/
}

}

void coroutines_ex3()
{
  std::cout << "coroutines_ex3" << std::endl;
  test_1();
}

