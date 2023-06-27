#include <iostream>
#include <string>
#include <functional>
#include "boost/tuple/tuple.hpp"

template <typename Function> void for_each_element(
  const boost::tuples::null_type&, Function) {}

template <typename Tuple, typename Function> void 
for_each_element(Tuple& t, Function func) {
  func(t.get_head());
  for_each_element(t.get_tail(),func);
}

struct print {
  template <typename T> void operator()(const T& t) {
    std::cout << t << '\n';
  }
};

template <typename T> struct print_type {
  void operator()(const T& t) {
    std::cout << t << '\n';
  }

  template <typename U> void operator()(const U& u) {}
};

int main() {
  typedef boost::tuple<short,int,long> my_tuple;

  boost::tuple<int,short,double> nums(1,2,3.01);

  for_each_element(nums, print());
  for_each_element(nums, print_type<double>());
}

