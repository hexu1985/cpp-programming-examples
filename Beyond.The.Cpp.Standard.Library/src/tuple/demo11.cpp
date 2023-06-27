#include <iostream>
#include "boost/tuple/tuple.hpp"
#include <cassert>
#include <typeinfo>  //译注：原文没有这行，不能通过编译

template <bool B,typename Tuple> struct largest_type_helper {
  typedef typename boost::tuples::element<1,Tuple>::type type;
};

template<typename Tuple> struct largest_type_helper<true,Tuple> {
  typedef typename boost::tuples::element<0,Tuple>::type type;
};

template<typename Tuple> struct largest_type {
  typedef typename largest_type_helper<
    (sizeof(boost::tuples::element<0,Tuple>)>
    sizeof(boost::tuples::element<1,Tuple>)),Tuple>::type type; 
};

template <typename Tuple> 
typename largest_type<Tuple>::type sum(const Tuple& t) {
  typename largest_type<Tuple>::type
    result=boost::tuples::get<0>(t)+
      boost::tuples::get<1>(t);

  return result;
}

int main() {
  typedef boost::tuple<short,int,long> my_tuple;

  boost::tuples::element<0,my_tuple>::type first=14;
  assert(typeid(first) == typeid(short));  
  //译注：原文为assert(type_id(first) == typeid(short)); 明显有误
  boost::tuples::element<1,my_tuple>::type second=27;
  assert(typeid(second) == typeid(int));
  //译注：原文为assert(type_id(second) == typeid(int)); 明显有误
  boost::tuples::element<
    boost::tuples::length<my_tuple>::value-1,my_tuple>::type 
    last;

  my_tuple t(first,second,last);

  std::cout << "Type is int? " << 
    (typeid(int)==typeid(largest_type<my_tuple>::type)) << '\n';

  int s=sum(t);
}

