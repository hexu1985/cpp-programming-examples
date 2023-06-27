#include "tracer.h"
#include "boost/bind.hpp"

int main()
{
    tracer t;
    boost::bind(&tracer::print,&t,_1)(std::string("I'm called directly on t\n"));
    return 0;
}
