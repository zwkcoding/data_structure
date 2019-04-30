#include "../../include/base.h"

/// 
/// Time Complexity: O()
/// Space Complexity: O()
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> sta;
        vector<int> ans;
        ans.resize(T.size(), 0);
        for(int i=0;i<T.size();i++){
            while(sta.empty() != true) {
                if(T[sta.top()] < T[i])  {
                    ans[sta.top()] = i - sta.top();
                    sta.pop();
                } else {
                    break;
                }
            }
            sta.push(i);
        }
        return ans;
    }

};


int main() {
    vector<int> first;
    vector<int> expectAns;

    first = {73, 74, 75, 71, 69, 72, 76, 73};
    expectAns = {1, 1, 4, 2, 1, 1, 0, 0};
    TEST_SMP1(Solution, dailyTemperatures, expectAns, first);

    first = {73, 74, 75, 71, 69, 72, 70, 73};
    expectAns = {1, 1, 0, 2, 1, 2, 1, 0};
    TEST_SMP1(Solution, dailyTemperatures, expectAns, first);

    first = {1,1,3,4};
    expectAns = {2,1,1,0};
    TEST_SMP1(Solution, dailyTemperatures, expectAns, first);
    return 0;
}
