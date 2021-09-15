#include <global.h>
#include <boost/serialization/strong_typedef.hpp>

namespace
{

/**
 * Use the boost strong typedef macro to define 3 strong types (all based on std::string):
 *   - A type "FirstName"
 *   - A type "LastName"
 *   - A type "ID"
 * https://www.boost.org/doc/libs/1_49_0/libs/serialization/doc/strong_typedef.html
 */

BOOST_STRONG_TYPEDEF(std::string, FirstName)
BOOST_STRONG_TYPEDEF(std::string, LastName)
BOOST_STRONG_TYPEDEF(std::string, ID)

/**
 * Create a struct Person that has members of the types above
 */
struct Person
{
  FirstName first;
  LastName last;
  ID id;
  
  bool operator==(const FirstName &f) { return f == first; }
  bool operator==(const LastName &f) { return f == last; }
  bool operator==(const ID &f) { return f == id; }
};

// uncomment the following std::array
static std::array s_persons = {
  Person{FirstName("F1"), LastName("L1"), ID("I1")},
  Person{FirstName("F2"), LastName("L2"), ID("I2")},
  Person{FirstName("F3"), LastName("L3"), ID("I3")},
  Person{FirstName("F4"), LastName("L4"), ID("I4")},
  Person{FirstName("F5"), LastName("L5"), ID("I5")}
};

/**
 * Create a function "Find" that accepts FirstName/LastName/ID and returns a pointer to the 'Person' struct in s_persons that matches
 */
template<class T, class = std::enable_if_t<std::is_same_v<T, LastName> || std::is_same_v<T, FirstName> || std::is_same_v<T, ID>>>
Person *find(const T &f)
{
  auto it = std::find(s_persons.begin(), s_persons.end(), f);
  return it != s_persons.end() ? &*it : nullptr;
}

/**
 * Create a overload for the ostream operator<< that prints the Persons full information if you give it the FirstName or the LastName or the ID
 * You can use the previously created 'find' function to lookup the write person
 */
template<class T, class = std::enable_if_t<std::is_same_v<T, LastName> || std::is_same_v<T, FirstName> || std::is_same_v<T, ID>>>
std::ostream &operator<<(std::ostream &os, const T &f)
{
  auto p = find(f);
  if (p)
    os << "{ first: " << (std::string)p->first << ", last: " << (std::string)p->last << ", id: " << (std::string)p->id << " }"; 
  else
    os << "{}";
  return os;
}

/**
 * If you completed the above tasks, you should be able to uncomment the code in "test_1"
 */
void test_1()
{
  ASSERT(find(FirstName("F1")) != nullptr);
  ASSERT(find(LastName("L1")) != nullptr);
  ASSERT(find(ID("I1")) != nullptr);

  ASSERT(find(FirstName("I1")) == nullptr);
  ASSERT(find(LastName("F1")) == nullptr);
  ASSERT(find(ID("L1")) == nullptr);
  
  std::cout << "F1 -> " << FirstName("F1") << "\n";
  std::cout << "L1 -> " << LastName("L1") << "\n";
  std::cout << "I1 -> " << ID("I1") << "\n";
}

void f(const std::string &) { }
void g(const std::string &) { std::cout << "g_string\n"; }
void g(const FirstName &) { std::cout << "g_FirstName\n"; }

void test_2()
{
  // Can you assign a generic std::string to a FirstName/LastName/ID?
  // Can you assign FirstName/LastName/ID to a std::string?
  // Can you pass a FirstName/LastName/ID to a function accepting an std::string?
  // Can you compare a FirstName with another FirstName?
  // Can you compare a FirstName with a LastName?
  // Can you add a FirstName to a FirstName?
  // If there is a function with an overload for std::string and FirstName, what version does the compiler take?
  // Test all these things out
  
  // FirstName a = std::string("F1"); // error: conversion from ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} to non-scalar type ‘{anonymous}::FirstName’ requested
  std::string b = FirstName("F1");
  ASSERT(FirstName("F1") == FirstName("F1"));
  // FirstName("F1") == LastName("F1"); // This seems to trigger a warning during compilation
  // auto sum = FirstName("F1") + FirstName("F1");  // error: no match for ‘operator+’ (operand types are ‘{anonymous}::FirstName’ and ‘{anonymous}::FirstName’)
  f(FirstName("F1"));
  g(FirstName("F1"));
}

}
 
void type_safe_ex2()
{
  std::cout << "type_safe_ex2\n";
  test_1();
  test_2();
}

