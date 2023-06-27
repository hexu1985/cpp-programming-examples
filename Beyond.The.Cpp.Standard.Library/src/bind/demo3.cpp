#include <vector>
#include <algorithm>
#include "status.h"
#include "boost/bind.hpp"

int main() {
  std::vector<status*> p_statuses;
  p_statuses.push_back(new status("status 1"));
  p_statuses.push_back(new status("status 2"));
  p_statuses.push_back(new status("status 3"));
  p_statuses.push_back(new status("status 4"));
  
  p_statuses[1]->break_it();
  p_statuses[2]->break_it();
  
  for (std::vector<status*>::iterator it=p_statuses.begin();
    it!=p_statuses.end();++it) {
    (*it)->report();
  }

  //============================================
  std::cout << std::string(40, '=') << std::endl;
  std::for_each(  p_statuses.begin(),  p_statuses.end(),  std::mem_fun(&status::report));

  //============================================
  std::cout << std::string(40, '=') << std::endl;
  std::for_each(  p_statuses.begin(),  p_statuses.end(),  boost::bind(&status::report,_1));

  return 0;
}
