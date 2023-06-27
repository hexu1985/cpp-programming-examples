#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int main() {
  typedef std::map<int,std::string> type;
  type keys_and_values;
  keys_and_values[3]="Less than pi";
  keys_and_values[42]="You tell me";
  keys_and_values[0]="Nothing, if you ask me";
  std::for_each(
    keys_and_values.begin(),
    keys_and_values.end(),
    [](const type::value_type &val) {
      std::cout << "key=" << val.first << ", value=" << val.second << '\n';
    });
  std::cout << '\n';
  // Print the size and max_size of the container
  [](const type &t) {
    std::cout << "keys_and_values.size()=" << t.size() << "\nkeys_and_values.max_size()=" << t.max_size();
  }(keys_and_values);
  std::cout << '\n';
  return 0;
}

