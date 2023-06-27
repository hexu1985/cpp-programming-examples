#include <iostream>
#include <string>
#include <algorithm>

template <typename String,typename Integral>
void is_it_long(const String& s,const Integral& i) {
  [](const String &_1, const Integral &_2) {
    if (_1.size() < _2) std::cout << "Quite short...\n";
    else std::cout << "Quite long...\n";
  }(s, i);
}

int main() {
  std::string s="Is this string long?";
  is_it_long(s,4u);
  is_it_long(s,4);
}

