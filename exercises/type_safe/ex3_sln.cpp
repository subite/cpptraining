#include <global.h>
#include "NamedType/named_type.hpp"


/**
 * As you saw in ex2.cpp the BOOST_STRONG_TYPEDEF result in the loss of the operators on the underlying type
 * and is thus harder to use when you want to keep the underlying type for operations.
 *
 * NamedType tries to give a solution for that.
 * https://github.com/joboccara/NamedType
 */

/*
 * Here is a type "Lumen" (a measure of the total quantity of visible light emitted by a source per unit of time)
 * that is defined using the 'NamedType' type.
 */
using Lumen = fluent::NamedType<uint64_t, struct LumenStruct, fluent::Arithmetic>;

constexpr Lumen operator"" _lumen(unsigned long long value)
{
  return Lumen(value);
}

namespace
{

/*
 * Given the current 'Lumen' definition we can create instances of 'Lumen' but they are not very useful
 * We can't even compare it with itself.
 * Uncomment the code in test_1 and make it compile again by changing the definition of 'Lumen'
 */
void test_1()
{
  auto a = 10_lumen;
  auto b = 10_lumen;
  ASSERT(a == b);
}

/*
 * Do the same for test_2
 */
void test_2()
{
  auto a = 10_lumen;
  auto b = 11_lumen;
  ASSERT(a < b);
}

/*
 * Do the same for test_3
 */
void test_3()
{
  auto a = 10_lumen;
  auto b = 11_lumen;
  ASSERT((a + b) == 21_lumen);
}

/*
 * Do the same for test_4
 */
void test_4()
{
  auto a = 10_lumen;
  std::cout << "a = " << a << "\n";
}

std::ostream &operator<<(std::ostream &os, const Lumen &l)
{
  os << l.get() << " lumen";
  return os;
}

/*
 * Now provide a ostream operator<< overload for the 'Lumen' type that adds the unit after the number 
 */
void test_5()
{
  auto a = 10_lumen;
  std::cout << "a = " << a << "\n";
}

}
 
void type_safe_ex3()
{
  std::cout << "type_safe_ex3\n";
  test_1();
  test_2();
  test_3();
  test_4();
  test_5();
}

