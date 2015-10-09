#include <boost/variant.hpp>

int main() {
    boost::variant<int,std::string> variant1 = 6;

    switch (variant1.which()) {
        case 0: {
            std::cout << "int" << std::endl; 
            break;
        }
        case 1: {
            std::cout << "string" << std::endl; 
            break;
        }
        default: {
            std::cout << "duno ..." << std::endl;
            break;
        }
    }

    auto int1 = boost::get<int>(variant1);  // ok

    try {
        auto str1 = boost::get<std::string>(variant1);  // fails
    }
    catch (const boost::bad_get& e) {
        std::cout << "fails" << std::endl;
    }
    
}
