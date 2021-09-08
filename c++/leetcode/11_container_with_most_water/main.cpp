#include "../../include/base.h"
#include <vector>

/// sequential search
/// Time Complexity:  O()
/// Space Complexity: O().

class Solution
{
public:

    int maxArea(vector<int>& height)
    {
        int head, tail;
        int curr_area, max_area, max_width;

        head = 0;
        tail = height.size() - 1;
        if (tail < 2)
        {
            return 2 * min(height[0], height[1]);
        }

        max_width = tail - head;
        max_area = min(height[head], height[tail]) *
            max_width;
        while (max_width > 1)
        {
            max_width --;
            if (height[head] <= height[tail])
            {
                head ++;
            }
            else tail --;

            curr_area = min(height[head], height[tail]) *
                max_width;
            max_area = max(curr_area, max_area);
        }

        return max_area;
    }

};


int main()
{
    vector<int> first;
    int expectAns;


    first.clear();
    first.push_back(1);
    first.push_back(2);
    first.push_back(1);
    expectAns = 2;
    TEST_SMP1(Solution, maxArea, expectAns, first);

    first.clear();
    first.push_back(1);
    first.push_back(8);
    first.push_back(6);
    first.push_back(2);
    first.push_back(5);
    first.push_back(4);
    first.push_back(8);
    first.push_back(3);
    first.push_back(7);
    expectAns = 49;
    TEST_SMP1(Solution, maxArea, expectAns, first);
}
