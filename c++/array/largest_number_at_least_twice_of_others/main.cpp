#include "../../include/base.h"

/// 
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

public:
    int dominantIndex(vector<int>& nums) {
      int max_nums= nums[0];
      int index = 0;
      for(int i = 0; i < nums.size(); i++)  {
          index = nums[i] > max_nums ? i : index;
          max_nums = max(max_nums, nums[i]);
      }
      for(auto t: nums) {
          if(t != max_nums)  {
              if(max_nums < 2*t)  {
                  return -1;
                  break;
              }
          }
      }
      return index;
    }
};


int main() {
    #define CLASS Solution
    #define FUNCTION dominantIndex

    vector<int> first;
    int expectAns;


    first = {3, 6, 1, 0};
    expectAns =1;
    TEST_SMP1(CLASS, FUNCTION, expectAns, first);


    first = {1,2,3,4};
    expectAns = -1;
    TEST_SMP1(CLASS, FUNCTION, expectAns, first);

    return 0;
}
