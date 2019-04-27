/*
 * @Author: Zhou WenKai 
 * @Date: 2019-04-27 20:34:19 
 * @Last Modified by: Zhou WenKai
 * @Last Modified time: 2019-04-27 20:57:41
 */



#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<time.h>
#include "../../include/base.h"
using namespace std;


#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

typedef unsigned uint;
typedef unsigned char uchar;
auto __ =[]() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}
();

/// count method
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count_one = 0;
        int ans  = 0;
        for(int i = 0; i < nums.size(); i++)  {
            if(nums[i] == 1)  {
                count_one++;
                ans = max(ans, count_one);
            } else {
                count_one = 0;
            }
        }
        /// more simple
        /*
        int max_cnt =0, cnt = 0;
        for(auto n : nums)  {
            if ( n == 1) max_cnt = max(max_cnt,  ++cnt);
            else cnt = 0;
        }
        return max_cnt;
        */
        return ans;
    }
};

template <class ansType, class dataType1, class dataType2 = int>
void test(ansType& expectAns, dataType1& firstData, dataType2 secondData = dataType2()) {
    Solution work;
    ansType ans;
    ans = work.findMaxConsecutiveOnes(firstData);

    static int index = 0;
    index++;
    bool check = eq(ans, expectAns);
    printf("\n");
    if(!check) {
        printf("index %d: NO\n", index);
        output("firstData", firstData);
        output("ans", ans);
        output("expectAns", expectAns);
    } else {
        printf("index %d: YES\n", index);
    }
    printf("\n");

}

int main() {
    vector<int> first;
    int expectAns;


    first = {1,1,0,1,1,1};
    expectAns = 3;
    test(expectAns, first);


    first = {1,1,0};
    expectAns = 2;
    test(expectAns, first);


    first = {0, 1,1};
    expectAns = 2;
    test(expectAns, first);


    first = {0, 1,1, 0};
    expectAns = 2;
    test(expectAns, first);



    first = {1,1};
    expectAns = 2;
    test(expectAns, first);



    first = {0,0,0};
    expectAns = 0;
    test(expectAns, first);

    first = {0,0,1};
    expectAns = 1;
    test(expectAns, first);
    return 0;
}
