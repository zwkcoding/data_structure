/*
 * @Author: Zhou WenKai 
 * @Date: 2019-04-28 18:39:38 
 * @Last Modified by: Zhou WenKai
 * @Last Modified time: 2019-04-28 19:41:07
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

/// fast-slow pointers
/// ref: https://leetcode.com/explore/learn/card/array-and-string/205/array-two-pointer-technique/1299/discuss/59090/C%2B%2B-O(n)-and-O(nlogn)/268464
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = INT_MAX ;
        int sum = 0;
        int f_p = 0, s_p = 0;
        if(nums.size() == 1)  {
            if(nums[0] < s)  return 0;
            else return 1;
        }
        for(f_p = 0; f_p < nums.size(); f_p++)  {
            sum += nums[f_p];
            while(sum >= s)  {
                res = min(res, f_p - 1);
                sum -= nums[s_p];
                s_p++;
            }
        }
        return res == INT_MAX ? 0 : res;
       
    }
};

template <class ansType, class dataType1, class dataType2 = int>
void test(ansType& expectAns, dataType1& firstData, dataType2 secondData = dataType2()) {
    Solution work;
    ansType ans;
    ans = work.minSubArrayLen(firstData, secondData);

    static int index = 0;
    index++;
    bool check = eq(ans, expectAns);
    printf("\n");
    if(!check) {
        printf("index %d: NO\n", index);
        output("firstData", firstData);
        output("secondData", secondData);
        output("ans", ans);
        output("expectAns", expectAns);
    } else {
        printf("index %d: YES\n", index);
    }
    printf("\n");

}

int main() {
    int first;
    vector<int> second;
    int expectAns;


    first = 7;
    second = {2,3,1,2,4,3};
    expectAns = 2;
    test(expectAns, first, second);


    first = 100;
    second = {2,3,1,2,4,3};
    expectAns = 0;
    test(expectAns, first, second);

    first = 3;
    second = {3};
    expectAns = 1;
    test(expectAns, first, second);
    return 0;
}
