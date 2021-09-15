#include <global.h>


/**
 * Why does the commented code in "test_1" not compile?
 * What should we change to "Object" to make it compile?
 */


namespace
{

template <typename T>
struct Object
{
  template <typename S, typename = std::enable_if_t<std::is_same<std::remove_cvref_t<S>, T>::value>>
  Object(S &&t) : m_value(std::forward<S>(t)) {}
  
  T m_value;
};



void test_1()
{
  std::unique_ptr<int> ptr = std::make_unique<int>(5);
  auto obj1 = Object<decltype(ptr)>(std::move(ptr));
  
  std::string v2 = "2";
  auto obj2 = Object<decltype(v2)>(std::move(v2));
  
  std::string v3 = "3";
  auto obj3 = Object<decltype(v3)>(v3);
  
}

}

void move_ex4()
{
  test_1();
}
