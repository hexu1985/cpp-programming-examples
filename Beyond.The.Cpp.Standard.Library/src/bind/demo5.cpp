#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "simple_bind.h"

class Test {
public:
  void do_stuff(const std::vector<int>& v) {
    std::copy(v.begin(),v.end(),
      std::ostream_iterator<int>(std::cout," "));
  }
};

int main() {
  Test t;
  std::vector<int> vec;
  vec.push_back(42);
  simple_bind(&Test::do_stuff,t,_1)(vec);
  std::cout << std::endl;
  return 0;
}

