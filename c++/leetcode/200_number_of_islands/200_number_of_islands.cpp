/*
 * @Author: Zhou WenKai
 * @Date: 2019-04-25 18:41:01
 * @Last Modified by: Zhou WenKai
 * @Last Modified time: 2019-04-25 19:23:23
 */

#include "../..//include/base.h"
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
#include <utility>
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

/// Time Complexity: O()
/// Space Complexity: O()

class Solution
{
public:

    typedef pair<int, int> Item;

    Item dirs[4] =
    {
        {0, 1},
        {0, -1},
        {-1, 0},
        {1, 0}
    };

    inline bool is_item_valid(Item ele,
            vector<vector<char>> &grid)
    {
        return (ele.first >= 0) &&
                (ele.first < grid.size()) &&
                (ele.second >= 0) &&
                (ele.second < grid[0].size()) &&
                ('1' == grid[ele.first][ele.second]);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;

        const int n = grid.size();
        const int m = grid[0].size();
        int i, j, res;
        bool searched[n][m];
        char type;
        Item item, curr, neighbor;
        std::stack<Item> st = stack<Item>();

        res = 0;
        memset(searched, 0, sizeof(bool) * n * m);
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                item.first = i;
                item.second = j;
                type = grid[i][j];
                if (searched[i][j]) continue;
                if ('0' == type) continue;
                // start dfs
                st.push(item);
                searched[i][j] = true;
                while (!st.empty())
                {
                    curr = st.top();
                    st.pop();
                    for (auto dir : dirs)
                    {
                        neighbor = curr;
                        neighbor.first += dir.first;
                        neighbor.second += dir.second;
                        if (searched[neighbor.first][neighbor.second]) continue;
                        if (is_item_valid(neighbor, grid))
                        {
                            searched[neighbor.first][neighbor.second] =
                                true;
                            st.push(neighbor);
                        }
                    }
                }
                res ++;
            }
        }

        return res;
    }
};

void test(int expectAns, vector<vector<char>> &data)
{
    Solution work;
    int ans;
    ans = work.numIslands(data);

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

int main() {
    vector<vector<char>> second;
    int expectAns;

    second = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    expectAns = 1;
    TEST_SMP1(Solution, numIslands, expectAns, second);

    second = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    expectAns = 3;
    TEST_SMP1(Solution, numIslands, expectAns, second);

    return 0;
}