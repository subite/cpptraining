#include <iostream>
#include <vector>


struct Vtable
{
  void (*speak)(void *ptr);
  void (*destroy)(void *ptr);
};



template <class Concrete>
constexpr Vtable vtable_for {
  [](void *ptr){ static_cast<Concrete*>(ptr)->speak(); },
  [](void *ptr){ delete static_cast<Concrete*>(ptr); },
};

struct Animal
{
  void *m_concrete;
  const Vtable *m_vtable;
  
  Animal(const Animal &t) = delete;
  Animal(Animal &&t) noexcept
  {
    m_concrete = t.m_concrete;
    m_vtable = t.m_vtable;
    t.m_vtable = nullptr;
    t.m_concrete = nullptr;
  }
  
  template<class T>
  Animal(const T& t)
    : m_concrete(new T(t))
    , m_vtable(&vtable_for<T>)
  {};
  
  ~Animal()
  {
    if (m_vtable)
      m_vtable->destroy(m_concrete);
  }
  
  void speak()
  {
    if (m_vtable)
      m_vtable->speak(m_concrete);
  }
};

struct Dog
{
  void speak()
  {
    std::cout << "Woof\n";
  }
};

struct Cat
{
  void speak()
  {
    std::cout << "Meow\n";
  }
};

int main()
{
  std::vector<Animal> v;
  v.emplace_back(Dog());
  v.emplace_back(Cat());
  for (auto &a : v)
    a.speak();
}
