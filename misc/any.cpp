#include <cstdint>
#include <iostream>
#include <boost/any.hpp>

int main() {
    boost::any any1(static_cast<uint64_t>(0));
    uint64_t int1 = boost::any_cast<uint64_t>(any1);  // ok

    boost::any any2(static_cast<uint64_t>(0));
    try {
        int int2 = boost::any_cast<int>(any2);  // fails
    }
    catch (const boost::bad_any_cast& e) {
        std::cout << "fail" << std::endl;
    }
}
