#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>

template <typename T> 
class add_prev: public std::unary_function<T,T> {  
  T prev_;
public:  
  T operator()(T t) {
    prev_+=t;    
    return prev_;  
  }
};

int main() {
  using namespace std::placeholders;
  std::vector<int> vec;
  vec.push_back(5);
  vec.push_back(8);
  vec.push_back(2);
  vec.push_back(1);

  std::cout << "original vec:\n";
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, ", "));
  std::cout << "\n";

  add_prev<int> ap;
  std::transform(
    vec.begin(),
    vec.end(),
    vec.begin(),
    std::bind(std::ref(ap),_1));

  std::cout << "after transform vec:\n";
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, ", "));
  std::cout << "\n";

  return 0;
}

