/*
 * Filename: /home/zwk/code/data_structrue/c++/string/strStr/main.cpp
 * Path: /home/zwk/code/data_structrue/c++/string/strStr
 * Created Date: Wednesday, June 26th 2019, 8:03:04 pm
 * Author: zwk
 * 
 * Copyright (c) 2019 Your Company
 */


#include "../../include/base.h"

/// ref:  http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/　　　
/// ref: https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

/// KMP
/// Time Complexity:  worst: O(n) 
/// Space Complexity: O(m).
class Solution {
public:
      void computeLPSArray(string& pat, vector<int>& lps)  {
         int n = pat.size();
         for(int i = 1, len = 0; i < n;)  {
            if(pat[i] == pat[len])  {
                len++;  
                lps[i] = len;
                i++;
            } else if(len)  {
                len = lps[len-1];
            } else {
                lps[i] = 0;
                i++;
            }  
         } 
     }
     int strStr(string txt, string pat) {
         int m = txt.size(), n = pat.size();
         if(!n) return 0;
         vector<int> lps(n, 0);
         // make partial match table
         computeLPSArray(pat, lps);
         // kmp process
         int i = 0, j = 0;
         while(i < m)  {
             if(txt[i] == pat[j])  {
                 i++;
                 j++;
             }
             if(j == n)  {
                 // return first occurrence
                 return i-j;
             }
             else if(i < m && txt[i] != pat[j])  {
                 j ? j = lps[j-1] : i++;
             }    
         }
        return -1;
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


