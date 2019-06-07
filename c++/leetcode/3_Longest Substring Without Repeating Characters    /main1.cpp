
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
        if(s.size() == 0) return ans;
        unordered_map<int, int> mp;  // 记录出现次数
        // 暴力破解
        for(int i = 0; i < s.size();)  {
            mp.clear();  // 清空map，重新记录
            mp[s[i]] = i;
            int count = 1;
            int j = 0;
            for(j = i+1; j < s.size(); j++)  {
                if(mp.find(s[j]) == mp.end())  {
                    mp[s[j]] = j;
                    count++;
                } else {
                    break;
                }
            }
            if(count > ans) ans = count;
            debug << mp[s[j]] << endl;
            i = mp[s[j]] + 1;  // 从重复元素下一个元素开始
            if(i == s.size() - 1)  break;  // 遍历到最后的元素退出

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

    // first =  "bbbbb";
    // expectAns = 1;
    // TEST_SMP1(Solution, lengthOfLongestSubstring, expectAns, first);

    // first =  "pwwkew";
    // expectAns = 3;
    // TEST_SMP1(Solution, lengthOfLongestSubstring, expectAns, first);

    return 0;
}
