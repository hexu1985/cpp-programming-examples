#include <iostream>
#include <string>
#include "boost/variant.hpp"

class print_visitor : public boost::static_visitor<void> {
public:
  void operator()(int &i) const {
    std::cout << "It's an int: " << i << '\n';
  }

  void operator()(std::string &s) const {
    std::cout << "It's a std::string: " << s << '\n';
  }

  void operator()(double &d) const {
    std::cout << "It's a double: " << d << '\n';
  }

};

int main() {
  boost::variant<int,std::string,double,char>
    my_first_variant("Hello there!");
 
  print_visitor v;
 
  boost::apply_visitor(v,my_first_variant);
  my_first_variant=12;
  boost::apply_visitor(v,my_first_variant);
  my_first_variant=1.1;
  boost::apply_visitor(v,my_first_variant);
  my_first_variant='a';
  boost::apply_visitor(v,my_first_variant);
}

