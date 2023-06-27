#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include "boost/bind.hpp"

int main()
{
    std::vector<int> ints;

    ints.push_back(7);
    ints.push_back(4);
    ints.push_back(12);
    ints.push_back(10);

    int count=std::count_if(
            ints.begin(),
            ints.end(),
            boost::bind(
                std::logical_and<bool>(),
                boost::bind(std::greater<int>(),_1,5),
                boost::bind(std::less_equal<int>(),_1,10)));

    std::cout << count << '\n';

    std::vector<int>::iterator int_it=std::find_if(
            ints.begin(),
            ints.end(),
            boost::bind(std::logical_and<bool>(),
                boost::bind(std::greater<int>(),_1,5),
                boost::bind(std::less_equal<int>(),_1,10)));

    if (int_it!=ints.end()) {
        std::cout << *int_it << '\n';
    }

    return 0;
}

