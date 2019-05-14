/*
 * Filename: /home/zwk/code/data_structrue/c++/recursion/395longest-substring-with-at-least-k-repeating-characters/main.cpp
 * Path: /home/zwk/code/data_structrue/c++/recursion/395longest-substring-with-at-least-k-repeating-characters
 * Created Date: Tuesday, May 14th 2019, 6:49:25 pm
 * Author: zwk
 * 
 * Copyright (c) 2019 Your Company
 */

#include "../../include/base.h"

/// tricky 
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int a= 0, b = 0;
        for(int i = 0; i < nums.size(); i++)  {
            if(i%2)  {
                a = max((a + nums[i]), b);
            }else  {
                b = max((b + nums[i]), a);
            }
        }
        return max(a, b);
    }

};


int main() {
    vector<int>  first;
    int expectAns;

    first = {1,2,3,1};
    expectAns = 4;
    TEST_SMP1(Solution, rob, expectAns, first);

    first = {2,7,9,3,1};
    expectAns = 12;
    TEST_SMP1(Solution, rob, expectAns, first);


    first = { 10, 0, 1, 100};
    expectAns = 110;
    TEST_SMP1(Solution, rob, expectAns, first);

    first = { 2,7,9,3,1,4};
    expectAns = 15;
    TEST_SMP1(Solution, rob, expectAns, first);

    return 0;
}
