#include <atomic>
#include <iostream>
#include <thread>
#include <boost/range/irange.hpp>

using namespace std;

int main()
{
    atomic<uint64_t> counter;
    counter.store(0);

    auto incr = [&] () { 
        for (auto i : boost::irange(0,1000000)) { 
            ++counter; 
        } 
    };

    thread t1(incr);
    thread t2(incr);

    t1.join();
    t2.join();

    cout << counter.load() << endl;

    return 0;
}
