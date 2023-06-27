#include <iostream>
#include <string>
#include "boost/tuple/tuple.hpp"

template <typename Tuple,int Index> struct print_helper {
  static void print(const Tuple& t) {
    print_helper<Tuple,Index-1>::print(t);
    std::cout << boost::tuples::get<Index>(t) << '\n';
  }
};

template<typename Tuple> struct print_helper<Tuple,0> {
  static void print(const Tuple& t) {
    std::cout << boost::tuples::get<0>(t) << '\n';
  }
};

template <typename Tuple> void print_all(const Tuple& t) {
  print_helper<
    Tuple,boost::tuples::length<Tuple>::value-1>::print(t);
}

int main() {
  boost::tuple<int,std::string,double> 
    tup(42,"A four and a two",42.424242);

  print_all(tup);
}

