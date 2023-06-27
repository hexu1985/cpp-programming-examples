#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template <typename T,typename Operation>
void for_all(T& t,Operation Op) {
  std::for_each(t.begin(),t.end(),Op);
}

int main() {
  std::vector<std::string> vec;
  vec.push_back("What are");
  vec.push_back("the names");
  vec.push_back("of the");
  vec.push_back("placeholders?");
  for_all(vec, [](const std::string &Arg1) { std::cout << Arg1 << " ";});
  std::cout << "\nArg1, Arg2, and Arg3!";
  std::cout << "\n";

  return 0;
}

