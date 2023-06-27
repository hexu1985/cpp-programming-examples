#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include "boost/bind.hpp"

void print_string(const std::string& s) {
  std::cout << s << '\n';
}

int main()
{
  std::map<int,std::string> my_map;
  my_map[0]="Boost";
  my_map[1]="Bind";
  
  std::for_each(
    my_map.begin(),
    my_map.end(),
    [](const std::map<int,std::string>::value_type &val) { print_string(val.second); });

  return 0;
}

