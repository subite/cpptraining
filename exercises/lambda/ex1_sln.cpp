#include <global.h>

namespace
{

/*
 * Basic lambda syntax
 * Create a lambda length that returns the length of a string
 */
void test_1()
{
  /* uncomment the following code and add your lambda here */
  auto length = [](const std::string &str) -> int { return str.length(); };
  ASSERT(length("abc") == 3);
  ASSERT(length("abcde") == 5);
}
 
 
/*
 * Lambda captures
 * Create a lambda called 'multiply' that multiplies the argument with the variable 'multiplier'
 */
void test_2()
{
  int multiplier = 1;
  auto multiply = [&multiplier](int t) {
    return t * multiplier;
  };
  
  ASSERT(multiply(2) == 2);
  multiplier = 2;
  ASSERT(multiply(2) == 4);
  multiplier = 3;
  ASSERT(multiply(2) == 6);
}

/*
 * Lambda captures
 * Create a vector of functions that multiply the index in the vector with the argument
 * index i -> i * argument
 */
void test_3()
{
  std::vector<std::function<int(int)>> multipliers;
  for (int n = 0; n != 10; ++n)
  {
    /* Alter the lambda represent a different
     * calculation on every iteration, so that we
     * end up with an array of multiplying functions
     * n -> n * i
     * lambda expressions can be used to create functions on-the-fly!
     */
    multipliers.push_back([n=n](int i) { return n * i; });
  }

  ASSERT(multipliers[1](1) == 1);
  ASSERT(multipliers[1](2) == 2);
  ASSERT(multipliers[2](1) == 2);
  ASSERT(multipliers[3](3) == 9);
}

/*
 * Statefull lambdas
 */
void test_4()
{
  /*
   * create a lambda expression `called` that stores and returns the number of times it has been called
   * HINT: lambda expressions are immutable, unless...
   */
   auto called = [n=0]() mutable {
     return ++n;
   };

  ASSERT(called() == 1);
  ASSERT(called() == 2);
  ASSERT(called() == 3);
}

void test_5()
{
  /* create a lambda expression `fib` that every time it's called returns the next fibonacci number */

  auto fib = [x1=-1, x2=-1]() mutable {
    if (x1 == -1) {
      x1 = 0;
      return x1;
    }
    if (x2 == -1) {
      x2 = 1;
      return x2;
    }
    auto ret = x1 + x2;
    x1 = x2;
    x2 = ret;
    return ret;
  };
  ASSERT(fib() == 0);
  ASSERT(fib() == 1);
  ASSERT(fib() == 1);
  ASSERT(fib() == 2);
  ASSERT(fib() == 3);
  ASSERT(fib() == 5);
}

} 
 
void lambda_ex1()
{
  test_1();
  test_2();
  test_3();
  test_4();
  test_5();
}
