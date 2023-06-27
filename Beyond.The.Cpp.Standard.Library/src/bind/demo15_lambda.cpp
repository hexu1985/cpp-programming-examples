#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "boost/bind.hpp"

void print(std::ostream* os,int i) {
  (*os) << i << '\n';
}

int main() {
  std::map<std::string,std::vector<int> > m;
  m["Strange?"].push_back(1);
  m["Strange?"].push_back(2);
  m["Strange?"].push_back(3);
  m["Weird?"].push_back(4);
  m["Weird?"].push_back(5);

  std::for_each(m.begin(),m.end(),
    [](const std::map<std::string, std::vector<int> >::value_type &val) { print(&std::cout,val.second.size()); });

  return 0;
}

