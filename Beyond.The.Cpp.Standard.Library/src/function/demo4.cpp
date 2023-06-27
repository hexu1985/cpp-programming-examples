#include <iostream>
#include "boost/function.hpp"

class some_class {
public:
  void do_stuff(int i) const {
    std::cout << "OK. Stuff is done. " << i << '\n';
  }
};

void f1() 
{
  boost::function<void(some_class,int)> f;
  f=&some_class::do_stuff;
  f(some_class(),2);
}

void f2()
{
  boost::function<void(some_class&,int)> f;
  f=&some_class::do_stuff;
  some_class s;
  f(s,1);
}

void f3()
{
  boost::function<void(some_class*,int)> f;
  f=&some_class::do_stuff;
  some_class s;
  f(&s,3);
}

int main()
{
  f1();
  f2();
  f3();
  return 0;
}
