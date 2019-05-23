class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> ans;
        if(str.empty())  {
            return ans;
        }
        sort(str.begin(), str.end());
        do  {
            ans.push_back(str);
        }
        while(next_permutation(str.begin( ), str.end( )));
        return ans;
    }
};
