#include <global.h>

namespace
{

/*
 * Lambdas are objects to.
 * Create a lambda 'create_adder' that takes an int as argument and
 * returns a lambda that adds that int to it's argument.
 */
void test_1()
{
  /* uncomment the following code and add your lambda here */
  // auto create_adder = ...
  // auto add2 = create_adder(2);
  // auto add5 = create_adder(5);
  // ASSERT(add2(3) == 5);
  // ASSERT(add5(1) == 6);
}

 
/* 
 * Since lambdas are instances with a type (that we don't know, but the compiler does)
 * We can inherit from them.
 * 
 * 1) Create a type 'Overloader' with two template parameters (T1, T2)
 *    and let 'Overloader' inherits from those two template types.
 * 2) Create a constructor that forwards it's two arguments to the constructor of T1 and T2
 * 2) Add a using declaration to 'Overloader' for 'operator()' of those template types.
 * 3) Create a template function 'overload' that takes two template arguments
 *    and returns an instance of 'Overloader' with as template types the arguments.
 */
void test_2()
{
  /* If all went as planned, you can uncomment the following lines and they should work */
  // auto o1 = overload(
  //   [](int i){ return std::to_string(i); },
  //   [](double d){ return std::to_string(d);}
  // );
  // ASSERT(o1(2) == "2");
  
  
  /*
   * Let's go a step further and use use our newly created 'overload'
   * function as visitor for std::visit.
   * Uncomment the code below and fill in the '...'
   */
  // using Var = std::variant<int, std::string>;
  // auto stringify = [](const Var &v) {
  //   return std::visit(
  //     ...,
  //    v);
  // };
  // Var v1 = 10;
  // Var v2 = "Hello";
  // ASSERT(stringify(v1) == "10");
  // ASSERT(stringify(v2) == "Hello");
  
  /*
   * What happens if in the 'overload' call you change the lambda that accepts a std::string
   * to accept a 'double'?
   * What does the compiler say?
   * Can we generalize the lambda so the following code works?
   * Hint: look at the overloads of std::to_string
   */
  // auto o2 = overload(
  //   ...
  // );
  // ASSERT(o2(2) == "2");
  // ASSERT(o2(2ul) == "2");
  // ASSERT(o2(std::string("Hello")) == "Hello");
}

}
 
void lambda_ex3()
{
  test_1();
  test_2();
}
