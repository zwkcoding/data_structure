/*
 * Filename: /home/zwk/code/data_structrue/c++/binary_search/162_Find_Peak_Element/main.cpp
 * Path: /home/zwk/code/data_structrue/c++/binary_search/162_Find_Peak_Element
 * Created Date: Monday, May 13th 2019, 8:24:11 pm
 * Author: zwk
 * 
 * Copyright (c) 2019 Your Company
 */


#include "../../include/base.h"
#include <array>

/// sequential search
/// Time Complexity:  O(n) 
/// Space Complexity: O(1). 

class Solution {
public:
    int findPeak(vector<int>& nums)  {
        for(int i  = 1; i < nums.size(); i++)  {
            if(nums[i] < nums[i-1])  {
                return i - 1;
            }
        }
        return nums.size() - 1;
    }

};


int main() {
    vector<int> first;
    int second;
    int ans, expectAns;

    first.clear();
    first.push_back(1);
    first.push_back(2);
    first.push_back(3);
    first.push_back(1);
    expectAns = 2;
    TEST_SMP1(Solution, findPeak, expectAns, first);

    first.clear();
    first.push_back(1);
    first.push_back(2);
    first.push_back(1);
    first.push_back(3);
    first.push_back(5);
    first.push_back(6);
    first.push_back(4);
    expectAns = 1;
    TEST_SMP1(Solution, findPeak, expectAns, first);



    return 0;
}
