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

// Tests for switch_example function
TEST(SwitchExampleTest, Value1) {
    // Test when value is 1
    int result = switch_example(1);
    EXPECT_EQ(result, 10);
}

TEST(SwitchExampleTest, Value2) {
    // Test when value is 2
    int result = switch_example(2);
    EXPECT_EQ(result, 20);
}

TEST(SwitchExampleTest, Value3) {
    // Test when value is 3
    int result = switch_example(3);
    EXPECT_EQ(result, 30);
}

TEST(SwitchExampleTest, DefaultValue) {
    // Test when value is not 1, 2, or 3
    int result = switch_example(4);
    EXPECT_EQ(result, 0);
}

// Tests for while_loop_example function
TEST(WhileLoopExampleTest, Count0) {
    // Test when count is 0
    int result = while_loop_example(0);
    EXPECT_EQ(result, 0);
}

TEST(WhileLoopExampleTest, Count1) {
    // Test when count is 1
    int result = while_loop_example(1);
    EXPECT_EQ(result, 0);
}

TEST(WhileLoopExampleTest, Count5) {
    // Test when count is 5
    int result = while_loop_example(5);
    EXPECT_EQ(result, 10);
}

// Run all the tests that were declared with TEST()
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*
(1) Compile the test program with the following command:
g++ -std=c++11 -Wall --coverage -I/usr/src/gtest/include/gtest -L/usr/src/gtest/lib example.c example_test_gpt35.cpp -lgtest -lgtest_main -pthread -o example_test_gpt35
(2) Run the test program with the following command:
./example_test_gpt35
(3) Generate the coverage report with the following command:
lcov --capture --directory . --output-file coverage_gpt35.info
(4) Filter out system and third-party files from the report:
lcov --remove coverage_gpt35.info '/usr/*' 'gtest/*' --output-file coverage_filtered_gpt35.info
(5) Generate an HTML coverage report:
genhtml coverage_filtered_gpt35.info --output-directory coverage_report_gpt35
*/
