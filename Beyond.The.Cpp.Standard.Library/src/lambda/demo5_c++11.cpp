#include <iostream>
#include <vector>
#include <algorithm>

template <typename T,typename Operation>
void for_all(T& t,Operation Op) {
  std::for_each(t.begin(),t.end(),Op);
}

int main() {
  std::vector<int> vec;
  vec.push_back(0);
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  for_all(vec, [](int _){ std::cout << ' ' << _ << '\n'; });

  return 0;
}

