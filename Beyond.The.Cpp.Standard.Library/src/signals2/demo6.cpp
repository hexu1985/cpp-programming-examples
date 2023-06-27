#include <iostream>
#include <boost/optional/optional_io.hpp>
#include "boost/signals2.hpp"

bool always_return_true() {
  return true;
}

bool always_return_false() {
  return false;
}

int main() {
  boost::signals2::signal<bool ()> sig;

  sig.connect(&always_return_true);
  sig.connect(&always_return_false);

  std::cout << std::boolalpha << "True or false? " << sig();
}

