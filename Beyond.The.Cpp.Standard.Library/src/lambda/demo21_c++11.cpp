#include <iostream>
#include <exception>

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
  try {
    std::cout << "Throw an exception here.\n";

    auto fn =
      [](bool _1) {
        if (_1==true)
          throw some_exception("Somewhere, something went terribly wrong.");
      };

    fn(true);

    std::cout << "We'll never get here!\n";
  }
  catch(some_exception& e) {
    std::cout << "Caught exception, \"" << e.what() << "\"\n";
  }
}

