
#include "../../include/base.h"

/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        if(s.size() == 0) return ans;
        unordered_map<int, int> mp;  // 记录出现次数
        // 暴力破解
        for(int i = 0; i < s.size(); i++)  {
            mp.clear();  // 清空map，重新记录
            mp[s[i]]++;
            int count = 1;
            for(int j = i+1; j < s.size(); j++)  {
                if(mp.find(s[j]) == mp.end())  {
                    mp[s[j]]++;
                    count++;
                } else {
                    break;
                }
            }
            if(count > ans) ans = count;
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

    return 0;
}
