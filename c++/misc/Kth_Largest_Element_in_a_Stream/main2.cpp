class Solution {
private:
    int partition(int l, int h, vector<int>& nums)  {
        int pivot = nums[h];
        int i = l;
        for(int j = l; j <= h; j++)  {
            if(nums[j] < pivot)  {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[h]);
        return i;   
    }
public:
   int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo < hi) {
            int j = partition(lo, hi, nums);
            if(j < k)  {
                lo++;
            }else if(j > k)  {
                hi--;
            }else {
               break;
            }
        }
        return nums[k];
    }
    
};
