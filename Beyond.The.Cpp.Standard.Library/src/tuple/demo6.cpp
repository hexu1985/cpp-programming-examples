#include <iostream>
#include "boost/tuple/tuple.hpp"
#include "boost/math/common_factor.hpp"

boost::tuple<int,int> gcd_lcm(int val1,int val2) {
  return boost::make_tuple(
    boost::math::gcd(val1,val2),
    boost::math::lcm(val1,val2));
}

int main() {
  //"老"方法
  boost::tuple<int,int> tup;
  tup=gcd_lcm(12,18);
  int gcd=tup.get<0>();  // 译注：原文为 int gcd=tup.get<0>()); 明显有误
  int lcm=tup.get<1>();  // 译注：原文为 int gcd=tup.get<1>()); 明显有误

  std::cout << "Greatest common divisor: " << gcd << '\n';
  std::cout << "Least common multiple: " << lcm << '\n';

  //"新"方法
  boost::tie(gcd,lcm)=gcd_lcm(15,20);

  std::cout << "Greatest common divisor: " << gcd << '\n';
  std::cout << "Least common multiple: " << lcm << '\n';
}

