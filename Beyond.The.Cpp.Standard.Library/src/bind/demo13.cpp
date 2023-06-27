#include <iostream>
#include "boost/bind.hpp"

class base {
public:
  virtual void print() const {
    std::cout << "I am base.\n";
  }
  virtual ~base() {}
};

class derived : public base {
public:
  void print() const {
    std::cout << "I am derived.\n";
  }
};

int main()
{
  derived d;
  base b;
  boost::bind(&base::print,_1)(b);
  boost::bind(&base::print,_1)(d);

  return 0;
}
