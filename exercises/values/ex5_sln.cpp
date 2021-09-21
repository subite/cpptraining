#include <global.h>

namespace
{

struct Vtable
{
  std::string (*id)(void *ptr);
  void (*destroy)(void *ptr);
  void* (*copy_const)(void *ptr);
  int &(*int_offset)(void *ptr);
};



template <class Concrete>
constexpr Vtable vtable_for {
  [](void *ptr) -> std::string { return static_cast<Concrete*>(ptr)->id(); },
  [](void *ptr){ delete static_cast<Concrete*>(ptr); },
  [](void *ptr) -> void* { return new Concrete(*static_cast<Concrete*>(ptr)); },
  [](void *ptr) -> int & { return static_cast<Concrete*>(ptr)->m_int; }
};

struct Vehicle
{
  Vehicle(Vehicle &&t) noexcept
    : m_int(t.m_int)
  {
    m_concrete = t.m_concrete;
    m_vtable = t.m_vtable;
    t.m_vtable = nullptr;
    t.m_concrete = nullptr;
  }
  
  Vehicle(const Vehicle &t) noexcept
    : m_vtable(t.m_vtable)
    , m_concrete(t.m_vtable->copy_const(t.m_concrete))
    , m_int(m_vtable->int_offset(m_concrete))
  {
  }
  
  template<class T>
  Vehicle(const T& t)
    : m_concrete(new T(t))
    , m_vtable(&vtable_for<T>)
    , m_int(m_vtable->int_offset(m_concrete))
  {};
  
  ~Vehicle()
  {
    if (m_vtable)
      m_vtable->destroy(m_concrete);
  }
  
  std::string id()
  {
    if (m_vtable)
      return m_vtable->id(m_concrete);
    return "";
  }
  
  void *m_concrete;
  const Vtable *m_vtable;
  int &m_int;
};

struct Car
{
  std::string id() { return m_id; }
  std::string m_id;
  int m_int = 1;
};

struct Bus
{
  std::string id() { return m_id; }
  std::string m_id;
  int m_int = 2;
};

/**
 * Uncomment the following code and make it work
 */
void test_1()
{
  std::vector<Vehicle> vs;
  vs.emplace_back(Car{"car_1"});
  vs.emplace_back(Car{"car_2"});
  vs.emplace_back(Bus{"bus_1"});
  vs.emplace_back(Bus{"bus_2"});
  
  ASSERT(vs[0].id() == "car_1");
  ASSERT(vs[1].id() == "car_2");
  ASSERT(vs[2].id() == "bus_1");
  ASSERT(vs[3].id() == "bus_2");
}

/**
 * Uncomment the following code and make it work
 */
void test_2()
{
  std::vector<Vehicle> v_old;
  v_old.emplace_back(Car{"car_1"});
  v_old.emplace_back(Car{"car_2"});
  v_old.emplace_back(Bus{"bus_1"});
  v_old.emplace_back(Bus{"bus_2"});
  
  auto v_new = v_old;
  ASSERT(v_old[0].id() == "car_1");
  ASSERT(v_new[1].id() == "car_2");
  ASSERT(v_old[2].id() == "bus_1");
  ASSERT(v_new[3].id() == "bus_2");
}


/**
 * Can you also provide access to member variables iso functions?
 * Add a int member to Car and Bus and provide access to it via Vehicle
 * Uncomment the following code and make it work
 */
void test_3()
{
  std::vector<Vehicle> v;
  v.emplace_back(Car{"car_1"});
  v.emplace_back(Bus{"bus_1"});
  
  ASSERT(v[0].id() == "car_1");
  ASSERT(v[0].m_int == 1);
  ASSERT(v[1].id() == "bus_1");
  ASSERT(v[1].m_int == 2);
}

}
 
void values_ex5()
{
  test_1();
  test_2();
  test_3();
}
