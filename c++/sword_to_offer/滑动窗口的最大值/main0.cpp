class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> ans;
        if(num.size() == 0)  return ans;
        if(size == 0) return ans;
        int n = num.size();
        if(size > n) return ans;
        int max = INT_MIN;
        for(int i = 0; i <= n - size; i++)  {
            max = num[i];
            for(int j = i; j < i+size; j++)  {
                if(num[j] > max) max = num[j];
            }
            ans.push_back(max);
        }
        return ans;
    }
};
