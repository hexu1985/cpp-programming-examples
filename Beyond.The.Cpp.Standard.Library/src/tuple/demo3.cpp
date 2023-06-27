#include <iostream>
#include <string>

#include "boost/tuple/tuple.hpp"

class base {
public:
  virtual ~base() {};
  virtual void test() {
    std::cout << "base::test()\n";
  }
};

class derived : public base {
public:
  virtual void test() {
    std::cout << "derived::test()\n";
  }
};

int main() {
  boost::tuple<int,std::string,derived> tup1(-5,"Tuples");
  boost::tuple<unsigned int,std::string,base> tup2;
  tup2=tup1;

  tup2.get<2>().test();
  std::cout << "Interesting value: " 
    << tup2.get<0>() << '\n';

  const boost::tuple<double,std::string,base> tup3(tup2);
  // tup3.get<0>()=3.14;	// compile error
  derived d;
  boost::tuple<int,std::string,derived*> 
    tup4(-5,"Tuples",&d);
  boost::tuple<unsigned int,std::string,base*> tup5;
  tup5=tup4;

  tup5.get<2>()->test();

  boost::tuple<int,std::string,derived&>
    tup6(12,"Example",d); 

  boost::tuple<unsigned int,std::string,base&> tup7(tup6);

  tup7.get<2>().test();
}

