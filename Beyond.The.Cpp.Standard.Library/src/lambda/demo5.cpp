#include <iostream>
#include <vector>
#include <algorithm>
#include "boost/lambda/lambda.hpp"

template <typename T,typename Operation>
void for_all(T& t,Operation Op) {
  std::for_each(t.begin(),t.end(),Op);
}

int main() {
  using boost::lambda::constant;
  using boost::lambda::constant_type;
  constant_type<char>::type newline(constant('\n'));
  constant_type<char>::type space(constant(' '));
  boost::lambda::placeholder1_type _;
  std::vector<int> vec;
  vec.push_back(0);
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  for_all(vec,std::cout << space << _ << newline);
  for_all(vec,
    std::cout << constant(' ') << _ << constant('\n'));
}

