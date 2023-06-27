#include <iostream>
#include <exception>
#include "boost/lambda/lambda.hpp"
#include "boost/lambda/exceptions.hpp"
#include "boost/lambda/if.hpp"
#include "boost/lambda/construct.hpp"
#include "boost/lambda/bind.hpp"

class some_exception : public std::exception {
  std::string what_;
public:
  some_exception(const char* what) : what_(what) {}

  virtual const char* what() const throw() {
    return what_.c_str();
  }
  virtual ~some_exception() throw() {}
};

int main() {
  using namespace boost::lambda;

  try {
    std::cout << "Throw an exception here.\n";

    (if_then(_1==true,throw_exception(
      bind(constructor<some_exception>(),
        constant("Somewhere, something went \
        terribly wrong.")))))(make_const(true));

    std::cout << "We'll never get here!\n";
  }
  catch(some_exception& e) {
    std::cout << "Caught exception, \"" << e.what() << "\"\n";
  }
}

