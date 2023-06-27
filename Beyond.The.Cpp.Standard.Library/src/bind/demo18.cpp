#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "boost/bind.hpp"

class print_size {
public:
  typedef void result_type;
  template <typename Pair> result_type operator()
    (std::ostream& os,const Pair& x) const {
    os << x.second.size() << '\n';
  }
};

int main() {
  std::map<std::string,std::vector<int> > m;
  m["Strange?"].push_back(1);
  m["Strange?"].push_back(2);
  m["Strange?"].push_back(3);
  m["Weird?"].push_back(4);
  m["Weird?"].push_back(5);

  std::for_each(m.begin(),m.end(),
    boost::bind(print_size(),boost::ref(std::cout),_1));

  return 0;
}

