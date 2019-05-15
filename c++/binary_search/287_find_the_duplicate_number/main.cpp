/// Time Complexity: O(nlogn)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size();
        while(low < high)  {
            int count = 0;
            int mid = low + ((high-low)>>1);
            for(auto i : nums)  {
                if(i <= mid)  {
                    count++;
                }
            }
            if(count <= mid)  low = mid + 1;
            else high = mid;
        }
        return low;
    }
};
