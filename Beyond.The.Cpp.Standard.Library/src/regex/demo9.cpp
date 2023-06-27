#include <iostream>
#include <string>
#include "boost/regex.hpp"

int main() {  
  std::cout << "Enter a regular expression:\n";
  std::string s;
  std::getline(std::cin, s);
  try {
    boost::regex reg(s);
    std::cout << "Enter a string to be matched:\n";
 
    std::getline(std::cin,s);
 
    if (boost::regex_match(s,reg))
      std::cout << "That's right!\n";
    else
      std::cout << "No, sorry, that doesn't match.\n";
  }
  catch(const boost::bad_expression& e) {
    std::cout << 
      "That's not a valid regular expression! (Error: " << 
      e.what() << ") Exiting...\n";
  }

  return 0;
}

