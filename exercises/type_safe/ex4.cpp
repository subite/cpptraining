#include <global.h>
#include <mutex>
#include <thread>


namespace
{

class Resource
{
public:
  uint64_t get() const { return m_counter; }
  void set(uint64_t new_value) { m_counter = new_value; } 
private:
  uint64_t m_counter = 0;
};

Resource &get_global_resource()
{
  static Resource s_resource;
  return s_resource;
}

std::mutex &get_global_resource_lock()
{
  static std::mutex s_mutex;
  return s_mutex;
}

/**
 * Uncomment the code in test_1
 * What is dangerous about it?
 * How do we make sure that code that calls 'lock()' also calls 'unlock()'
 * How do we make sure that everybody that gets the global resource also calls lock and unlock
 * 
 * Without changing the Resource class rewrite the global functions and thread function to solve these issues.
 */
void test_1()
{
/*
  auto f = [](){
    for (auto i = 0; i < 100; i++)
    {
      get_global_resource_lock().lock();
      auto old_val = get_global_resource().get();
      std::this_thread::sleep_for(std::chrono::milliseconds(5));
      auto new_val = old_val + 1;
      get_global_resource().set(new_val);
      get_global_resource_lock().unlock();
    }
  };
  
  std::thread t1(f);
  std::thread t2(f);
  
  t1.join();
  t2.join();

  ASSERT(get_global_resource().get() == 200);
*/

  get_global_resource_lock().lock();
  std::cout << "Global resource counter: " << get_global_resource().get();
  get_global_resource_lock().unlock();
}

}
 
void type_safe_ex4()
{
  std::cout << "type_safe_ex4\n";
  test_1();
}

