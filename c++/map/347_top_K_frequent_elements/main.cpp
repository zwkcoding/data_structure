class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> fre_map;
        for(auto i : nums)  {
            fre_map[i]++;
        }
        
        vector<vector<int>> bucket(nums.size()+1);    // must add 1, in case of nums.size() == 1
        for(auto m : fre_map)  {
            // put element into bucket
            bucket[m.second].push_back(m.first);
        }
        
        vector<int> ans;
        for(int i = bucket.size()-1; i >= 0; i--)  {
            // Reverse order output
            for(auto n : bucket[i])  {
                ans.push_back(n);
                if(ans.size() == k)  {
                    return ans;
                }
            }
        }
        return ans;        
    }
};
