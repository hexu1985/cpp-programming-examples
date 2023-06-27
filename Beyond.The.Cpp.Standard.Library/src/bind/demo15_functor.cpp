#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "boost/bind.hpp"

class print_size {
  std::ostream& os_;
  typedef std::map<std::string,std::vector<int> > map_type;
public:
  print_size(std::ostream& os):os_(os) {}

  void operator()(
    const map_type::value_type& x) const {
    os_ << x.second.size() << '\n';
  }
};

int main() {
  std::map<std::string,std::vector<int> > m;
  m["Strange?"].push_back(1);
  m["Strange?"].push_back(2);
  m["Strange?"].push_back(3);
  m["Weird?"].push_back(4);
  m["Weird?"].push_back(5);

  std::for_each(m.begin(),m.end(),print_size(std::cout));

  return 0;
}

