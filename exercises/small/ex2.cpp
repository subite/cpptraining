#include <global.h>

using namespace std::string_literals;

namespace
{

/*
 * Create a function 'sum' that returns the sum of all it's parameters
 * and uncomment the following lines
 */
void test_1()
{
  // ASSERT(sum(1, 2) == 3);
  // ASSERT(sum(1.0, 2.0, 3.0) == 6.0);
  // ASSERT(sum("a"s, "b"s, "c"s, "d"s) == "abcd"s);
}


/**
 * Now write a function 'sum_doubler' that doubles the sum function
 * Forward the arguments to the sum function
 */
void test_2()
{
  // ASSERT(sum_doubler(1, 2) == 6);
  // ASSERT(sum_doubler(1.0, 2.0, 3.0) == 12.0);
  // ASSERT(sum_doubler("a"s, "b"s, "c"s, "d"s) == "abcdabcd"s);
}


/*
 * Create a function 'push_back_vec' that takes a vector as first argument
 * and pushes all remaining all arguments to that vector
 * HINT: use the ',' operator
 */
void test_3()
{
  // std::vector<int> v1;
  // push_back_vec(v1, 6, 2, 45, 12);
  // push_back_vec(v1, 1, 2, 9);
  // ASSERT(v1[0] == 6);
  // ASSERT(v1[6] == 9);
  
  // std::vector<std::string> v2;
  // std::string a = "a";
  // push_back_vec(v2, std::move(a), "b");
  // ASSERT(v2[0] == "a");
  // ASSERT(v2[1] == "b");
}


template <class T1, class T2>
class Overloader : public T1, public T2
{
public:
  template <class T3, class T4>
  Overloader(T3 &&t3, T4 &&t4)
    : T1(std::forward<T3>(t3))
    , T2(std::forward<T4>(t4))
  {}
  using T1::operator();
  using T2::operator();
};

template <class T1, class T2>
auto overload(T1 &&t1, T2 &&t2)
{
  return Overloader<T1, T2>(std::forward<T1>(t1), std::forward<T2>(t2));
}

/*
 * You should have enough knowledge to change the 'overload' function to accept multiple lambdas
 * If you're ready, you can uncomment the function body below.
 */
void test_4()
{
  // auto o2 = overload(
  //   [](const int i){ return std::to_string(i); },
  //   [](const std::string &s){ return s;},
  //   [](const unsigned long i) {return std::to_string(i); },
  //   [](const double i){ return std::to_string(i);}
  // );
  // ASSERT(o2(2) == "2");
  // ASSERT(o2(2ul) == "2");
  // ASSERT(o2(std::string("Hello")) == "Hello");
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
  // return [](){
  //   return sum(0);
  // }();
  return 0;
}

void test_5()
{
  // ASSERT(sum2(1) == 1);
  // ASSERT(sum2(1, 2) == 3);
  // ASSERT(sum2(1, 2, 3) == 6);
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
