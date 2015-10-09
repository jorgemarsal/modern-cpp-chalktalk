#include <iostream>
#include <string>
#include <unordered_map>
#include <boost/any.hpp>
#include <boost/range/irange.hpp>

using GenericMap = std::unordered_map<std::string, boost::any>;

class EventLogger {
 public:
    void onLineConsumed(const GenericMap& data) const {
        const std::string& text = boost::any_cast<std::string>(data.at("text"));
        std::cout << text << std::endl;
    }
};

class Reader {
 public:
    void addEventLogger(const EventLogger& eventLogger) {
        eventLoggers_.push_back(eventLogger);
    }
    void read() const {
        GenericMap map;
        map["text"] = std::string("FYI");
        for (auto i : boost::irange(0,1)) {
            for (auto eventLogger : eventLoggers_) {
                eventLogger.onLineConsumed(map);
            }
        }
    }
 private:
    std::vector<EventLogger> eventLoggers_;

};

int main() {
    EventLogger ev1;
    EventLogger ev2;
    Reader r;
    r.addEventLogger(ev1);
    r.addEventLogger(ev2);
    r.read();
}
