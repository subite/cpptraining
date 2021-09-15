#include <global.h>

namespace
{

struct Object1
{
  Object1(uint64_t v) : m_value(v) { ++s_constructs; }
  Object1(Object1 &&o) : m_value(o.m_value) { ++s_moves; }
  Object1(const Object1 &o) : m_value(o.m_value) { ++s_copies; }
  
  uint64_t m_value;
  
  static uint64_t s_constructs;
  static uint64_t s_moves;
  static uint64_t s_copies;
};

uint64_t Object1::s_constructs = 0;
uint64_t Object1::s_moves = 0;
uint64_t Object1::s_copies = 0;


std::pair<std::vector<Object1>, std::vector<Object1>> split(std::vector<Object1> &&vec)
{
  std::vector<Object1> even;
  even.reserve(vec.size());
  std::vector<Object1> uneven;
  uneven.reserve(vec.size());
  for (auto &o : vec)
  {
    if (o.m_value % 2 == 0)
      even.push_back(std::move(o));
    else
      uneven.push_back(std::move(o));
  }
  return {std::move(even), std::move(uneven)};
}

void test_1()
{
  std::vector<Object1> v;
  v.reserve(10);
  for (uint64_t i = 1; i <= 10; ++i)
  {
    v.emplace_back(i);
  }
  auto value = std::move(split(std::move(v)));

  std::cout << "constructs: " << Object1::s_constructs << "\n";
  std::cout << "moves: " << Object1::s_moves << "\n";
  std::cout << "copies: " << Object1::s_copies << "\n";
  std::cout << "evens: " << value.first.size() << "\n";
  std::cout << "unevens: " << value.second.size() << "\n";

  ASSERT(Object1::s_constructs == 10);
  ASSERT(Object1::s_moves == 10);
  ASSERT(Object1::s_copies == 0);
  ASSERT(value.first.size() == 5);
  ASSERT(value.second.size() == 5);
}


}

void move_ex2()
{
  test_1();
}
