/*
Treat the column value as a base 26 number. Map A to 1, B to 2..., and Z to 26.

YZ = 25*(26^1) + 26*(26^0)
XYZ = 24*(26^2) + 25*(26^1) + 26*(26^0)
*/

class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for(int i = s.length(); i > 0; i--)  {
            ans += (s[i-1] + 1 - 'A') * pow(26,  (s.length() - i));
        }
        return ans;
        
    }
};
