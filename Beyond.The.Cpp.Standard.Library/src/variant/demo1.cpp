#include <iostream>
#include <string>
#include "boost/variant.hpp"

template <typename V> void print(V& v) {
  if (int* pi=boost::get<int>(&v))
    std::cout << "It's an int: " << *pi << '\n';
  else if (std::string* ps=boost::get<std::string>(&v))
    std::cout << "It's a std::string: " << *ps << '\n';
  else if (double* pd=boost::get<double>(&v))
    std::cout << "It's a double: " << *pd << '\n';

  std::cout << "My work here is done!\n";
}

int main() {
  boost::variant<int,std::string,double>
    my_first_variant("Hello there!");
  print(my_first_variant);
  my_first_variant=12;
  print(my_first_variant);
  my_first_variant=1.1;
  print(my_first_variant);
}

