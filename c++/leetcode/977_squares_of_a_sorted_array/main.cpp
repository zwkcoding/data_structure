#include "../../include/base.h"
#include <vector>

/// sequential search
/// Time Complexity:  O()
/// Space Complexity: O().

class Solution
{
public:

    vector<int> sortedSquares(vector<int>& nums)
    {
        bool start_nega;
        int i, size, square, check_index, nega_size;
        vector<int> res;
        vector<int> posi, nega;

        size = nums.size();
        start_nega = false;
        // two part vector, up order in nega, down order in posi
        for (i = size - 1; i >= 0; i--)
        {
            square = nums[i] * nums[i];
            if (!start_nega)
            {
                if (nums[i] < 0)
                {
                    nega.push_back(square);
                    start_nega = true;
                    continue;
                }
                posi.push_back(square);
            }
            else
            {
                nega.push_back(square);
            }
        }

        if (posi.size() < 1) return nega;
        else if (nega.size() < 1)
        {
            size = posi.size();
            // reverse it
            for (i = size - 1; i >= 0; i--)
            {
                res.push_back(posi[i]);
            }
            return res;
        }
        // merge sort, insert posi to nega
        size = posi.size();
        nega_size = nega.size();
        check_index = 0;
        for (i = size - 1; i >= 0; i--)
        {
            while (check_index < nega_size)
            {
                if (nega[check_index] <= posi[i])
                {
                    res.push_back(nega[check_index]);
                    check_index++;
                }
                else
                {
                    res.push_back(posi[i]);
                    break;
                }
            }
            if (check_index >= nega_size)
            res.push_back(posi[i]);
        }

        // fill left nega element
        while (check_index < nega_size)
        {
            res.push_back(nega[check_index]);
            check_index++;
        }

        return res;
    }
};


int main()
{
    vector<int> first;
    vector<int> expectAns;


    first.clear();
    first.push_back(-2);
    first.push_back(0);
    expectAns.clear();
    expectAns.push_back(0);
    expectAns.push_back(4);
    TEST_SMP1(Solution, sortedSquares, expectAns, first);

    first.clear();
    first.push_back(-4);
    first.push_back(-1);
    first.push_back(0);
    first.push_back(3);
    first.push_back(10);
    expectAns.clear();
    expectAns.push_back(0);
    expectAns.push_back(1);
    expectAns.push_back(9);
    expectAns.push_back(16);
    expectAns.push_back(100);
    TEST_SMP1(Solution, sortedSquares, expectAns, first);

    first.clear();
    first.push_back(-7);
    first.push_back(-3);
    first.push_back(2);
    first.push_back(3);
    first.push_back(11);
    expectAns.clear();
    expectAns.push_back(4);
    expectAns.push_back(9);
    expectAns.push_back(9);
    expectAns.push_back(49);
    expectAns.push_back(121);
    TEST_SMP1(Solution, sortedSquares, expectAns, first);
}