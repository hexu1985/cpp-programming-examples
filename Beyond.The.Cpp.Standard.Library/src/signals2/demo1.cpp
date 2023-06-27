#include <iostream>
#include "boost/signals2.hpp"

void my_first_slot() {
  std::cout << "void my_first_slot()\n";
}

class my_second_slot {
public:
  void operator()() const {
    std::cout <<
      "void my_second_slot::operator()() const\n";
  }
};

int main() {
  boost::signals2::signal<void ()> sig;

  sig.connect(&my_first_slot);
  sig.connect(my_second_slot());

  std::cout << "Emitting a signal...\n";
  sig();
}

