#include <iostream>
#include "boost/lambda/lambda.hpp"
#include "boost/lambda/casts.hpp"
#include "boost/lambda/bind.hpp"
#include "boost/lambda/exceptions.hpp"

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

  (try_catch(
    bind(&derived::do_more_stuff,ll_dynamic_cast<derived&>(*_1)),
      catch_exception<std::bad_cast>(bind(&base::do_stuff,_1))))(p1);
  (try_catch(
    bind(&derived::do_more_stuff,
      ll_dynamic_cast<derived&>(*_1)),
        catch_exception<std::bad_cast>(
          bind(&base::do_stuff,_1))))(p2);
}

