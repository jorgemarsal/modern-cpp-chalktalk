#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

class A {
 public:
    ~A() {
        std::cout << "In destructor" << std::endl;
    }
};

int main() {
   auto ptr1(make_unique<A>());
   // auto ptr2 = ptr1;  // doesn't compile

   auto ptr3(make_shared<A>());
   std::cout << ptr3.use_count() << std::endl;
   auto ptr4 = ptr3;
   std::cout << ptr3.use_count() << std::endl;
}
