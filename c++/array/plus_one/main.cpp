/*
 * @Author: Zhou WenKai 
 * @Date: 2019-04-24 21:05:43 
 * @Last Modified by: Zhou WenKai
 * @Last Modified time: 2019-04-24 21:38:47
 */

#include "../../include/base.h"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

// const int debug = 0;
// typedef unsigned uint;
// typedef unsigned char uchar;
auto __ = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution
{
public:
    vector<int> plusOne(vector<int> nums)
    {
        const int n = nums.size();
        int temp = 0;
        int add = 1;
        for (int i = n - 1; i >= 0; i--) {
            temp = nums[i] + add;
            if (temp < 10) {
                nums[i] = temp;
                break;
            } else {
                nums[i] = temp % 10;
                add = temp / 10;
                if (i == 0) {
                    nums.insert(nums.begin(), add);
                } else {
                    continue;
                }
            }
        }
        return nums;
    }
};

template <class ansType, class dataType1, class dataType2 = int>
void test(ansType &expectAns, dataType1 &data, dataType2 K = dataType2())
{
    Solution work;
    ansType ans;
    ans = work.plusOne(data);

    static int index = 0;
    index++;
    bool check = eq(ans, expectAns);
    printf("\n");
    if (!check) {
        printf("index %d: NO\n", index);
        output("data", data);
        output("ans", ans);
        output("expectAns", expectAns);
    } else {
        printf("index %d: YES\n", index);
    }
    printf("\n");
}

int main()
{
    vector<int> data;
    vector<int> expectAns;

    data = {1, 2, 3};
    expectAns = {1, 2, 4};
    test(expectAns, data);

    data = {4, 3, 2, 1};
    expectAns = {4, 3, 2, 2};
    test(expectAns, data);

    data = {0};
    expectAns = {1};
    test(expectAns, data);

    data = {9, 0, 9};
    expectAns = {9, 1, 0};
    test(expectAns, data);

    data = {9, 9, 9};
    expectAns = {1, 0, 0, 0};
    test(expectAns, data);

    return 0;
}
