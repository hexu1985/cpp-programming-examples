#include <iostream>
#include "boost/lambda/lambda.hpp"
#include "boost/lambda/casts.hpp"
#include "boost/lambda/if.hpp"
#include "boost/lambda/bind.hpp"

class base {
public:
  virtual ~base() {}
  void do_stuff() const {
    std::cout << "void base::do_stuff() const\n";
  }
};

class derived : public base {
public:
  void do_more_stuff() const {
    std::cout << "void derived::do_more_stuff() const\n";
  }
};

int main() {
  using namespace boost::lambda;
  base* p1=new base;
  base* p2=new derived;
  derived* pd=0;
  auto fn = [&pd](base *_1) {
    if ((pd = dynamic_cast<derived*>(_1))) pd->do_more_stuff();
    else pd->do_stuff();
  };
  fn(p1);
  fn(p2);
}

