int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1, kth;
        while (true) {
        
        
// ref1:https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C%2B%2B-STL-partition-and-heapsort
// ref2: https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60294/Solution-explained
// max-heap 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        // max_heap
        for(int i = 0; i < k - 1; i++)  {
            pq.pop();
        }
        return pq.top();
    }
};
