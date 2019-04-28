/*
 * @Author: Zhou WenKai 
 * @Date: 2019-04-28 19:26:23 
 * @Last Modified by: Zhou WenKai
 * @Last Modified time: 2019-04-28 19:43:55
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

/// force search
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = INT_MAX ;
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        for(int i = 0; i < n; i++)  {
            sums[i+1] = sums[i] + nums[i];
        }
        for(int i = 0; i < n + 1; i++)  {
            if(sums[i] >= s)  {
                for(int j = 0; j < i; j++)  {
                    if(sums[j]  >= sums[i] - s)  {
                        res = min(res, i - j);
                        break;
                    }
                }
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
