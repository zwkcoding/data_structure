class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int head = 0;
        int end = array.size() - 1;
        vector<int> res;
        if (array.size( ) < 2)
        {
            return res;
        }
        
        int two_sum = array[head] + array[end];
        while(head <= end)  {
            two_sum = array[head] + array[end];
            if(two_sum > sum)  {
                end--;
            } else if(two_sum < sum)  {
                head++;
            } else {
                ///  左右夹逼
                ///  相隔距离越远，乘积也越小
                ///  从两端分别向中间走，先找到的那一对和一定最小
                res.push_back(array[head]);
                res.push_back(array[end]);
                break;
            }
        }
        return res;
    }
};
