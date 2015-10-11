#include <gtest/gtest.h>

class Calculator {
 public:
    static uint64_t sum(const uint64_t op1, const uint64_t op2) {
        return op1 + op2;
    }
    static uint64_t mul(const uint64_t op1, const uint64_t op2) {
        return op1 * op2;
    }
};

struct MyConfig {
    MyConfig(const uint64_t op1,
             const uint64_t op2) : op1_(op1), op2_(op2) {
    }

    const uint64_t op1_;
    const uint64_t op2_;
};

::std::ostream& operator<<(::std::ostream& os, const MyConfig& config) {
  return os << "op1: " << config.op1_ << " op2: " << config.op2_;
}

class MyTest : public ::testing::TestWithParam<MyConfig> {

};

TEST_P(MyTest, Sum) {
    const MyConfig& conf = GetParam();
    EXPECT_EQ(Calculator::sum(conf.op1_,conf.op2_), conf.op1_ + conf.op2_);
}

TEST_P(MyTest, Multiply) {
    const MyConfig& conf = GetParam();
    EXPECT_EQ(Calculator::mul(conf.op1_,conf.op2_), conf.op1_ * conf.op2_);
}

INSTANTIATE_TEST_CASE_P(MyValues, MyTest, ::testing::Values(
    MyConfig(1,2),
    MyConfig(3,4)
));

