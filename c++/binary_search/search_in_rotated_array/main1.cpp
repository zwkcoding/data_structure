#include "../../include/base.h"

class Solution {
public:
    int searchMin(vector<int>& nums) {
        if(nums.size() == 0) {
            return -1;
        }
        int left = 0, right = nums.size()-1;
        // nums value like: k, k+1, ... , MAX,  1, 2, ..., k-1
        while(left < right){
            int mid=(left + right)/2;
            if(nums[mid]>nums[right]) left=mid+1;
            else right=mid;
        }
        return left;
        }
};


int main() {
#define CLASS Solution
#define FUNCTION searchMin

    vector<int> first;
    int second;
    int expectAns;

    first = {1,2,4,5,6,7,0};
    expectAns = 6;
    TEST_SMP1(Solution, FUNCTION, expectAns, first);

    first = {4,5,6,7,0,1,2};
    expectAns = 4;
    TEST_SMP1(Solution, FUNCTION, expectAns, first);

    first = {5,6,7,0,1,2,4};
    expectAns = 3;
    TEST_SMP1(Solution, FUNCTION, expectAns, first);

    first = {6,7,0,1,2,4,5};
    expectAns = 2;
    TEST_SMP1(Solution, FUNCTION, expectAns, first);

    first = {7,0,1,2,4,5,6};
    expectAns = 1;
    TEST_SMP1(Solution, FUNCTION, expectAns, first);

    first = {0,1,2,4,5,6,7};
    expectAns = 0;
    TEST_SMP1(Solution, FUNCTION, expectAns, first);

    return 0;
}
