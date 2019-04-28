#include "../../include/base.h"

/// 
/// Time Complexity: O(n * k)
/// Space Complexity: O(1)
class Solution {

void rotate(vector<int>& nums)  {
    for ( int i = nums.size() - 1 ; i > 0; i--)  {
       std::swap(nums[i], nums[i - 1]);
    }
} 

public:
    vector<int> rotate(vector<int>& nums, int k) {
        // todo
    }
};


int main() {
    vector<int> first;
    int second;
    vector<int> expectAns;


    first = {1,2,3,4,5,6,7};
    second = 1;
    expectAns = {7,1,2,3,4,5,6};
    TEST_SMP2(Solution, rotate, expectAns, first, second);


    first = {1,2,3,4,5,6,7};
    second = 2;
    expectAns = {6,7,1,2,3,4,5};
    TEST_SMP2(Solution, rotate, expectAns, first, second);


    first = {1,2,3,4,5,6,7};
    second = 3;
    expectAns = {5,6,7,1,2,3,4};
    TEST_SMP2(Solution, rotate, expectAns, first, second);


    first = {-1,-100,3,99};
    second = 2;
    expectAns = {3,99,-1,-100};
    TEST_SMP2(Solution, rotate, expectAns, first, second);


    return 0;
}
