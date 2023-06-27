#include <iostream>
#include <string>
#include "boost/tuple/tuple.hpp"

void print_all(const boost::tuples::null_type&) {}

template <typename Tuple> void print_all(const Tuple& t) {
  std::cout << t.get_head() << '\n';
  print_all(t.get_tail());
}

int main() {
  boost::tuple<int,std::string,double> 
    tup(42,"A four and a two",42.424242);

  print_all(tup);
}

