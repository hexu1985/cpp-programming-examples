#include <vector>
#include <algorithm>
#include "status.h"
#include "boost/bind.hpp"
#include "boost/shared_ptr.hpp"

int main() {
  std::vector<boost::shared_ptr<status> > s_statuses;
  s_statuses.push_back(
    boost::shared_ptr<status>(new status("status 1")));
  s_statuses.push_back(
    boost::shared_ptr<status>(new status("status 2")));
  s_statuses.push_back(
    boost::shared_ptr<status>(new status("status 3")));
  s_statuses.push_back(
    boost::shared_ptr<status>(new status("status 4")));
  s_statuses[1]->break_it();
  s_statuses[2]->break_it();
  
  for (std::vector<boost::shared_ptr<status> >::iterator it=s_statuses.begin();
    it!=s_statuses.end();++it) {
    (*it)->report();
  }

  //============================================
  //std::cout << std::string(40, '=') << std::endl;
  //std::for_each(  s_statuses.begin(),  s_statuses.end(),  std::mem_fun(&status::report));

  //============================================
  std::cout << std::string(40, '=') << std::endl;
  std::for_each(  s_statuses.begin(),  s_statuses.end(),  boost::bind(&status::report,_1));

  return 0;
}
