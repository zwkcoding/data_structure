#include "../../include/base.h"
#include <vector>

/// sequential search
/// Time Complexity:  O()
/// Space Complexity: O().

class Solution
{
public:

    int search(vector<int>& nums, int target)
    {
        int head, tail, half;

        head = 0;
        tail = nums.size() - 1;
        if (tail < 1)
        {
            return (nums[0] == target) ? 0 : -1;
        }
        else if (tail < 2)
        {
            if (nums[0] == target) return 0;
            else if (nums[1] == target) return 1;
            else return -1;
        }

        // avoid endless loop
        while (head < tail - 1)
        {
            half = (head + tail) / 2;
            if (nums[half] < target)
            {
                head = half;
            }
            else if (nums[half] > target)
            {
                tail = half;
            }
            else return half;
        }

        if (target == nums[nums.size() - 1]) return nums.size() - 1;
        if (target == nums[0]) return 0;
        return -1;
    }
};


int main()
{
    vector<int> first;
    int sec, expectAns;

    first.clear();
    first.push_back(-1);
    first.push_back(0);
    first.push_back(3);
    first.push_back(5);
    first.push_back(9);
    first.push_back(12);
    sec = 9;
    expectAns = 4;
    TEST_SMP2(Solution, search, expectAns, first, sec);
    sec = 2;
    expectAns = -1;
    TEST_SMP2(Solution, search, expectAns, first, sec);

    first.clear();
    first.push_back(-1);
    first.push_back(0);
    first.push_back(5);
    sec = 5;
    expectAns = 2;
    TEST_SMP2(Solution, search, expectAns, first, sec);
}
