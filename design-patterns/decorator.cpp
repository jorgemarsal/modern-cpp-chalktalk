#include <iostream>
#include <memory>

class IDownloader {
 public:
    virtual ~IDownloader() {}
    virtual void download() = 0;
};

class SimpleDownloader : public IDownloader {
 public:
    void download() {
       std::cout << "Downloading ..." << std::endl;
    }

};

class LoggingDownloader : public IDownloader {
 public:
    LoggingDownloader(std::unique_ptr<IDownloader> downloader) {
        downloader_ = std::move(downloader);
    }

    void download() {
        std::cout << "begin log" << std::endl;
        downloader_->download();
        std::cout << "end log" << std::endl;
    }
 private:
    std::unique_ptr<IDownloader> downloader_;
};

int main () {
    auto simpleDownloader(
        std::unique_ptr<IDownloader>(std::make_unique<SimpleDownloader>()));
    auto loggingDownloader(std::unique_ptr<IDownloader>(
        std::make_unique<LoggingDownloader>(
            std::unique_ptr<IDownloader>(std::make_unique<SimpleDownloader>())
    )));

    simpleDownloader->download();
    loggingDownloader->download();
}
