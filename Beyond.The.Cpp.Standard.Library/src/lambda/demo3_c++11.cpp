#include <iostream>

class double_it {
public:  
    int operator()(int i) const 
    {
        return i*2;
    }
};

int main() 
{  
    double_it d;
    int i=12;

    // If you uncomment the following expression,  
    // the compiler will complain;
    // it's just not possible to deduce the return type
    // of the function call operator of double_it.
    // (std::cout << _1 << "*2=" << (bind(d,_1)))(i);
    [&d](int a) {
        std::cout << a << "*2=" << d(a);
    }(i);
    std::cout << '\n';
    [&d](int a) {
        std::cout << a << "*2=" << d(a);
    }(i);
    std::cout << '\n';

    return 0;
}

