#include <iostream>
#include "boost/tuple/tuple.hpp"
#include "boost/tuple/tuple_io.hpp"

int main() {
  boost::tuple<int,double> tup1;
  boost::tuple<long,long,long> tup2;

  std::cout << "Enter an int and a double as (1 2.3):\n";
  std::cin >> tup1;

  std::cout << "Enter three ints as |1.2.3|:\n";
  std::cin >> boost::tuples::set_open('|') >>
  boost::tuples::set_close('|') >>
  boost::tuples::set_delimiter('.') >> tup2;

  std::cout << "Here they are:\n"
    << tup1 << '\n'
    << boost::tuples::set_open('\"') <<
  boost::tuples::set_close('\"') <<
  boost::tuples::set_delimiter('-');

  std::cout << tup2 << '\n';
}

