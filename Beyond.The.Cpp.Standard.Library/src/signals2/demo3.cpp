#include <iostream>
#include "boost/signals2.hpp"

class double_slot {
public:
  void operator()(int& i) const {
    i*=2;
  }
};

class plus_slot {
public:
  void operator()(int& i) const {
    i+=3;
  }
};

int main() {
  boost::signals2::signal<void (int&)> sig;
  sig.connect(1, double_slot());
  sig.connect(0, plus_slot());

  int result=12;
  sig(result);
  std::cout << "The result is: " << result << '\n';
}

