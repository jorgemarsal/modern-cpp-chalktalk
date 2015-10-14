#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <boost/any.hpp>
#include <boost/range/irange.hpp>

using GenericMap = std::unordered_map<std::string, boost::any>;

class INotifiable {
 public:
    virtual ~INotifiable() {}
    virtual void onEvent(const GenericMap& data) const = 0;
};

class EventLogger : public INotifiable {
 public:
    void onEvent(const GenericMap& data) const {
        const std::string& text = boost::any_cast<std::string>(data.at("text"));
        std::cout << text << std::endl;
    }
};

class Reader {
 public:
    void addObserver(INotifiable* observer) {
        observers_.push_back(observer);
    }
    void read() const {
        GenericMap map;
        map["text"] = std::string("FYI");
        for (auto i : boost::irange(0,1)) {
            for (auto observer : observers_) {
                observer->onEvent(map);
            }
        }
    }
 private:
    std::vector<INotifiable*> observers_;

};

int main() {
    EventLogger ev1;
    EventLogger ev2;
    Reader r;
    r.addObserver(static_cast<INotifiable*>(&ev1));
    r.addObserver(static_cast<INotifiable*>(&ev2));
    r.read();
}
