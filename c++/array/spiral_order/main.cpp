/*
 * @Author: Zhou WenKai 
 * @Date: 2019-04-25 19:25:26 
 * @Last Modified by: Zhou WenKai
 * @Last Modified time: 2019-04-25 20:51:55
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
        int row_num = matrix.size();
        int col_num = matrix[0].size();
        if (row_num == 0 || col_num == 0)
            return res;

        // templates
        //top , right, bottom, left
        enum
        {
            TOP = 0,
            RIGHT = 1,
            BOTTOM = 2,
            LEFT = 3
        };
        int base[4] = {0, matrix[0].size() - 1, matrix.size() - 1, 0};
        // border change template
        int baseInc[4] = {1, -1, -1, 1};
        // direction template
        int xyInc[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // current direction and position
        int step = 0, x = 0, y = 0;

        while (base[TOP] <= base[BOTTOM] && base[RIGHT] >= base[LEFT]) {
            while (x <= base[BOTTOM] && x >= base[TOP] && y <= base[RIGHT] && y >= base[LEFT]) {
                res.push_back(matrix[x][y]);
                x += xyInc[step][0];
                y += xyInc[step][1];
            }

            // back one step
            x -= xyInc[step][0];
            y -= xyInc[step][1];

            // if(step == 0 || step == 3)
            // base[step]++;
            base[step] += baseInc[step];
            // step++;
            // step %= 4;
            step = (step + 1) % 4;

            x += xyInc[step][0];
            y += xyInc[step][1];
        }
        return res;
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
