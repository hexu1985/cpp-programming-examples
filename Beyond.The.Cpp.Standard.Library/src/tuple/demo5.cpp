#include <iostream>
#include <vector> 
#include "boost/tuple/tuple.hpp"
#include "boost/tuple/tuple_comparison.hpp"

template <int Index> class element_less {
public:
  template <typename Tuple> 
  bool operator()(const Tuple& lhs,const Tuple& rhs) const {
    return boost::get<Index>(lhs)<boost::get<Index>(rhs); 
  } 
};


int main() {
  typedef boost::tuple<short,int,long,float,double,long double> 
    num_tuple;

  std::vector<num_tuple> vec;

  vec.push_back(num_tuple(6,2));
  vec.push_back(num_tuple(7,1));
  vec.push_back(num_tuple(5));

  std::sort(vec.begin(),vec.end(),element_less<1>());

  std::cout << "After sorting: " << 
    vec[0].get<0>() << '\n' <<
    vec[1].get<0>() << '\n' <<
    vec[2].get<0>() << '\n';
}

