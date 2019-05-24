//  如果p是丑数，那么p=2^x * 3^y * 5^z
// 要注意，后面的丑数是有前一个丑数乘以2，3，5中的一个得来。因此可以用动态规划去解
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index < 7) return index;    // special case
        int x2 = 0, x3 = 0, x5 = 0, count = 1;
        vector<int> ans(index, 0);
        ans[0] = 1;
        while(count < index)  {
            int temp = min(ans[x2]*2, min(ans[x3]*3, ans[x5]*5));
            if(ans[x2]*2 == temp) x2++;
            if(ans[x3]*3== temp) x3++;
            if(ans[x5]*5 == temp) x5++;
            ans[count++]= temp;
        }
        return ans[index - 1];
    }
};
