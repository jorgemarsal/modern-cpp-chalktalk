#include <iostream>
#include <memory>

class Downloader {
 public:
    virtual ~Downloader() {}
    virtual void download() = 0;
};

class SimpleDownloader : public Downloader {
 public:
    void download() {
       std::cout << "Downloading ..." << std::endl;
    }

};

class LoggingDownloader : public Downloader {
 public:
    LoggingDownloader(std::unique_ptr<Downloader> downloader) {
        downloader_ = std::move(downloader);
    }

    void download() {
        std::cout << "begin log" << std::endl;
        downloader_->download();
        std::cout << "end log" << std::endl;
    }
 private:
    std::unique_ptr<Downloader> downloader_;
};

int main () {
    auto simpleDownloader(
        std::unique_ptr<Downloader>(std::make_unique<SimpleDownloader>()));
    auto twiceDownloader(std::unique_ptr<Downloader>(
        std::make_unique<LoggingDownloader>(
            std::unique_ptr<Downloader>(std::make_unique<SimpleDownloader>())
    )));

    simpleDownloader->download();
    twiceDownloader->download();
}
