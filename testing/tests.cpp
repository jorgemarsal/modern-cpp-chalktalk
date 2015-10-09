#include <gtest/gtest.h>

struct MyConfig {
    MyConfig(const int number) : number_(number) {
    }

    const int number_;
};

::std::ostream& operator<<(::std::ostream& os, const MyConfig& config) {
  return os << config.number_;
}

class MyTest : public ::testing::TestWithParam<MyConfig> {

};

TEST_P(MyTest, Example1) {
    const MyConfig& conf = GetParam();
    EXPECT_EQ(conf.number_, 1);
}

TEST_P(MyTest, Example2) {
    const MyConfig& conf = GetParam();
    EXPECT_EQ(conf.number_, 2);
}

INSTANTIATE_TEST_CASE_P(MyValues, MyTest, ::testing::Values(
    MyConfig(1),
    MyConfig(2)
));

