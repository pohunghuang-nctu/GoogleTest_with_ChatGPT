/*
Treat your self as an expert of GoogleTest Platform. 
Please compose a test program to test below 2 functions. 
I need 100 percent branch coverage and line coverage, 
and the test program must be written in C language.
int switch_example(int value) {
    int result;
    switch (value) {
        case 1:
            result = 10;
            break;
        case 2:
            result = 20;
            break;
        case 3:
            result = 30;
            break;
        default:
            result = 0;
    }
    return result;
}

int while_loop_example(int count) {
    int i = 0;
    int sum = 0;
    while (i < count) {
        sum += i;
        i++;
    }
    return sum;
} 
*/

#include <gtest/gtest.h>

// Include the header file with the functions to be tested
#include "example.h"


// Test cases for switch_example
TEST(SwitchExampleTest, Case1) {
    EXPECT_EQ(switch_example(1), 10);
}

TEST(SwitchExampleTest, Case2) {
    EXPECT_EQ(switch_example(2), 20);
}

TEST(SwitchExampleTest, Case3) {
    EXPECT_EQ(switch_example(3), 30);
}

TEST(SwitchExampleTest, DefaultCase) {
    EXPECT_EQ(switch_example(0), 0);
    EXPECT_EQ(switch_example(4), 0);
    EXPECT_EQ(switch_example(-1), 0);
}

// Test cases for while_loop_example
TEST(WhileLoopExampleTest, ZeroCount) {
    EXPECT_EQ(while_loop_example(0), 0);
}

TEST(WhileLoopExampleTest, PositiveCount) {
    EXPECT_EQ(while_loop_example(1), 0);
    EXPECT_EQ(while_loop_example(5), 10);
    EXPECT_EQ(while_loop_example(10), 45);
}

// Run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
/*
(1) Compile the test program with the following command:
g++ -std=c++11 -Wall --coverage -I/usr/src/gtest/include/gtest -L/usr/src/gtest/lib example.c example_test_gpt4.cpp -lgtest -lgtest_main -pthread -o example_test_gpt4
(2) Run the test program with the following command:
./example_test_gpt4
(3) Generate the coverage report with the following command:
lcov --capture --directory . --output-file coverage.info
(4) Filter out system and third-party files from the report:
lcov --remove coverage.info '/usr/*' 'gtest/*' --output-file coverage_filtered.info
(5) Generate an HTML coverage report:
genhtml coverage_filtered.info --output-directory coverage_report_gpt4
*/