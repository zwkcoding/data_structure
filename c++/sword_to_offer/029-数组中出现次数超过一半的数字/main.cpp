class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        
        unordered_map<int, int> mp;
        if(numbers.size()  == 0) return -1;
        int tar_n = numbers.size() / 2;
        for(auto i : numbers)  {
            mp[i]++;
        }
        for(auto i : mp)  {
            if(i.second > tar_n)  {
                return i.first;
            }
        }
        return 0;
    
    }
};
