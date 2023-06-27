#include <iostream>
#include <string>
#include <cassert>
#include "boost/signals2.hpp"

int main() {
  boost::signals2::signal<void (std::string)> sig;

  sig.connect([](const std::string &_1) {
          std::cout << "Something happened: " << _1 << '\n'; });
  sig.connect([](const std::string &_1) {
    if(_1=="Signal") {
      std::cout << "Ok, I've got it\n";
    } else {
      std::cout << "Yeah, whatever\n";
    } });

  sig("Signal");
  sig("Another signal");

  boost::signals2::signal<void (int&)> sig2;
  sig2.connect(0, [](int &_1) { _1*=2; }); // 加倍
  sig2.connect(1, [](int &_1) { _1+=3; }); // 加 3
  int i=12;
  sig2(i);
  assert(i==27);
}

