class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector< vector<int> > res;
        vector<int> currRes;

        if(sum < 3)
        {
            return res;
        }

        int begin = 1, end = 2, mid = (sum + 1) / 2;
        int currSum = begin + end;
        while(begin < mid && end < sum)  {
            if(currSum < sum)  {
                end += 1;
                currSum += end;  // 增加一个大数
            } else if(currSum > sum)  {
                currSum -= begin;  // 减去一个小数
                begin += 1;
            } else {
                // 找到一个结果集
                currRes.resize(0);
                for(int i = begin; i <= end; i++)  {
                    currRes.push_back(i);
                }
                res.push_back(currRes);
                // 继续前行
                currSum -= begin;  // 减去当前的小数
                begin += 1;    // 推进
            }
        }
        return res;
    }
};
