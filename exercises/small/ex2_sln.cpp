#include <global.h>

using namespace std::string_literals;

namespace
{

template<typename... Args>
auto sum(Args... args)
{
    return (args + ...);
}

/*
 * Create a function 'sum' that returns the sum of all it's parameters
 * and uncomment the following lines
 */
void test_1()
{
  ASSERT(sum(1, 2) == 3);
  ASSERT(sum(1.0, 2.0, 3.0) == 6.0);
  ASSERT(sum("a"s, "b"s, "c"s, "d"s) == "abcd"s);
}


template<typename... Args>
auto sum_doubler(Args... args)
{
  /*
   * why do we need a temporary variable?
   * What happens if we try:
   *   sum(args ...) + sum(std::forward<Args>(args) ...)
   * What is the order of operations?
   */
  auto tmp = sum(args ...);
  return std::move(tmp) + sum(std::forward<Args>(args) ...);
}

/**
 * Now write a function 'sum_doubler' that doubles the sum function
 * Forward the arguments to the sum function
 */
void test_2()
{
  ASSERT(sum_doubler(1, 2) == 6);
  ASSERT(sum_doubler(1.0, 2.0, 3.0) == 12.0);
  ASSERT(sum_doubler("a"s, "b"s, "c"s, "d"s) == "abcdabcd"s);
}


template<typename T, typename... Args>
void push_back_vec(std::vector<T>& v, Args&&... args)
{
  (v.push_back(std::forward<Args>(args)), ...);
}

/*
 * Create a function 'push_back_vec' that takes a vector as first argument
 * and pushes all remaining all arguments to that vector
 * HINT: use the ',' operator
 */
void test_3()
{
  std::vector<int> v1;
  push_back_vec(v1, 6, 2, 45, 12);
  push_back_vec(v1, 1, 2, 9);
  ASSERT(v1[0] == 6);
  ASSERT(v1[6] == 9);
  
  std::vector<std::string> v2;
  std::string a = "a";
  push_back_vec(v2, std::move(a), "b");
  ASSERT(v2[0] == "a");
  ASSERT(v2[1] == "b");
}


template<typename... Ts>
class Overloader : public Ts...
{
public:
  template<typename... Fs>
  Overloader(Fs&& ... fs)
    : Ts(std::forward<Fs>(fs))...
  {}
  using Ts::operator()...;
};

template<typename... Ts>
auto overload(Ts&&... ts)
{
  return Overloader<Ts...>(std::forward<Ts>(ts)...);
}

/*
 * You should have enough knowledge to change the 'overload' function to accept multiple lambdas
 * If you're ready, you can uncomment the function body below.
 */
void test_4()
{
  auto o2 = overload(
    [](const int i){ return std::to_string(i); },
    [](const std::string &s){ return s;},
    [](const unsigned long i) {return std::to_string(i); },
    [](const double i){ return std::to_string(i);}
  );
  ASSERT(o2(2) == "2");
  ASSERT(o2(2ul) == "2");
  ASSERT(o2(std::string("Hello")) == "Hello");
}

/*
 * 1) Pass the template parameter pack to the lambda
 * 2) adapt the lambda so it calls the sum function with the parameter pack
 * 3) remove the 'return 0'
 * 4) uncomment the body of 'test_5'
 */
template<typename... Args>
auto sum2(Args... args)
{
  return [args...](){
    return sum(args...);
    }();
}

void test_5()
{
  ASSERT(sum2(1) == 1);
  ASSERT(sum2(1, 2) == 3);
  ASSERT(sum2(1, 2, 3) == 6);
}

} 
 
void small_ex2()
{
  test_1();
  test_2();
  test_3();
  test_4();
  test_5();
}
