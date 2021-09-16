#include "../../include/base.h"

#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

// const int debug = 0;
// typedef unsigned uint;
// typedef unsigned char uchar;
auto __ = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

/// Time Complexity: O()
/// Space Complexity: O()

class Solution
{
public:

    std::pair<int, int> dir_seq[4] =
    {
        {0, 1}, // right
        {1, 0}, // down
        {0, -1}, // left
        {-1, 0} // up
    };

    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        bool change_dir;
        int m, n, curr_dir, curr_x, curr_y;
        int x_s, x_e, y_s, y_e; // x_dir [min, max] record
        vector<int> res;

        m = matrix.size();
        n = matrix[0].size();
        x_s = 0;
        x_e = n - 1;
        y_s = 0;
        y_e = m - 1;

        curr_x = 0;
        curr_y = 0;
        curr_dir = 0;
        change_dir = false;
        // main loop, execute spiral order
        while (true)
        {
            switch (curr_dir)
            {
                case 0 : // curr dir: right, watch: x_e, update: y_s++;
                    if (curr_x >= x_e)
                    {
                        y_s ++;
                        change_dir = true;
                    }
                    break;
                case 1 : // dir: down, watch: y_e, update: x_e--;
                    if (curr_y >= y_e)
                    {
                        x_e --;
                        change_dir = true;
                    }
                    break;
                case 2: // dir: left, watch: x_s, update: y_e--;
                    if (curr_x <= x_s)
                    {
                        y_e --;
                        change_dir = true;
                    }
                    break;
                case 3: // dir: up, watch: y_s, update: x_s++;
                    if (curr_y <= y_s)
                    {
                        x_s ++;
                        change_dir = true;
                    }
                    break;
                default: break;
            }
#if 0
            printf("curr_xy: [%d, %d], change_dir: %d\n",
                    curr_x, curr_y, (int) change_dir);
            printf("add ele (%d), curr dir: %d, x limit: [%d, %d], "
                    "y limit: [%d, %d]\n",
                    matrix[curr_y][curr_x], curr_dir, x_s, x_e, y_s, y_e);
#endif
            res.push_back(matrix[curr_y][curr_x]);
            if (x_s > x_e || y_s > y_e) break;
            if (change_dir)
            {
                // next loop
                change_dir = false;
                curr_dir ++;
                curr_dir %= 4;
            }
            curr_y += dir_seq[curr_dir].first;
            curr_x += dir_seq[curr_dir].second;
            curr_x = min(curr_x, x_e);
            curr_x = max(curr_x, x_s);
            curr_y = min(curr_y, y_e);
            curr_y = max(curr_y, y_s);
#if 0
            printf("next_xy: [%d, %d], curr_dir: %d\n",
                    curr_x, curr_y, curr_dir);
#endif
        }

        return res;
    }
};

int main()
{
    vector<vector<int>> first;
    vector<int> expectAns;

    first =
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
    expectAns = {1, 2, 3, 6, 9, 8, 7, 4, 5};
    TEST_SMP1(Solution, spiralOrder, expectAns, first);

    first =
        {
            {1}
        };
    expectAns = {1};
    TEST_SMP1(Solution, spiralOrder, expectAns, first);

    first =
        {
            {1},
            {2},
            {3},
            {4},
            {5},
        };
    expectAns = {1, 2, 3, 4, 5};
    TEST_SMP1(Solution, spiralOrder, expectAns, first);

    first =
        {
            {1, 2}
        };
    expectAns = {1, 2};
    TEST_SMP1(Solution, spiralOrder, expectAns, first);

    first =
        {
            {1, 2},
            {3, 4}
        };
    expectAns = {1, 2, 4, 3};
    TEST_SMP1(Solution, spiralOrder, expectAns, first);

    first =
        {
            {1, 2},
            {3, 4},
            {5, 6}
        };
    expectAns = {1, 2, 4, 6, 5, 3};
    TEST_SMP1(Solution, spiralOrder, expectAns, first);

    first =
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        };
    expectAns = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
    TEST_SMP1(Solution, spiralOrder, expectAns, first);

    return 0;
}