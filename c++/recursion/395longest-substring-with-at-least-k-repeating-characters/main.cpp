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
