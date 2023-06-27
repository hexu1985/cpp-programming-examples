#include <iostream>
#include "boost/signals2.hpp"

class slot {
public:
  void operator()() const {
    std::cout << "Something important just happened!\n";
  }
};

int main() {
  boost::signals2::signal<void ()> sig;
  {
    boost::signals2::scoped_connection s=sig.connect(slot());
  }
  sig();
}

