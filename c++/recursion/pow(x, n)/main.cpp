#include "../../include/base.h"

/// 
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {

public:

    // recursion mode
    double myPow(double x, int n) {
        long  m = n;
        if(0 == n )
            return 1;
        if(n < 0) {
            m = -m;
            x = 1/x;}
         return ((n & 1) == 0) ? myPow(x*x, m/2) : x*myPow(x*x, m/2);
    }

    // iteration mode
    double myPowIter(double x, int n) {
    double ans = 1;
    long  m = n;
    if(0 == n )
        return 1;
    if(n < 0) {
        m = -m;
        x = 1/x;}
    while (m) {
        if (m & 1)      // 判断是否为奇数
            ans *= x;
        x *= x;
        m >>= 1;
    }
        return ans;
    }
};


int main() {

    double  first ;
    int second ;
    double expectAns ;

#define FUNCNAME myPowIter
#define CLASSNAME Solution

    first = 2;
    second = 3;
    expectAns = 8;
    TEST_SMP2(CLASSNAME, FUNCNAME, expectAns, first, second);

    first = 2;
    second = 10;
    expectAns = 1024;
    TEST_SMP2(CLASSNAME, FUNCNAME, expectAns, first, second);

    first = 2;
    second = -3;
    expectAns = 1 / 8.0;
    TEST_SMP2(CLASSNAME, FUNCNAME, expectAns, first, second);

    first = 2;
    second = 0;
    expectAns = 1;
    TEST_SMP2(CLASSNAME, FUNCNAME, expectAns, first, second);

    return 0;
}
