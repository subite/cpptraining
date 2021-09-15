#include <global.h>

using namespace std::chrono_literals;

namespace
{

// for the exercises in this file, you can use cppreference as a guide
// https://en.cppreference.com/w/cpp/chrono

// create a new type that represents a duration of 1/60000th of a second
// use std::chrono as it already has all the features we need
using F60kHz = std::ratio<1, 60000>;
using Duration60kHz = std::chrono::duration<int64_t, F60kHz>;


// now change the following code to make it type safe
void test_1()
{
  Duration60kHz time2sec(2s);
  Duration60kHz time100ms(100ms);
  int count = 10;
  auto total = (time2sec + time100ms) * count;
  ASSERT(total.count() == 1260000);
}

// create a time point that represents the time in 1/60000th of a second
using Time60kHzUtc = std::chrono::time_point<std::chrono::system_clock, Duration60kHz>;

// create a function 'now' that returns the current UTC time in our new time point
auto now() { return std::chrono::time_point_cast<Duration60kHz>(std::chrono::system_clock::now()); }

// use this clock to change and modify the the following code
// you can add a special ostream overload for our custom type
void test_2()
{
  auto start = now();
  // do some work
  std::vector<int> v;
  for (int i = 0; i < 10000; ++i) v.push_back(i);
  auto total = std::accumulate(v.begin(), v.end(), 0ull);
  (void)total;
  // record end time
  auto end = now();
  auto diff = end - start;
  std::cout << "test_2 diff: " << diff.count() << "\n";
}

// What does the following function print?
// Is this what we expect?
// Modify the following function to use std::chrono types
// What did the compiler do to help you?
void test_3()
{
  // these are all the lap times in miliseconds
  std::vector lap_times{400ms, 356ms, 402ms, 397ms, 402ms, 386ms};

  /**
   * error: no match for ‘operator+=’ (operand types are ‘std::chrono::duration<long int>’ and ‘std::chrono::duration<long int, std::ratio<1, 1000> >’)
        total_sec += i;
   */
  auto total_sec = 0ms;
  for (auto i : lap_times)
    total_sec += i;
  std::cout << "test_3: The total time is " << std::chrono::duration_cast<std::chrono::seconds>(total_sec).count() << " seconds\n";
}

}

void type_safe_ex1()
{
  std::cout << "type_safe_ex1\n";
  test_1();
  test_2();
  test_3();
}
