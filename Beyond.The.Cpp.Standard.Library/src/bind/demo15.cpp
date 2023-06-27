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
    boost::bind(&print,&std::cout,
      boost::bind(&std::vector<int>::size,
        boost::bind(
          &std::map<std::string,
            std::vector<int> >::value_type::second,_1))));

  return 0;
}

