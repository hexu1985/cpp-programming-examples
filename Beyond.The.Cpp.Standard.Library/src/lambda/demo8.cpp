#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include "boost/lambda/lambda.hpp"
#include "boost/lambda/bind.hpp"

int main() {
  using namespace boost::lambda;
  std::vector<int> vec(3);
  vec[0]=12;
  vec[1]=10;
  vec[2]=7;

  std::cout << "original vec:\n";
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, ", "));
  std::cout << "\n";

  // Transform using std::bind1st and std::plus
  std::transform(vec.begin(),vec.end(),vec.begin(),
    std::bind1st(std::plus<int>(),4));

  std::cout << "after transform by bind1st vec:\n";
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, ", "));
  std::cout << "\n";

  // Transform using a lambda expression
  std::transform(vec.begin(),vec.end(),vec.begin(),_1-=4);

  std::cout << "after transform lambda vec:\n";
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, ", "));
  std::cout << "\n";

  return 0;
}

