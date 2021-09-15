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

// BOOST_STRONG_TYPEDEF( ... )
// BOOST_STRONG_TYPEDEF( ... )
// BOOST_STRONG_TYPEDEF( ... )

/**
 * Create a struct Person that has members of the types above
 */
// struct Person
// {
// };

/* uncomment the following std::array */
// static std::array s_persons = {
//   Person{FirstName("F1"), LastName("L1"), ID("I1")},
//   Person{FirstName("F2"), LastName("L2"), ID("I2")},
//   Person{FirstName("F3"), LastName("L3"), ID("I3")},
//   Person{FirstName("F4"), LastName("L4"), ID("I4")},
//   Person{FirstName("F5"), LastName("L5"), ID("I5")}
// };

/**
 * Create a function "Find" that accepts FirstName/LastName/ID and returns a pointer to the 'Person' struct in s_persons that matches
 */
// Person *find( ... ) {}

/**
 * Create a overload for the ostream operator<< that prints the Persons full information if you give it the FirstName or the LastName or the ID
 * You can use the previously created 'find' function to lookup the write person
 */
// std::ostream &operator<<(std::ostream &os, ...)

/**
 * If you completed the above tasks, you should be able to uncomment the code in "test_1"
 */
void test_1()
{
//  ASSERT(find(FirstName("F1")) != nullptr);
//  ASSERT(find(LastName("L1")) != nullptr);
//  ASSERT(find(ID("I1")) != nullptr);

//  ASSERT(find(FirstName("I1")) == nullptr);
//  ASSERT(find(LastName("F1")) == nullptr);
//  ASSERT(find(ID("L1")) == nullptr);
  
//  std::cout << "F1 -> " << FirstName("F1") << "\n";
//  std::cout << "L1 -> " << LastName("L1") << "\n";
//  std::cout << "I1 -> " << ID("I1") << "\n";
}

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
}

}
 
void type_safe_ex2()
{
  std::cout << "type_safe_ex2\n";
  test_1();
  test_2();
}

