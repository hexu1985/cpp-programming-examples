#include <iostream>
#include <vector>
#include <algorithm>
#include "boost/lambda/lambda.hpp"

template <typename T> class memorizer {
  std::vector<T> vec_;
public:
  memorizer& operator=(const T& t) {
    vec_.push_back(t);
    return *this;
  }
  void clear() {
    vec_.clear();
  }
  void report() const {
    using boost::lambda::_1;
    std::for_each(
      vec_.begin(),
      vec_.end(),
      std::cout << _1 << ",");
  }
};

int main() {
  using boost::lambda::var_type;
  using boost::lambda::var;
  using boost::lambda::_1;
  std::vector<int> vec;
  vec.push_back(0);
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  memorizer<int> m;
  var_type<memorizer<int> >::type mem(var(m));
  std::for_each(vec.begin(),vec.end(),mem=_1);
  m.report();
  m.clear();
  std::for_each(vec.begin(),vec.end(),var(m)=_1);
  m.report();
  std::cout << "\n";
  return 0;
}

