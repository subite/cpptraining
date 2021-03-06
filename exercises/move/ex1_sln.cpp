#include <global.h>

namspace
{

/***
 * Exercise 1
 * Add move constructors to the following object
 */
struct Object_1
{
  Object_1(const std::string &v) : m_value(v) {}
  Object_1(const Object_1 &obj) : m_value(obj.m_value) {}
  
  Object_1(std::string &&v) : m_value(std::move(v)) {}
  Object_1(Object_1 &&obj) : m_value(std::move(obj.m_value)) {}
  Object_1 &operator=(Object_1 &&obj) { m_value = std::move(obj.m_value);  return *this; }
  
  std::string m_value;
};


/*
 * How do you know that your code works?
 * Add code here to verify that your new constructors work
 * You have an assert macro available:
 *   ASSERT(1 == 1);
 */
void test_1()
{
  std::string str = "obj";
  Object_1 o(std::move(str));
  ASSERT(str.size() == 0);
  ASSERT(o.m_value == "obj");
  
  Object_1 o2 = std::move(o);
  ASSERT(o.m_value.size() == 0);
  ASSERT(o2.m_value == "obj");
}
 
 
/*
 * What do you need to also add support for assignment
 * Uncomment the following code and make them work
 */
void test_2()
{
  Object_1 obj1("obj1");
  Object_1 obj2("obj2");
  obj1 = std::move(obj2);
  ASSERT(obj2.m_value.size() == 0);
  ASSERT(obj1.m_value == "obj2");
}

}
 
void move_ex1()
{
  test_1();
  test_2();
}
