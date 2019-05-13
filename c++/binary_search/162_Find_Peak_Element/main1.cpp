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

// Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

/// binary search: iteration
/// Time Complexity:  O(logn) 
/// Space Complexity: O(1). 

class Solution {
private:
    int Helper(const vector<int> &num, int low, int high)  {
        if(low == high)  {
            return low;
        }
        while(low < high)  {
            int mid = low + ((high - low)>>1);
            int mid_p = mid + 1;
            if(num[mid] > num[mid_p])  {
                high = mid;
            } else  {
                low = mid_p;
            }
        }
    }

public:
    int findPeak(vector<int>& nums)  {
        return Helper(nums, 0, nums.size() - 1);
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
    expectAns = 5;
    TEST_SMP1(Solution, findPeak, expectAns, first);



    return 0;
}
