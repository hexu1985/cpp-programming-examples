#include <iostream>
#include <cassert>
#include <string>
#include "boost/regex.hpp"

int main() {
  // 3 digits, a word, any character, 2 digits or "N/A", 
  // a space, then the first word again
  boost::regex reg("(new)|(delete)");
  boost::smatch m;
  std::string s=
    "Calls to new must be followed by delete. \
    Calling simply new results in a leak!";
  
  if (boost::regex_search(s,m,reg)) {
    // Did new match?
    if (m[1].matched)
      std::cout << "The expression (new) matched!\n";
    if (m[2].matched)
      std::cout << "The expression (delete) matched!\n";
  }
}

