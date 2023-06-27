#ifndef PERSONAL_INFO_INCLUDE
#define PERSONAL_INFO_INCLUDE

#include <string>
#include <iostream>

class personal_info {
  std::string name_;
  std::string surname_;
  unsigned int age_;

public:
  personal_info(
    const std::string& n,
    const std::string& s,
    unsigned int age):name_(n),surname_(s),age_(age) {}

  std::string name() const {
    return name_;
  }

  std::string surname() const {
    return surname_;
  }

  unsigned int age() const {
    return age_;
  }
};

std::ostream& operator<<(
  std::ostream& os,const personal_info& pi) {
  os << pi.name() << ' ' <<
    pi.surname() << ' ' << pi.age() << '\n';
  return os;
}

#endif
