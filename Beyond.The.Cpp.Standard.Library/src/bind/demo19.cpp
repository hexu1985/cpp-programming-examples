#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "boost/bind.hpp"

class print_size {
public:
  typedef void result_type;
  template <typename T> void operator()
    (std::ostream& os,const T& x) const {
    os << x.size() << '\n';
  }
};

int main() {
  std::map<std::string,std::vector<int> > m;
  m["Strange?"].push_back(1);
  m["Strange?"].push_back(2);
  m["Strange?"].push_back(3);
  m["Weird?"].push_back(4);
  m["Weird?"].push_back(5);

  typedef std::map<std::string,std::vector<int> > map_type;
  std::for_each(m.begin(),m.end(),
    boost::bind(print_size(),boost::ref(std::cout),
        boost::bind(&map_type::value_type::second,_1)));

  return 0;
}

