// Copyright 2022 WhyNot

#include <gtest/gtest.h>
#include <algorithm>

TEST(Test, Equation) {
    int x = std::max(1, 2);
    EXPECT_EQ(x, 2);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}