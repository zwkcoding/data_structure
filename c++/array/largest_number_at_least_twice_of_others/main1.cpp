#include "../../include/base.h"

/// find two largest number
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

public:
    int dominantIndex(vector<int>& nums) {
      int first_max = nums[0], second_max = first_max;
      int first_max_ind = 0;
      /*
        int max1 = 0, max2 = 0, idxOfMax1 = 0;
        if(nums.size() == 1)  {
            return 0;
        } else {
            first_max_ind = nums[0] > nums[1] ? 0 : 1;
            first_max = std::max(nums[0], nums[1]);
            second_max = std::min(nums[0], nums[1]);
      }
      */
      if(nums.size() == 1)  {
          return 0;
      }
      if(nums.size() == 1)  {
          return 0;
      } else {
        first_max_ind = nums[0] > nums[1] ? 0 : 1;
        first_max = std::max(nums[0], nums[1]);
        second_max = std::min(nums[0], nums[1]);
      }
      for(int i = 0;  i < nums.size(); i++)  {
          if(nums[i] > first_max)  {
              second_max = first_max;
              first_max = nums[i];
              first_max_ind = i;
          } else {
              if(nums[i] > second_max)  {
                  second_max = nums[i];
              }
          }
      }
      if(first_max < 2 * second_max)  {
          return -1;
      } else {
          return first_max_ind;
      }
    }

};


int main() {
    #define CLASS Solution
    #define FUNCTION dominantIndex

    vector<int> first;
    int expectAns;


    first = {1};
    expectAns = -1;
    TEST_SMP1(CLASS, FUNCTION, expectAns, first);

     first = {1, 0};
    expectAns = -1;
    TEST_SMP1(CLASS, FUNCTION, expectAns, first);
    
    first = {3, 6, 1, 0};
    expectAns =1;
    TEST_SMP1(CLASS, FUNCTION, expectAns, first);


    first = {1,2,3,4};
    expectAns = -1;
    TEST_SMP1(CLASS, FUNCTION, expectAns, first);

    return 0;
}
