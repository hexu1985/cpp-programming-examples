#include <iostream>
#include <vector>
#include <algorithm>

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
    std::for_each(
      vec_.begin(),
      vec_.end(),
      [](const T &_1) { std::cout << _1 << ","; });
  }
};

int main() {
  std::vector<int> vec;
  vec.push_back(0);
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  memorizer<int> m;
  std::for_each(vec.begin(),vec.end(), [&m](int _1) { m=_1; });
  m.report();
  m.clear();
  std::cout << "\n";
  return 0;
}

