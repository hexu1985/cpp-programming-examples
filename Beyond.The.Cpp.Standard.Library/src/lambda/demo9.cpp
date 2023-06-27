#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "boost/lambda/lambda.hpp"

void print_vec(const std::vector<int> &vec, const char *title)
{
  std::cout << title << "\n";
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, ", "));
  std::cout << "\n";
}

int main() {
  using namespace boost::lambda;
  std::vector<int> vec(3);
  vec[0]=1;
  vec[1]=2;
  vec[2]=3;
  print_vec(vec, "original vec:");

  std::for_each(vec.begin(),vec.end(),_1+=10);
  print_vec(vec, "after for_each +=10:");

  std::for_each(vec.begin(),vec.end(),_1-=10);
  print_vec(vec, "after for_each -=10:");

  std::for_each(vec.begin(),vec.end(),_1*=3);
  print_vec(vec, "after for_each *=3:");

  std::for_each(vec.begin(),vec.end(),_1/=2);
  print_vec(vec, "after for_each /=2:");

  std::for_each(vec.begin(),vec.end(),_1%=3);
  print_vec(vec, "after for_each %=3:");

  return 0;
}

