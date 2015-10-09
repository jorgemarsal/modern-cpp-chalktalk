#include <iostream>
#include <memory>

class Reader {
 public:
    virtual ~Reader() {}
    virtual void read() = 0;
};

class LocalReader : public Reader {
 public:
    void read() {
        std::cout << "Reading from local FS" << std::endl;
    }
};

class HdfsReader : public Reader {
 public:
    void read() {
        std::cout << "Reading from HDFS" << std::endl;
    }

};

class ReaderFactory {
 public:
    static std::unique_ptr<Reader> makeReader(const std::string& type) {
        if (type == "local") {
            return std::unique_ptr<Reader>(std::make_unique<LocalReader>());
        }
        else if (type == "hdfs") {
            return std::unique_ptr<Reader>(std::make_unique<HdfsReader>());
        }
        else {
            throw std::runtime_error("Unsupported type");
        }       
    }
};

int main() {
    auto reader1 = ReaderFactory::makeReader("local");
    reader1->read();
    auto reader2 = ReaderFactory::makeReader("hdfs");
    reader2->read();
}
