class Solution {
public:
    // 对于abcXYZdef，考虑他的自连接串abcXYZdefabcXYZdef，新的串正好是链接串的一个子串
    // 新的串是两倍串第len位起始长度为n字串
    string LeftRotateString(string str, int n) {
        if(str.size() == 0)  return str;
        int length = str.size();
        n %= str.size();
        str += str;
        return str.substr(n, length);
    }
};
