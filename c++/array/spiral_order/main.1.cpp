/*
 * @Author: Zhou WenKai 
 * @Date: 2019-04-25 20:44:24 
 * @Last Modified by: Zhou WenKai
 * @Last Modified time: 2019-04-25 20:51:46
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

// Template method
/// Time Complexity: O()
/// Space Complexity: O()
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> res;
        int nr = matrix.size();
        if (nr == 0)
            return res;
        int nc = matrix[0].size();
        if (nc == 0)
            return res;

        vector<int> nSteps{nc, nr - 1};
    }
};

template <class ansType, class dataType1, class dataType2 = int>
void test(ansType &expectAns, dataType1 &data, dataType2 K = dataType2())
{
    Solution work;
    ansType ans;
    ans = work.spiralOrder(data);

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
    vector<vector<int>> data;
    vector<int> expectAns;

    data = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    expectAns = {1, 2, 3, 6, 9, 8, 7, 4, 5};
    test(expectAns, data);

    data = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};
    expectAns = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
    test(expectAns, data);

    data = {
        {1}};
    expectAns = {1};
    test(expectAns, data);

    data = {
        {1},
        {4},
        {7}};
    expectAns = {1, 4, 7};
    test(expectAns, data);

    return 0;
}
