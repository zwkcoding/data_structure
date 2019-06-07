/*
 * Filename: /home/zwk/code/data_structrue/c++/leetcode/3_Longest Substring Without Repeating Characters    /main4.cpp
 * Path: /home/zwk/code/data_structrue/c++/leetcode/3_Longest Substring Without Repeating Characters    
 * Created Date: Friday, June 7th 2019, 2:18:12 pm
 * Author: zwk
 * 
 * Copyright (c) 2019 Your Company
 */

// ref : http://www.ahathinking.com/archives/123.html

#include "../../include/base.h"

//  调试开关
// #define __tmain 
#ifdef __tmain
#define debug cout
#else
#define debug 0 && cout
#endif // __tmain

/// dp + hash 
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
    int maxlen, maxindex;
    void output(char * arr)
{
    if(maxlen == 0)
    {
        printf("NO LNRS\n");
    }
    printf("The len of LNRS is %d\n",maxlen);
 
    int i = maxindex;
    while(maxlen--)
    {
        printf("%c",arr[i++]);
    }
    printf("\n");
}
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;
        int n = s.size();
        int mp[256] = {0};  // hashTable
        // int dp[n] = {0};
        // int len = 0;
        // int cur = 0 ;
        int last_index = 1;

        // mp[s[0]] = 1;
        int len = 0;
        for(int i = 0; i < s.size(); i++)  {
            if(mp[s[i]] != 0)  {
                // 找到重复的字符             
                // len++;
                // while(cur < mp[s[i]])  {
                //     len--;
                //     mp[s[cur]] = 0;  // 清空
                //     cur++;
                // }
                if(last_index <= mp[s[i]])  {
                    len = len - (mp[s[i]] - last_index);
                    last_index = mp[s[i]] + 1;
                } else {
                   len++; // 更新
                }
                mp[s[i]] = i + 1;  // 记住重复字符的更新位置
            } else {
                len++; // 更新
                mp[s[i]] = i + 1;  // 记住位置
            } 
            if(len > ans) ans = len;  // 更新 ans
        }

        maxlen = ans;
        maxindex = last_index - 1;

        output((char*)s.data());
        return ans;
    }
};


int main() {
    string first;
    int ans, expectAns;

    first =  "abcabcbb";
    expectAns = 3;
    TEST_SMP1(Solution, lengthOfLongestSubstring, expectAns, first);

    first =  "bbbbb";
    expectAns = 1;
    TEST_SMP1(Solution, lengthOfLongestSubstring, expectAns, first);

    first =  "pwwkew";
    expectAns = 3;
    TEST_SMP1(Solution, lengthOfLongestSubstring, expectAns, first);

     first =  "au";
    expectAns = 2;
    TEST_SMP1(Solution, lengthOfLongestSubstring, expectAns, first);


    return 0;
}
