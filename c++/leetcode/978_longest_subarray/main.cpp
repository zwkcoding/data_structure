#include "../../include/base.h"
#include <string>

// TODO:
// - improve it with only one loop
// - solve it with dp

/// sequential search
/// Time Complexity:  O()
/// Space Complexity: O().

class Solution
{
public:

    typedef enum comparator_type
    {
        GREATER = 0,
        LESS = 1
    } comparator_t;

    int maxTurbulenceSize(vector<int> &arr)
    {
        int i, j, flip_size, max_flip_size, size;
        int curr, next;
        comparator_t last_comp, comp;

        size = arr.size();
        if (1 == size) return 1;
        if (2 == size)
        {
            if (arr[0] == arr[1]) return 1;
            return 2;
        }

        max_flip_size = 0;
        for (i = 0; i < size - 1; i++)
        {
            curr = arr[i];
            flip_size = 0;
            next = arr[i + 1];
            if (curr == next) continue;
            for (j = i + 1; j < size; j++)
            {
                next = arr[j];
                if (curr > next) comp = GREATER;
                else if (curr < next) comp = LESS;
                if (j == i + 1)
                {
                    last_comp = comp;
                    curr = arr[j];
                    flip_size ++;
                    continue;
                }

                if (last_comp != comp)
                {
                    flip_size ++;
                }
                else
                {
                    i = j - 2;
                    break;
                }
                last_comp = comp;
                curr = arr[j];
            }
            max_flip_size = max(max_flip_size, flip_size);

        }
        if (0 == max_flip_size) return 1;
        return max_flip_size + 1;
    }
};


int main()
{
    std::vector<int> first;
    int expectAns;

    first = {9,4,2,10,7,8,8,1,9};
    expectAns = 5;
    TEST_SMP1(Solution, maxTurbulenceSize, expectAns, first);

    first = {4,8,12,16};
    expectAns = 2;
    TEST_SMP1(Solution, maxTurbulenceSize, expectAns, first);

    first = {8, 8};
    expectAns = 1;
    TEST_SMP1(Solution, maxTurbulenceSize, expectAns, first);

    first = {8, 8, 8, 8, 8};
    expectAns = 1;
    TEST_SMP1(Solution, maxTurbulenceSize, expectAns, first);

    first = {8, 8, 8, 8, 9};
    expectAns = 2;
    TEST_SMP1(Solution, maxTurbulenceSize, expectAns, first);

    first = {8, 9};
    expectAns = 2;
    TEST_SMP1(Solution, maxTurbulenceSize, expectAns, first);

    first = {100};
    expectAns = 1;
    TEST_SMP1(Solution, maxTurbulenceSize, expectAns, first);
}