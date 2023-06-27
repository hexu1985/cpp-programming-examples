#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
  std::vector<std::string> vec;
  vec.push_back("Lambda");
  vec.push_back("expressions");
  vec.push_back("really");
  vec.push_back("rock");
  std::for_each(vec.begin(),vec.end(),
    [](const std::string &_1) {
      if (_1.size() <= 6u) std::cout << _1 << '\n';
      else std::cout << "Skip.\n";
    });
}

