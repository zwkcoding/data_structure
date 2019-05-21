#include <iostream>
#include <cmath>
using namespace std;

//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


class Solution {
private:
    double powerNormal(double base, int exp)  {
        double res = base;
        for(int i = 1; i < exp; i++)  {
            res *= base;
        }
        return res;
    }
    
    bool equal(double left, double right)  {
        if(fabs(left - right) <  0.0000001)  {
            return true;
        }
        return false;
    }
public:
    double Power(double base, int exponent) {
        if(exponent == 1)  {
            return base;
        }
        if(exponent == 0)  {
            return 1;
        }
        if(exponent < 0)  {
            if(equal(powerNormal(base, -exponent), 0.00))  {
                std::cout <<"异常, 指数为负数的情况下，底数不能为0" << std::endl;
                return 0.0;
            }
            return 1 / powerNormal(base, -exponent);
        } else  {
            return powerNormal(base, exponent);
        }
        
    }
};
