class Solution {
public:
    string ReverseSentence(string str) {
        if(str.size() < 2 )
        {
            return str;
        }
        string res = "", tmp = "";
        for(unsigned int i = 0; i < str.size(); i++)  {
            if(str[i] == ' ')  {
                // 遇到空格，代表找到一个单词
                res = " " + tmp + res;  // 中间用空格拼接, 注意这里不要使用 `+=`
                tmp = "";
            } else  {
                // 没有遇到空格，还在等待一个单词结束
                tmp += str[i];
            }
        }
        if(tmp.size() != 0) {
            // 最后一个单词还没有拼接
             res = tmp + res;  // 最后一个单词不需要空格
        }
        return res;
    }
};
