// 维护一个递增队列
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> ans;
        if(num.size() == 0)  return ans;
        if(size == 0) return ans;
        int n = num.size();
        if(size > n) return ans;
        deque<int> qu;
        for(int i = 0; i < n; i++)  {
            while(qu.size() > 0 && num[qu.back()] < num[i])  qu.pop_back();    // 保证队首为最大值,且队列元素
            while(qu.size() > 0 && i - qu.front() + 1 > size)  qu.pop_front();    // 保证处于当前滑窗
            qu.push_back(i);    // 插入队列后面
            if(qu.size() > 0 &&  i + 1 >= size)  {
                ans.push_back(num[qu.front()]);        // 插入当前队列最大值
            }
        }
        return ans;
    }
};
