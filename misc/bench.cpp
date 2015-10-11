#include <folly/Benchmark.h>
#include <folly/Foreach.h>
#include <vector>

using namespace std;
using namespace folly;

BENCHMARK(copy) {
    vector<uint64_t> v;
    v.resize(128*1024*1024);
    FOR_EACH_RANGE (i, 0, 1) {
        vector<uint64_t> v2(v);
    }
}

BENCHMARK(move) {
    vector<uint64_t> v;
    v.resize(128*1024*1024);
    FOR_EACH_RANGE (i, 0, 1) {
        vector<uint64_t> v2(std::move(v));
    }
}

int main() {
    runBenchmarks();
}
