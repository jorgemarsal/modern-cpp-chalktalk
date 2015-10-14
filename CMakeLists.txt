cmake_minimum_required(VERSION 2.8)

SET (CMAKE_CXX_COMPILER "/usr/bin/clang++-3.6")

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

ADD_EXECUTABLE(decorator design-patterns/decorator.cpp)
ADD_EXECUTABLE(factory design-patterns/factory.cpp)
ADD_EXECUTABLE(interfaces design-patterns/interfaces.cpp)
ADD_EXECUTABLE(observer design-patterns/observer.cpp)

ADD_EXECUTABLE(debug misc/debug.cpp)
ADD_EXECUTABLE(smart misc/smart.cpp)
ADD_EXECUTABLE(any misc/any.cpp)
ADD_EXECUTABLE(variant misc/variant.cpp)

ADD_EXECUTABLE(asan_bad tooling/asan.cpp)
ADD_EXECUTABLE(asan_ex tooling/asan.cpp)
SET_TARGET_PROPERTIES(asan_ex PROPERTIES
  COMPILE_FLAGS "-fsanitize=address"
  LINK_FLAGS "-fsanitize=address"
)

ADD_EXECUTABLE(tsan_good tooling/tsan_good.cpp)
TARGET_LINK_LIBRARIES(tsan_good pthread)

ADD_EXECUTABLE(tsan_bad tooling/tsan.cpp)
TARGET_LINK_LIBRARIES(tsan_bad pthread)

ADD_EXECUTABLE(tsan_ex tooling/tsan.cpp)
TARGET_LINK_LIBRARIES(tsan_ex pthread)
SET_TARGET_PROPERTIES(tsan_ex PROPERTIES
  COMPILE_FLAGS "-fsanitize=thread"
  LINK_FLAGS "-fsanitize=thread"
)

ADD_EXECUTABLE(tests testing/tests.cpp testing/driver.cpp)
TARGET_LINK_LIBRARIES(tests gmock gtest pthread)
ADD_EXECUTABLE(mock testing/mock.cpp testing/driver.cpp)
TARGET_LINK_LIBRARIES(mock gmock gtest pthread)

ADD_EXECUTABLE(bench misc/bench.cpp)
TARGET_LINK_LIBRARIES(bench folly follybenchmark glog)

ADD_EXECUTABLE(tolint linting/tolint.cpp)
