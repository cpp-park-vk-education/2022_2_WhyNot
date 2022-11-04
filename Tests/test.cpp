// Copyright 2022 WhyNot

#include <gtest/gtest.h>

TEST(Test, Equation) {
    int x = 1;
    EXPECT_EQ(x, 1);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
