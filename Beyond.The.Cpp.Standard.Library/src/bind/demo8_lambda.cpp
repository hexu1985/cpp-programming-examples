#include <vector>
#include <algorithm>
#include <iostream>

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
            [](int i) { return i > 5 && i <= 10; });

    std::cout << count << '\n';

    std::vector<int>::iterator int_it=std::find_if(
            ints.begin(),
            ints.end(),
            [](int i) { return i > 5 && i <= 10; });

    if (int_it!=ints.end()) {
        std::cout << *int_it << '\n';
    }

    return 0;
}

