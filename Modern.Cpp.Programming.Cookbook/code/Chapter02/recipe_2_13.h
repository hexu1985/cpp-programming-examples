#pragma once

#include <chrono>
#include <ctime>
#include <string>
#include <vector>
#include <iterator>
#include <string>

#ifdef HAS_FORMAT_LIBRARY
#include <format>
using namespace std;
#else
#define FMT_HEADER_ONLY
#include "fmt/chrono.h"
#include "fmt/format.h"
using namespace fmt;
#endif

namespace recipe_2_13
{
   void execute()
   {
      {
         auto text = format("{} is {}", "John", 42);
      }

      {
         auto text = format("{0} is {1}", "John", 42);
      }

      {
         auto text = format("{0} hex is {0:08X}", 42);
      }

      {
         auto now = std::chrono::system_clock::now();
         auto time = std::chrono::system_clock::to_time_t(now);
         auto text = format("Today is {:%Y-%m-%d}", *std::localtime(&time));
      }

      {
         std::vector<char> buf;
         format_to(std::back_inserter(buf), "{} is {}", "John", 42);
      }

      {
         auto size = formatted_size("{} is {}", "John", 42);
         std::vector<char> buf(size);
         format_to(buf.data(), "{} is {}", "John", 42);
      }

      {
         char buf[100];
         auto result = format_to_n(buf, sizeof(buf), "{} is {}", "John", 42);
      }

      {
         auto t1 = format("{:5}", 42);    // "   42"
         auto t2 = format("{:5}", 'x');   // "x    "
         auto t3 = format("{:*<5}", 'x'); // "x****"
         auto t4 = format("{:*>5}", 'x'); // "****x"
         auto t5 = format("{:*^5}", 'x'); // "**x**"
         auto t6 = format("{:5}", true);  // "true "
      }

      {
         auto t7 = format("{0:},{0:+},{0:-},{0: }", 42);   // "42,+42,42, 42"
         auto t8 = format("{0:},{0:+},{0:-},{0: }", -42);  // "-42,-42,-42,-42"
      }

      {
         auto t9  = format("{:+05d}", 42); // "+0042"
         auto t10 = format("{:#05x}", 42); // "0x02a"
         auto t11 = format("{:<05}", -42); // "-42  "
      }
   }
}
