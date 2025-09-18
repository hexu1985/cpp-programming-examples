#pragma once

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

namespace recipe_2_14
{
   namespace v1
   {
      struct employee
      {
         int         id;
         std::string firstName;
         std::string lastName;
      };
   }

   namespace v2
   {
      struct employee
      {
         int         id;
         std::string firstName;
         std::string lastName;
      };
   }
}

#ifdef HAS_FORMAT_LIBRARY
namespace std {
#else
namespace fmt {
#endif

template <>
struct formatter<recipe_2_14::v1::employee>
{
   constexpr auto parse(format_parse_context& ctx) 
   {
      return ctx.begin();
   }

   auto format(recipe_2_14::v1::employee const& e, format_context& ctx) const {
      return format_to(ctx.out(),
         "[{}] {} {}",
         e.id, e.firstName, e.lastName);
   }
};

template<>
struct formatter<recipe_2_14::v2::employee>
{
   bool lexicographic_order = false;

   template <typename ParseContext>
   constexpr auto parse(ParseContext& ctx) 
   {
      auto iter = ctx.begin();
      if (iter == ctx.end()) {
          return iter;
      }
      auto get_char = [&]() { return iter != ctx.end() ? *iter : 0; };

      if (get_char() == ':') ++iter;
      char c = get_char();

      switch (c)
      {
      case '}': return ++iter;
      case 'L': lexicographic_order = true; return ++iter;
      case '{': return ++iter;
      default: throw format_error("invalid format");
      }
   }

   template <typename FormatContext>
   auto format(recipe_2_14::v2::employee const& e, FormatContext& ctx) const
   {
      if (lexicographic_order)
         return format_to(ctx.out(), "[{}] {}, {}", e.id, e.lastName, e.firstName);

      return format_to(ctx.out(), "[{}] {} {}", e.id, e.firstName, e.lastName);
   }
};

#ifdef HAS_FORMAT_LIBRARY
}   // namespace std
#else
}   /// namespace fmt
#endif

namespace recipe_2_14
{
   void execute()
   {
      {
         v1::employee e{ 42, "John", "Doe" };
         auto s1 = format("{}", e);   // [42] John Doe
         // auto s2 = format("{:L}", e); // error
      }

      {
         v2::employee e{ 42, "John", "Doe" };
         auto s1 = format("{}", e);   // [42] John Doe
         auto s2 = format("{:L}", e); // [42] Doe, John
         // auto s3 = format("{:A}", e); // error (invalid format)
      }
   }
}
