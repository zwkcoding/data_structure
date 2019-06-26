/*
 * Filename: /home/zwk/code/data_structrue/c++/string/strStr/main.cpp
 * Path: /home/zwk/code/data_structrue/c++/string/strStr
 * Created Date: Wednesday, June 26th 2019, 8:03:04 pm
 * Author: zwk
 * 
 * Copyright (c) 2019 Your Company
 */


#include "../../include/base.h"

/// brute force
/// Time Complexity:  O(m*n) 
/// Space Complexity: O(1).
class Solution {
public:
     int strStr(string tot, string ele) {
         int ans = 0;
         if(ele.size() == 0 ) return ans;
         if(tot.size() == 0 || tot.size() < ele.size())  return -1;
         int i , j;
         int pos = 0;
         for(i = 0, j = 0; i < tot.size()  && j < ele.size(); i++)  {
             if(tot[i] == ele[j])  {
                 j++;
             } else  {
                 i  = i - j;        // 从上一个匹配的下一个位置开始重新开始匹配
                 j = 0;
                 pos = i + 1;       // 记住开始匹配的位置
             }
         }
         return (j == ele.size()) ? pos : -1;
    }
};


int main() {
    string first;
    string second;
    int ans, expectAns;

    first = "hello";
    second = "ll";
    expectAns = 2;
    TEST_SMP2(Solution, strStr, expectAns, first, second);

    first = "aaaaa";
    second = "bba";
    expectAns = -1;
    TEST_SMP2(Solution, strStr, expectAns, first, second);

    return 0;
}


