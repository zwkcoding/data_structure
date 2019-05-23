class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ans;
        if(input.size( ) == 0 || input.size( ) < k)
        {
            return ans;
        }
        priority_queue<int> pq(input.begin(), input.end());  // defalut is max heap
        for(int i = 0; i < input.size() - k; i++)  {
            pq.pop();
        }
        
        while(!pq.empty())  {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
        
        
    }
};
