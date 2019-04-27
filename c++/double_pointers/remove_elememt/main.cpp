/*
 * @Author: Zhou WenKai 
 * @Date: 2019-04-27 20:21:37 
 * @Last Modified by: Zhou WenKai
 * @Last Modified time: 2019-04-27 20:27:40
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

/// right away mode
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        for(int i = 0; i < n;  i++)  {
            if(val == nums[i])  {
                nums[i] = nums[n-1];
                i--;
                n--;
            }
        }
        return n;
    }
};

template <class ansType, class dataType1, class dataType2 = int>
void test(ansType& expectAns, dataType1& firstData, dataType2 secondData = dataType2()) {
    Solution work;
    ansType ans;
    ans = work.removeElement(firstData, secondData);

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
    vector<int>first;
    int second;
    int expectAns;
    Solution work;

    first = {3,2,2,3};
    second = 3;
    expectAns = 2;
    test(expectAns, first, second);

    first = {0,1,2,2,3,0,4,2};
    second = 2;
    expectAns = 5;
    test(expectAns, first, second);

    first = {0,0};
    second = 0;
    expectAns = 0;
    test(expectAns, first, second);
    return 0;
}
