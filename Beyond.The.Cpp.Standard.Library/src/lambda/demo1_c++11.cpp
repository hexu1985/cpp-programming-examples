#include <iostream>
#include <string>
#include <functional>

int main() {
  [](const std::string &_1, const std::string &_2, const std::string &_3)
  { std::cout << _1 << " " << _3 << " " << _2 << "!\n"; }("Hello","friend","my");
  std::function<void(int,int,int)> f = [](int _1, int _2, int _3) {
    std::cout << _1 << "*" << _2 << "+" << _3
      << "=" <<_1*_2+_3 << "\n";
  };

  f(1,2,3);
  f(3,2,1);

  return 0;
}

