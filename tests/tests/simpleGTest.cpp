//
// Created by Mark Minch  on 11/28/23.
//

#include <string>
#include <iostream>
#include <gtest/gtest.h>

TEST(HelloTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

