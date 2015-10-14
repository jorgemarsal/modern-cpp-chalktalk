#include <iostream>
#include <boost/variant.hpp>

class LoggingVisitor
    : public boost::static_visitor<>
{
public:
    void operator()(const int & i) const {
        std::cout << "Visiting int" << std::endl;
    }
    void operator()(const std::string & str) const {
        std::cout << "Visiting string" << std::endl;
    }
};

int main() {
    boost::variant<int,std::string> variant1 = 6;

    auto int1 = boost::get<int>(variant1);  // ok

    try {
        auto str1 = boost::get<std::string>(variant1);  // fails
    }
    catch (const boost::bad_get& e) {
        std::cout << "fails" << std::endl;
    }

    boost::apply_visitor(LoggingVisitor(), variant1);

    boost::variant<int,std::string> variant2 = "hola";
    boost::apply_visitor(LoggingVisitor(), variant2);
}
