#include <iostream>
#include "boost/signals.hpp"

class slot {
public:
  void operator()() const {
    std::cout << "Something important just happened!\n";
  }
};

int main() {
  boost::signal<void ()> sig;
  {
    boost::signals::scoped_connection s=sig.connect(slot());
  }
  sig();
}

