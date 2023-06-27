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
    boost::bind(&print_string, boost::bind(
      &std::map<int,std::string>::value_type::second,_1)));

  return 0;
}

