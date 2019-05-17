class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n - 3; i++)  {
            // first num
            if(i > 0 && nums[i]  == nums[i-1]) continue;
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)  break;
            if(nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target)  continue;
            
            // second num
            for(int j = i + 1; j < n - 2; j++)  {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                if(nums[j] + nums[i] + nums[j+1] + nums[j+2] > target)  break;
                if(nums[j] + nums[i] + nums[n-2] + nums[n-1] < target)  continue;
                
                int l = j+1, h = n -1, t = target - nums[j]-nums[i];
                while(l < h)  {
                    // double pointers skills
                   if(l > j+1 && nums[l] == nums[l-1]) {l++; continue;}
                   if(nums[l] + nums[h] < t)  l++;
                   else if(nums[l] + nums[h] > t)  h--;
                   else  {
                       // vector<int> ans_t;
                       // ans_t.push_back(nums[i]);
                       // ans_t.push_back(nums[j]);
                       // ans_t.push_back(nums[l]);
                       // ans_t.push_back(nums[h]);
                       // ans.push_back(ans_t);
                       ans.push_back({nums[i],nums[j],nums[l++],nums[h--]});
                   }
                    
                }

            }
        }
        return ans;       
    }
};
