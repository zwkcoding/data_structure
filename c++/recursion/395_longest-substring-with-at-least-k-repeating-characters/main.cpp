/*
 * Filename: /home/zwk/code/data_structrue/c++/recursion/395longest-substring-with-at-least-k-repeating-characters/main.cpp
 * Path: /home/zwk/code/data_structrue/c++/recursion/395longest-substring-with-at-least-k-repeating-characters
 * Created Date: Tuesday, May 14th 2019, 6:49:25 pm
 * Author: zwk
 * 
 * Copyright (c) 2019 Your Company
 */

#include "../../include/base.h"

/// Time Complexity: O(n)
/// Space Complexity: O(nlogn) worst case
class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() == 0 || k > s.size())   return 0;
        if(k == 0)  return s.size();
        
        unordered_map<char,int> map;
        for(auto i : s)  {
            map[i]++;
        }
        
        int mid = 0;
        while(mid < s.size() && map[s[mid]] >= k) mid++;
        if (mid == s.size()) return s.size();
        int left = longestSubstring(s.substr(0,mid),k);
        while(mid < s.size() && map[s[mid]] < k) mid++;
        if(mid == s.size()) return left;
        int right = longestSubstring(s.substr(mid),k);
        return max(left, right);
    }
};


int main() {
    string first;
    int second;
    int expectAns;

    first =  "aaabb";
    second = 3;
    expectAns = 3;
    TEST_SMP2(Solution, longestSubstring, expectAns, first, second);

    first =  "ababbc";
    second = 2;
    expectAns = 5;
    TEST_SMP2(Solution, longestSubstring, expectAns, first, second);

    return 0;
}
