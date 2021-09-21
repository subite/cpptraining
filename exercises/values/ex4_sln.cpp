#include <global.h>
#include <thread>
#include <immer/flex_vector.hpp>

namespace
{
using namespace std::chrono_literals;

std::string s_saved;


/**
 * Luckily for us, there are libraries that implement immutable containers for us
 * and they also looked at the performance
 * 
 * For the last time, change the editor example, but now use the immer library:
 * https://github.com/arximboldi/immer
 */
class Editor
{
public:
  void append(const std::string &str)
  {
    m_undoBuff.push_back(m_buff);
    m_buff = m_buff + immer::flex_vector<char>{str.begin(), str.end()};
  }
  
  std::string get() const
  {
    return std::string(m_buff.begin(), m_buff.end());
  }
  
  void undo()
  {
    if (m_undoBuff.empty())
      return;
    m_buff = std::move(m_undoBuff.back());
    m_undoBuff.pop_back();
  }
  
  void save() const
  {
    std::thread t([buff=m_buff](){
      s_saved = std::string(buff.begin(), buff.end());
    });
    t.detach();
  }


private:
  immer::flex_vector<char> m_buff;
  std::vector<immer::flex_vector<char>> m_undoBuff;
};

/**
 * After you changed it to use immer, you can uncomment the following code
 */
void test_1()
{
  Editor e;
  e.append("Hello ");
  e.append("World");
  ASSERT(e.get() == "Hello World");
}


/**
 * Now add an undo option to the Editor
 * Uncomment the code below and make it work
 */
void test_2()
{
  Editor e;
  e.append("Hello ");
  e.append("World");
  ASSERT(e.get() == "Hello World");
  e.undo();
  ASSERT(e.get() == "Hello ");
  e.undo();
  ASSERT(e.get() == "");
}

/**
 * The save takes a long time
 * So we want the save to happen in a different thread
 * Make the save run on a different thread
 */
void test_3()
{
  Editor e;
  e.append("Hello ");
  auto start = std::chrono::high_resolution_clock::now();
  e.save();
  e.append("World");
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> elapsed = end-start;
  ASSERT(elapsed < 100ms);
  std::this_thread::sleep_for(300ms);
  ASSERT(e.get() == "Hello World");
  ASSERT(s_saved == "Hello ");
}

}
 
void values_ex4()
{
  test_1();
  test_2();
  test_3();
}
