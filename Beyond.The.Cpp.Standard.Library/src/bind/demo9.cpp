#include <iostream>
#include <list>
#include <functional>
#include <algorithm>
#include <iterator>
#include "boost/bind.hpp"

int main() 
{
    std::list<double> values;
    values.push_back(10.0);
    values.push_back(100.0);
    values.push_back(1000.0);

    std::transform(
            values.begin(),
            values.end(),
            values.begin(),
            boost::bind(
                std::multiplies<double>(),0.90,
                boost::bind<double>(
                    std::multiplies<double>(),_1,1.10)));

    std::copy(
            values.begin(),
            values.end(),
            std::ostream_iterator<double>(std::cout," "));

    std::cout << std::endl;

    return 0;
}
