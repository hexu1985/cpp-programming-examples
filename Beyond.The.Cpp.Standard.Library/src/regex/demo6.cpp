#include <iostream>
#include <string>
#include "boost/regex.hpp"

class regex_callback {
  int sum_;
public:
  regex_callback() : sum_(0) {}

  template <typename T> void operator()(const T& what) {
    sum_+=atoi(what[1].str().c_str());
  }

  int sum() const {
    return sum_;
  }
};

int main() {
  boost::regex reg("(\\d+),?");
  std::string s="1,1,2,3,5,8,13,21";

  boost::sregex_iterator it(s.begin(),s.end(),reg);
  boost::sregex_iterator end;

  regex_callback c;
  int sum=for_each(it,end,c).sum();
  std::cout << "sum of " << s << " is " << sum << std::endl;

  return 0;
}

