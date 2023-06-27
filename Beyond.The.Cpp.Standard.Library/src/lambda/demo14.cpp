#include <iostream>
#include <algorithm>
#include <vector>
#include "boost/lambda/lambda.hpp"
#include "boost/lambda/bind.hpp"

template <typename T> class sig_helper {};

// The version for the overload on int
template<> class sig_helper<int> {
public:
  typedef std::string type;
};

// The version for the overload on std::string
template<> class sig_helper<std::string> {
public:
  typedef double type;
};

// The function object
class some_function_object {
public:
  template <typename Args> class sig {
    typedef typename boost::tuples::element<1,Args>::type
      cv_first_argument_type;
    typedef typename
      boost::remove_cv<cv_first_argument_type>::type
      first_argument_type;
  public:
    // The first argument helps us decide the correct version
    typedef typename
      sig_helper<first_argument_type>::type type;
  };

  std::string operator()(int i) const {
    std::cout << i << '\n';
    return "Hello!";
  }

  double operator()(const std::string& s) const {
    std::cout << s << '\n';
    return 3.14159265353;
  }
};

int main() {
  using namespace boost::lambda;
  std::vector<int> vec;
  vec.push_back(5);
  vec.push_back(8);
  vec.push_back(2);
  vec.push_back(1);

  std::vector<std::string> svec;
  svec.resize(vec.size());

  std::cout << "vec:\n";
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, ", "));
  std::cout << "\n";

  some_function_object sfo;
  std::transform(
    vec.begin(),
    vec.end(),
    svec.begin(),
    bind(var(sfo), _1));

  std::cout << "svec:\n";
  std::copy(svec.begin(), svec.end(), std::ostream_iterator<std::string>(std::cout, ", "));
  std::cout << "\n";

  return 0;
}

