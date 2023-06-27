#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
  std::vector<int> vec1;
  vec1.push_back(2);
  vec1.push_back(3);
  vec1.push_back(5);
  vec1.push_back(7);
  vec1.push_back(11);
  std::vector<int> vec2;
  vec2.push_back(7);
  vec2.push_back(4);
  vec2.push_back(2);
  vec2.push_back(3);
  vec2.push_back(1);
  std::cout << *std::find_if(vec1.begin(),vec1.end(),
    [](int _1) { return (_1>=3 && _1<5) || _1<1; }) << '\n';
  std::cout << *std::find_if(vec2.begin(),vec2.end(),
    [](int _1) { return _1>=4 && _1<10; }) << '\n';
  std::cout << *std::find_if(vec1.begin(),vec1.end(),
    [](int _1) { return _1==4 || _1==5; }) << '\n';
  std::cout << *std::find_if(vec2.begin(),vec2.end(),
    [](int _1) { return _1!=7 && _1<10; }) << '\n';
  std::cout << *std::find_if(vec1.begin(),vec1.end(),
    [](int _1) { return !(_1%3); }) << '\n';
  std::cout << *std::find_if(vec2.begin(),vec2.end(),
    [](int _1) { return _1/2<3; }) << '\n';
}

