#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <memory>

class base {
public:
  virtual ~base() {}
};

class derived : public base {
};

int main() {
  typedef std::shared_ptr<base> ptr_type;
  typedef std::map<std::string,ptr_type> map_type;

  map_type m;
  m["An object"]=ptr_type(new base);
  m["Another object"]=ptr_type();
  m["Yet another object"]=ptr_type(new base);

  auto fn = 
    [](typename map_type::value_type &_1) {
      if (!_1.second.get()) {
        _1.second = ptr_type(new derived);
        std::cout << "Created a new derived for \"" << _1.first << "\".\n";
      } else {
        std::cout << "\"" << _1.first << "\" already has a valid pointer.\n";
      }
    };

  std::for_each(m.begin(),m.end(), fn);

  m["Beware, this is slightly tricky"]=ptr_type();
  std::cout << "\nHere we go again...\n";

  std::for_each(m.begin(),m.end(), fn);
}
