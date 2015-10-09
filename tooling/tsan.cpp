#include <iostream>
#include <thread>
#include <boost/range/irange.hpp>

int main()
{
    uint64_t counter = 0;
    auto incr = [&] () { 
        for (auto i : boost::irange(0,1000000)) { 
            ++counter; 
        } 
    };

    std::thread t1(incr);
    std::thread t2(incr);

    t1.join();
    t2.join();

    std::cout << counter << std::endl;

    return 0;
}
