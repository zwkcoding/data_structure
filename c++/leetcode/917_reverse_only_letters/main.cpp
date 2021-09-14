#include "../../include/base.h"
#include <string>

/// sequential search
/// Time Complexity:  O()
/// Space Complexity: O().

class Solution
{
public:

    inline bool is_letter(char ch)
    {
        if (ch >= 'A' && ch <= 'Z') return true;
        if (ch >= 'a' && ch <= 'z') return true;
        return false;
    }
    string reverseOnlyLetters(string s)
    {
        int tail_ptr, head_ptr;
        char tmp_ch;

        head_ptr = 0;
        tail_ptr = s.size() - 1;
        while (head_ptr < tail_ptr)
        {
            while (!is_letter(s[head_ptr]))
            {
                head_ptr ++;
                if (head_ptr >= tail_ptr) return s;
            }
            while (!is_letter(s[tail_ptr]))
            {
                tail_ptr --;
                if (head_ptr >= tail_ptr) return s;
            }
            tmp_ch = s[head_ptr];
            s[head_ptr] = s[tail_ptr];
            s[tail_ptr] = tmp_ch;
#if 0
            printf("head_ptr : %d %c, tail_ptr: %d %c; string: %s\n",
                    head_ptr, s[head_ptr], tail_ptr, s[tail_ptr],
                    s.c_str());
#endif
            head_ptr ++;
            tail_ptr --;
        }

        return s;
    }
};


int main()
{
    string first;
    string expectAns;

    first = "7_28]";
    expectAns = "7_28]";
    TEST_SMP1(Solution, reverseOnlyLetters, expectAns, first);

    first = "ab-cd";
    expectAns = "dc-ba";
    TEST_SMP1(Solution, reverseOnlyLetters, expectAns, first);

    first = "a-bC-dEf-ghIj";
    expectAns = "j-Ih-gfE-dCba";
    TEST_SMP1(Solution, reverseOnlyLetters, expectAns, first);

    first = "Test1ng-Leet=code-Q!";
    expectAns = "Qedo1ct-eeLg=ntse-T!";
    TEST_SMP1(Solution, reverseOnlyLetters, expectAns, first);
}