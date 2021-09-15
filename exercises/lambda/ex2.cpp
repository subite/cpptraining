#include <global.h>

namespace
{

/*
 * Create a lambda that add it's parameter to itself
 */
void test_1()
{
  /* uncomment the following code and add your lambda here */
  // auto twice = ...
  // ASSERT(twice(2) == 4);
  // ASSERT(twice(2.0) == 4.0);
  // ASSERT(twice(std::string("a")) == "aa");
}
 
 
/* 
 * Create a lambda that returns the string equivalent of the variant
 * Hint: use std::visit and std::to_string
 */
void test_2()
{
  using Var = std::variant<int, unsigned long, double>;
  Var v1 = 10;
  Var v2 = 2.0;
  Var v3 = 5ul;
 
  /* Uncomment the following code and fill in the lambda stringify */ 
  // auto stringify = ...
  // ASSERT(stringify(v1) == "10");
  // ASSERT(stringify(v2) == "2.000000");
  // ASSERT(stringify(v3) == "5");
}

}
 
void lambda_ex2()
{
  test_1();
  test_2();
}
