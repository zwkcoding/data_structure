
#include "../../include/base.h"

//  调试开关
// #define __tmain 
#ifdef __tmain
#define debug cout
#else
#define debug 0 && cout
#endif // __tmain

/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;
        int n = s.size();
        int mp[256] = {0};
        int len = 0;
        int cur = 0 ;
        // hashTable
        for(int i = 0; i < s.size(); i++)  {
            if(mp[s[i]] != 0)  {
                // 找到重复的字符
                len++;
                while(cur < mp[s[i]])  {
                    // 关键区别： 避免内层循环，形成一种滑窗。其实时间复杂度也等同于内层循环
                    len--;
                    mp[s[cur]] = 0;  // 清空
                    cur++;
                }
                mp[s[i]] = i + 1;  // 记住重复字符的更新位置
            } else {
                len++;
                mp[s[i]] = i + 1;  // 记住位置
                debug << len << endl;       
            } 
            if(len > ans) ans = len;  // 更新 ans
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
