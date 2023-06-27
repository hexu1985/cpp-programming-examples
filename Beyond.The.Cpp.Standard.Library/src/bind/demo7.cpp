#include <vector>
#include <algorithm>
#include <iterator>
#include "personal_info.h"
#include "boost/bind.hpp"

class personal_info_age_less_than: public std::binary_function<personal_info,personal_info,bool> {
public:
    bool operator ()(const personal_info& p1,const personal_info& p2) {
        return p1.age()<p2.age();
    }
};

int main()
{
    std::vector<personal_info> vec;
    vec.push_back(personal_info("Little","John",30));
    vec.push_back(personal_info("Friar", "Tuck",50));
    vec.push_back(personal_info("Robin", "Hood",40));

    std::cout << "original order of vec:\n";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<personal_info>(std::cout, "\n"));

    std::cout << "sort by personal_info_age_less_than:\n";
    std::sort(vec.begin(),vec.end(),personal_info_age_less_than());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<personal_info>(std::cout, "\n"));

    std::cout << "sort by bind personal_info::surname:\n";
    std::sort(vec.begin(), vec.end(), 
            boost::bind(std::less<std::string>(),
                boost::bind(&personal_info::surname,_1),
                boost::bind(&personal_info::surname,_2)));
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<personal_info>(std::cout, "\n"));

    std::cout << "sort by bind personal_info::age:\n";
    std::sort(vec.begin(), vec.end(), 
            boost::bind(std::less<unsigned int>(), 
                boost::bind(&personal_info::age,_1),
                boost::bind(&personal_info::age,_2)));
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<personal_info>(std::cout, "\n"));

    std::cout << "sort by lambda personal_info::surname:\n";
    std::sort(vec.begin(), vec.end(), 
            [](const personal_info &lhs, const personal_info &rhs) {
                return lhs.surname() < rhs.surname(); });
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<personal_info>(std::cout, "\n"));

    std::cout << "sort by lambda personal_info::age:\n";
    std::sort(vec.begin(), vec.end(), 
            [](const personal_info &lhs, const personal_info &rhs) {
                return lhs.age() < rhs.age(); });
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<personal_info>(std::cout, "\n"));

    return 0;
}

