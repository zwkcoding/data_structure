class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n < 1 || m < 1)  {
            return -1;
        }
        vector<int> array;
        for(int i = 0; i < n; i++)  {
            array.push_back(i);
        }
        
        // 循环找到该数，并剔除
        int numbers_cnt = n;
        int cnt = 0;
        while(numbers_cnt > 1)  {
            for(int i = 1; i < m; i++)  {
                cnt++;
                cnt %= numbers_cnt;
            }
            // 删除该元素
            array.erase(array.begin( ) + cnt);
            numbers_cnt--;
            
        }
        return array[0];
    }
};
