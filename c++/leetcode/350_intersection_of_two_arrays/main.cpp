#include "../../include/base.h"
#include <vector>

/// sequential search
/// Time Complexity:  O()
/// Space Complexity: O().

class Solution
{
public:

    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> count_map;
        vector<int> res;
        for (const auto &e : nums1)
        {
            count_map[e] ++;
        }

        for (const auto &e : nums2)
        {
            auto it = count_map.find(e);
            if (it != count_map.end())
            {
                if (count_map[e] > 0)
                {
                    res.push_back(e);
                    count_map[e] --;
                }
            }
        }

        return std::move(res);
    }
};


int main()
{
    vector<int> first, sec, res;

    first = {1, 2, 2, 1};
    sec = {2, 2};
    res = {2, 2};
    TEST_SMP2(Solution, intersect, res, first, sec);

    first = {4, 9, 5};
    sec = {9, 4, 9, 8, 4};
    res = {4, 9};
    TEST_SMP2(Solution, intersect, res, first, sec);
}
