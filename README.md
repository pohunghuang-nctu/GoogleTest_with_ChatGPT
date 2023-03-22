# 使用 ChatGPT 製作一個 GoogleTest測試C語言程式範例
**除了這段粗體字, 其他的內容, 包含 C, CPP, README.md, 都是 ChatGPT 寫的**
本專案旨在使用GoogleTest框架編寫測試，測試一個包含兩個函式的簡單C語言程式。兩個函式分別為"switch_example"和"while_loop_example"，用於示範"switch"和"while"的用法。此測試程式旨在達到100%的分支覆蓋率和行覆蓋率。

## 目錄結構
本專案的目錄結構如下：
```
.
├── example.c
├── example.h
├── example_standalone.c
├── example_test_gpt4.cpp
├── example_test_gpt35.cpp
└── coverage_report_gpt4
└── coverage_report_gpt35
```
- example.c：被測試的C語言程式，包含switch_example和while_loop_example兩個函式。
- example.h：被測試程式的標頭檔案。
example_standalone.c：包含main函式的程式，用於獨立執行example.c中的函式。
- example_test_gpt4.cpp：使用GoogleTest編寫的針對example.c的測試程式（基於gpt4.0生成）。
- example_test_gpt35.cpp：使用GoogleTest編寫的針對example.c的測試程式（基於gpt3.5生成）。
- coverage_report_gpt4：基於example_test_gpt4生成的覆蓋率報告。
- coverage_report_gpt35：基於example_test_gpt35生成的覆蓋率報告。

## 編譯和執行測試
### 編譯測試程式
使用以下命令編譯測試程式：
```
g++ -std=c++11 -Wall --coverage -I/usr/src/gtest/include/gtest -L/usr/src/gtest/lib example.c example_test_gpt4.cpp -lgtest -lgtest_main -pthread -o example_test_gpt4
```
### 執行測試程式
使用以下命令執行測試程式：
```
./example_test_gpt4
```
### 生成覆蓋率報告
1. 使用以下命令生成覆蓋率報告：
```
lcov --capture --directory . --output-file coverage.info

```
2. 使用以下命令從報告中過濾掉系統和第三方檔案：
```
lcov --remove coverage.info '/usr/*' 'gtest/*' --output-file coverage_filtered.info
```
3. 使用以下命令生成HTML覆蓋率報告：
```
genhtml coverage_filtered.info --output-directory coverage_report_gpt4
```
## 參考資料
1. prompts to generate tested code.
```
/*
Treat yourself as a C language expert. please show me a simple C program, 
which contains 2 functions, one called "switch example", 
another called "while loop example". 
They are created only to demonstrate the usage of "switch" and "while". 
Later I would create test cases for these 2 functions, 
so, please return some integer values in these functions.
And also, I need this C program can be compiled by gcc.
*/
```
2. prompts to geneate test program
```
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
```



