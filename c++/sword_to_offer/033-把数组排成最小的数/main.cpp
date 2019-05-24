template<class T>
string ToString(const T& t)
{

    ostringstream oss;  //  创建一个流

    oss <<t;            //  把值传递如流中
    return oss.str( );  //  获取转换后的字符转并将其写入result
}

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> str_vec;
        for(auto i : numbers)  {
            // push into str_vec
            str_vec.push_back(ToString(i));
        }
        ///  对字符串按照拼接后的大小进行排序
        sort(str_vec.begin(), str_vec.end(),[](string const &l, string const &r) { return l + r <  r + l; });
        string ans;
        for(auto s: str_vec)  {
            ans += s;    // 拼接结果
        }
        return ans;
  
    }
};
