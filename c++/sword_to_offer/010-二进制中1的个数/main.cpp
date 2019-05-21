class Solution {
public:
     int  NumberOf1(int n) {
         unsigned long flag = 1;
         int count = 0;
         while(flag <= INT_MAX) {
             if((n & flag) != 0)  count++;
             flag <<= 1;
         }
         // 32 bit
         if((n & flag) != 0)  {
             count++;
         }
         return count;
     }
};
