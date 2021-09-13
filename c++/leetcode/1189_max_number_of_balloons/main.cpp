#include "../../include/base.h"
#include <string>

/// sequential search
/// Time Complexity:  O()
/// Space Complexity: O().

class Solution
{
public:

    int maxNumberOfBalloons(std::string text)
    {
        int i, tmp, char_count[5], str_size;
        char ch_1;

        for (i = 0; i < 5; i++)
        {
            char_count[i] = 0;
        }

        str_size = text.size();
        tmp = str_size / 8;
        if (tmp < 1) return 0;
        for (i = 0; i < str_size; i++)
        {
            ch_1 = text[i];
            switch (ch_1)
            {
                case 'b' : char_count[0]++; break;
                case 'a' : char_count[1]++; break;
                case 'l' : char_count[2]++; break;
                case 'o' : char_count[3]++; break;
                case 'n' : char_count[4]++; break;
                default: break;
            }
        }

        tmp = min(char_count[0], char_count[1]);
        tmp = min(tmp, char_count[4]);
        tmp = min(tmp, char_count[2] / 2);
        tmp = min(tmp, char_count[3] / 2);

        return tmp;
    }

};


int main()
{
    std::string first;
    int expectAns;

    first = "nlaebolko";
    expectAns = 1;
    TEST_SMP1(Solution, maxNumberOfBalloons, expectAns, first);

    first = "loonbalxballpoon";
    expectAns = 2;
    TEST_SMP1(Solution, maxNumberOfBalloons, expectAns, first);

    first = "leetcode";
    expectAns = 0;
    TEST_SMP1(Solution, maxNumberOfBalloons, expectAns, first);
}