#include "../../include/base.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return -1;
        }
        int left = 0, right = nums.size()-1;
        // nums value like: k, k+1, ... , MAX,  1, 2, ..., k-1
        while(left <= right)  {
            int mid = left + ((right-left)>>1);
            if(target == nums[mid])  {
                return mid;
            }
            // there exists rotation; the middle element is in right part of the array before ratation
            else if(nums[mid] > nums[right])  {
                // target is in left part
                if(target < nums[mid] && target >= nums[left])  {
                    right = mid - 1;
                }
                // target is in right part
                else  {
                    left = mid + 1;
                }
            }
            //  there exists rotation; the middle element is in left part of the array before ratation
            else if(nums[mid] < nums[left])  {
                // target is in right part
                if(target > nums[mid] && target <= nums[right])  {
                    left = mid + 1;
                }
                // target  is in left part
                else  {
                    right = mid - 1;
                }
            }
            // normal 
            else {
                if(target < nums[mid])  {
                    right = mid - 1;
                }
                else if(target > nums[mid])  {
                    left = mid + 1;
                }
            }
            }
            return -1;
        }

};


int main() {
#define CLASS Solution
#define FUNCTION search

    vector<int> first;
    int second;
    int expectAns;

    first = {4,5,6,7,0,1,2};
    second = 0;
    expectAns = 4;
    TEST_SMP2(Solution, FUNCTION, expectAns, first, second);

    first = {4,5,6,7,0,1,2};
    second = 3;
    expectAns = -1;
    TEST_SMP2(Solution, FUNCTION, expectAns, first, second);

    first = {7,0,1,2,4,5,6};
    second = 5;
    expectAns = 5;
    TEST_SMP2(Solution, FUNCTION, expectAns, first, second);

    first = {0,1,2,4,5,6,7};
    second = 7;
    expectAns = 6;
    TEST_SMP2(Solution, FUNCTION, expectAns, first, second);

    return 0;
}
