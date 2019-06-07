
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
/// Space Complexity: O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;
        int n = s.size();
        int mp[256] = {0};  // hashTable
        int dp[n] = {0};
        // int len = 0;
        // int cur = 0 ;
        int last_index = 1;
        // dp 的初始条件
        dp[0] = 1;
        mp[s[0]] = 1;
        for(int i = 1; i < s.size(); i++)  {
            if(mp[s[i]] != 0)  {
                // 找到重复的字符
                // len++;
                // while(cur < mp[s[i]])  {
                //     len--;
                //     mp[s[cur]] = 0;  // 清空
                //     cur++;
                // }
                if(last_index <= mp[s[i]])  {
                    dp[i] = dp[i-1] - (mp[s[i]] - last_index);
                    last_index = mp[s[i]] + 1;
                } else {
                    dp[i] = dp[i-1] + 1; // 更新 
                }
                mp[s[i]] = i + 1;  // 记住重复字符的更新位置 index + 1
            } else {
                dp[i] = dp[i-1] + 1; // 更新
                mp[s[i]] = i + 1;  // 记住位置
            } 
            if(dp[i] > ans) ans = dp[i];  // 更新 ans
        }

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
