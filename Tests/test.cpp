// Copyright 2022 WhyNot

#include <gtest/gtest.h>

TEST(Test, Equation) {
    EXPECT_EQ(0, 0);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
