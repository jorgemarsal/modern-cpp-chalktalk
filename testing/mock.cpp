#include <gmock/gmock.h>
#include <gtest/gtest.h>

class ICalculator {
 public:
    virtual uint64_t sum (const uint64_t op1, const uint64_t op2) = 0;
    virtual uint64_t mul (const uint64_t op1, const uint64_t op2) = 0;
};

class OnlineCalculator : public ICalculator {
 public:
    uint64_t sum(const uint64_t op1, const uint64_t op2) {
        throw std::runtime_error("Unimplemented");
    }
    uint64_t mul(const uint64_t op1, const uint64_t op2) {
        throw std::runtime_error("Unimplemented");
    }
};

class MockCalculator : public ICalculator {
public:
    MOCK_METHOD2(sum, uint64_t(const uint64_t, const uint64_t));
    MOCK_METHOD2(mul, uint64_t(const uint64_t, const uint64_t));
};

TEST(testcase, test) {
    using ::testing::Return;
    using ::testing::_;

    MockCalculator c;

    EXPECT_CALL(c, sum(_,_))
        .Times(2)
        .WillOnce(Return(3))
        .WillOnce(Return(7));
    EXPECT_CALL(c, mul(_,_))
        .Times(2)
        .WillOnce(Return(2))
        .WillOnce(Return(12));


    EXPECT_EQ(c.sum(1,2), 3);
    EXPECT_EQ(c.sum(3,4), 7);

    EXPECT_EQ(c.mul(1,2), 2);
    EXPECT_EQ(c.mul(3,4), 12);
}
