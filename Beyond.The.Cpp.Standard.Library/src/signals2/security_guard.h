#ifndef SECURITY_GUARD_INC
#define SECURITY_GUARD_INC

#include <string>
#include <iostream>

class security_guard {
  std::string name_;
public:
  security_guard (const char* name) : name_(name) {}

  void do_whatever_it_takes_to_stop_that_car() const {
    std::cout <<
      "Stop in the name of...eh..." << name_ << '\n';
  }

  void nah_dont_bother() const {
    std::cout << name_ <<
      " says: Man, that coffee tastes f i n e fine!\n";
  }

  void operator()(const std::string& car_id) const {
    if (car_id.size() && car_id[0]=='N')
      do_whatever_it_takes_to_stop_that_car();
    else
      nah_dont_bother();
  }
};

#endif
