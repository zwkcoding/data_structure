/*
 * Filename: /home/zwk/code/data_structrue/c++/binary_search/162_Find_Peak_Element/main.cpp
 * Path: /home/zwk/code/data_structrue/c++/binary_search/162_Find_Peak_Element
 * Created Date: Monday, May 13th 2019, 8:24:11 pm
 * Author: zwk
 *
 * Copyright (c) 2019 Your Company
 */


#include "../../include/base.h"
#include <vector>

/// sequential search
/// Time Complexity:  O()
/// Space Complexity: O().

class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int size, start, end, tmp;
        size = nums.size();
        if (size < 1) return 0;
        if (1 == size)
        {
            if (target <= nums[0]) return 0;
            else return 1;
        }

        start = 0;
        end = size - 1;
        while (start < end)
        {
            tmp = (start + end) / 2;
            if (target < nums[tmp])
            {
                end = tmp;
            }
            else if (target > nums[tmp])
            {
                start = tmp + 1;
            }
            else return tmp;
        }
        if (target <= nums[start]) return start;
        else return start + 1;
    }

};


int main()
{
    vector<int> first;
    int expectAns, second;

    first.clear();
    first.push_back(1);
    first.push_back(3);
    first.push_back(5);
    first.push_back(6);
    second = 5;
    expectAns = 2;
    TEST_SMP2(Solution, searchInsert,
            expectAns, first, second);

    second = 2;
    expectAns = 1;
    TEST_SMP2(Solution, searchInsert,
            expectAns, first, second);

    second = 7;
    expectAns = 4;
    TEST_SMP2(Solution, searchInsert,
            expectAns, first, second);

    second = 5;
    expectAns = 2;
    TEST_SMP2(Solution, searchInsert,
            expectAns, first, second);

    return 0;
}