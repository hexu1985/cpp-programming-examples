#ifndef TRACER_INCLUDE
#define TRACER_INCLUDE

#include <iostream>
#include <string>

class tracer {
public:
  tracer() {
    std::cout << "tracer::tracer()\n";
  }

  tracer(const tracer& other) {
    std::cout << "tracer::tracer(const tracer& other)\n";
  }

  tracer& operator=(const tracer& other) {
    std::cout <<
      "tracer& tracer::operator=(const tracer& other)\n";
    return *this;
  }

  ~tracer() {
    std::cout << "tracer::~tracer()\n";
  }

  void print(const std::string& s) const {
    std::cout << s << '\n';
  }
};

#endif
