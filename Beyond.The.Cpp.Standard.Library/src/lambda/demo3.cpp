#include <iostream>
#include "boost/lambda/lambda.hpp"
#include "boost/lambda/bind.hpp"

class double_it {
public:  
    int operator()(int i) const 
    {
        return i*2;
    }
};

int main() 
{  
    using namespace boost::lambda;
    double_it d;
    int i=12;

    // If you uncomment the following expression,  
    // the compiler will complain;
    // it's just not possible to deduce the return type
    // of the function call operator of double_it.
    // (std::cout << _1 << "*2=" << (bind(d,_1)))(i);
    (std::cout << _1 << "*2=" << (bind<int>(d,_1)))(i);
    std::cout << '\n';
    (std::cout << _1 << "*2=" << (ret<int>(bind(d,_1))))(i);
    std::cout << '\n';

    return 0;
}

