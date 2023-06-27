#include <iostream>
#include <string>
#include "boost/regex.hpp"

int main() {
  boost::regex reg4("[^13579]");
  std::string s="0123456789";
  boost::sregex_iterator it(s.begin(),s.end(),reg4);
  boost::sregex_iterator end;

  while (it!=end) 
    std::cout << *it++;

  std::cout << std::endl;
  return 0;
}

