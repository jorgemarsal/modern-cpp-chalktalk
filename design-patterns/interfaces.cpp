#include <iostream>
#include <string>
#include <unordered_map>
#include <boost/any.hpp>

using GenericMap = std::unordered_map<std::string, boost::any>;

class Debuggable {
 public:
    virtual ~Debuggable() {}
    virtual GenericMap getDebugInfo() = 0;
};

class Configurable {
 public:
   virtual ~Configurable() {}
   virtual void configure(const GenericMap& config) = 0;
};

template <class T> 
class Iterable {
 public:
    virtual ~Iterable() {}
    virtual bool hasNext() = 0;
    virtual T next() = 0;
};

class BaseComponent : public Debuggable, public Configurable {
 public:
    virtual ~BaseComponent() {}
};

struct Record {

};

class Reader : public BaseComponent, public Iterable<Record> {
 public:
    Reader() : first_(true) {
    }

    GenericMap getDebugInfo() {
        GenericMap map;
        map["text"] = std::string("FYI");
        return map;
    }
    void configure(const GenericMap& config) {
        filename_ = boost::any_cast<std::string>(config.at("filename"));
    }
    bool hasNext() {
        if (first_) {
            first_ = false;
            return true;
        }
        return first_;
        
    }
    Record next() {
        return Record();
    }

 private:
    std::string filename_;
    bool first_;
};

int main() {
    Reader r;
    GenericMap config;
    config["filename"] = std::string("/tmp/file.txt");
    r.configure(config);
    while (r.hasNext()) {
        Record rec = r.next();
        std::cout << "Record consumed" << std::endl;
    }
    auto debugInfo = r.getDebugInfo();
}
