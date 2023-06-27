#include <iostream>
#include "boost/signals2.hpp"
#include "boost/bind.hpp"

class some_class {
public:
  bool some_function(double d) {
    return d>3.14;
  }

  bool another_function(double d) {
    return d<0.0;
  }
};

int main() {
  boost::signals2::signal<bool (double)> sig0;
  boost::signals2::signal<bool (double)> sig1;

  some_class sc;

  sig0.connect(
    boost::bind(&some_class::some_function,&sc,_1));
  sig1.connect(
    boost::bind(&some_class::another_function,&sc,_1));

  sig0(3.1);
  sig1(-12.78);
}

