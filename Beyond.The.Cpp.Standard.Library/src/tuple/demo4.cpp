#include <iostream>
#include <string>

#include "boost/tuple/tuple.hpp"
#include "boost/tuple/tuple_comparison.hpp"

int main() {
  boost::tuple<int,std::string> tup1(11,"Match?");
  boost::tuple<short,std::string> tup2(12,"Match?");

  std::cout << std::boolalpha;

  std::cout << "Comparison: tup1 is less than tup2\n";

  std::cout << "tup1==tup2: " << (tup1==tup2) << '\n'; 
  std::cout << "tup1!=tup2: " << (tup1!=tup2) << '\n';
  std::cout << "tup1<tup2: " << (tup1<tup2) << '\n';
  std::cout << "tup1>tup2: " << (tup1>tup2) << '\n';
  std::cout << "tup1<=tup2: " << (tup1<=tup2) << '\n';
  std::cout << "tup1>=tup2: " << (tup1>=tup2) << '\n';

  tup2.get<0>()=boost::get<0>(tup1); //tup2=tup1 also works

  std::cout << "\nComparison: tup1 equals tup2\n"; 

  std::cout << "tup1==tup2: " << (tup1==tup2) << '\n'; 
  std::cout << "tup1!=tup2: " << (tup1!=tup2) << '\n';
  std::cout << "tup1<tup2: " << (tup1<tup2) << '\n';
  std::cout << "tup1>tup2: " << (tup1>tup2) << '\n';
  std::cout << "tup1<=tup2: " << (tup1<=tup2) << '\n';
  std::cout << "tup1>=tup2: " << (tup1>=tup2) << '\n';
}

