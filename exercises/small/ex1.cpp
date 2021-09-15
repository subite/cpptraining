#include <global.h>

namespace
{

/*
 * Simplify the code below by using auto
 */
void test_1()
{
  std::map<std::string, std::vector<std::string>> belongings;
  
  std::vector<std::string> &Toms = belongings["Tom"];
  Toms.emplace_back("keys");
  Toms.emplace_back("car");
  
  std::vector<std::string> &Bills = belongings["Bill"];
  Bills.emplace_back("pc");
  Bills.emplace_back("zune");
  
  std::stringstream ss;
  for (std::map<std::string, std::vector<std::string>>::const_iterator it = belongings.begin();
       it != belongings.end();
       ++it)
  {
    const std::map<std::string, std::vector<std::string>>::value_type &p = *it;
    ss << p.first << ":";
    for (std::map<std::string, std::vector<std::string>>::mapped_type::const_iterator it2 = p.second.begin();
         it2 != p.second.end();
         ++it2)
    {
      if (it2 != p.second.begin())
        ss << ",";
      ss << *it2;
    }
    ss << "\n";
  }
  ASSERT(ss.str() == "Bill:pc,zune\nTom:keys,car\n");
}


/*
 * Do the same with the following code
 */
void increment(std::deque<bool>& bits)
{
  std::function<void(bool&)> flip = [](bool &bit){ bit = not bit; };
  if (bits.empty()) return;
  if (bits.size() == 1)
    flip(bits.back());
    
  for (long bitIndex = bits.size() - 1; bitIndex >= 0; --bitIndex)
  {
    bool &bit = bits[bitIndex];
    flip(bit);
    if (bit == true)
      break;
  }
}


/**
 * You can leave this function alone
 */
std::string to_string(const std::deque<bool>& bits)
{
  std::stringstream ss;
  for (auto bitIndex = 0ull; bitIndex < bits.size(); ++bitIndex)
    ss << bits[bitIndex];
  return ss.str();
}


void test_2()
{
  auto number = std::deque<bool>(3);
  increment(number); ASSERT(to_string(number) == "001");
  increment(number); ASSERT(to_string(number) == "010");
  increment(number); ASSERT(to_string(number) == "011");
  increment(number); ASSERT(to_string(number) == "100");
  increment(number); ASSERT(to_string(number) == "101");
  increment(number); ASSERT(to_string(number) == "110");
  increment(number); ASSERT(to_string(number) == "111");
  increment(number); ASSERT(to_string(number) == "000");
}

} 
 
void small_ex1()
{
  test_1();
  test_2();
}
