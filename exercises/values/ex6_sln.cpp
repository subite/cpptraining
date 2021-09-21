#include <global.h>
#include <any>

namespace
{ 
  struct Vtable
  {
    bool (*equal)(void *a, void *b);
    void (*destroy)(void *ptr);
  };

  template <class Concrete>
  constexpr Vtable vtable_for
  {
    [](void *a, void *b){ return *static_cast<Concrete*>(a) == *static_cast<Concrete*>(b); },
    [](void *ptr){ delete static_cast<Concrete*>(ptr); },
  };



/**
 * With everything we learned last week
 * and all the previous exercises, you should be able to create your own std::any
 * but with comparison support.
 */

struct MyAny
{
  void *m_concrete;
  const Vtable *m_vtable;

  MyAny(const MyAny &t) = delete;
  MyAny(MyAny &&t) noexcept
  {
    m_concrete = t.m_concrete;
    m_vtable = t.m_vtable;
    t.m_vtable = nullptr;
    t.m_concrete = nullptr;
  }
  
    template<class T>

  MyAny(const T& t)
    : m_concrete(new T(t))
    , m_vtable(&vtable_for<T>)
  {};

  bool operator==(const MyAny &b)
  {
    if (m_vtable == b.m_vtable)
    {
      if (m_vtable == nullptr)
        return true;
      return m_vtable->equal(m_concrete, b.m_concrete);
    }
    return false;
  }

  ~MyAny()
  {
    if (m_vtable)
      m_vtable->destroy(m_concrete);
  }
};

/**
 * replace the std::any with MyAny when your done
 */
void test_1()
{
  MyAny i1 = 1;
  MyAny i2 = 1;
  MyAny s1 = std::string("string");
  MyAny s2 = std::string("string");
  ASSERT(i1 == i2);
  ASSERT(s1 == s2);
  ASSERT(not(i1 == s1));
  ASSERT(not(i2 == s2));
}
}



void values_ex6()
{
  test_1();
}