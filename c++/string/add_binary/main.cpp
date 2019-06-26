/*
 * @Author: Zhou WenKai 
 * @Date: 2019-04-27 12:36:38 
 * @Last Modified by: Zhou WenKai
 * @Last Modified time: 2019-04-27 12:54:57
 */

#include "../../include/base.h"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

// const int debug = 0;
// typedef unsigned uint;
// typedef unsigned char uchar;
auto __ = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution
{
public:
    string addBinary(string first, string second) {
        string res;

         // calc max length
        int max_len = max(first.length(),second.length()) + 1;
        
        // reverse
        std::reverse(first.begin(), first.end());
        std::reverse(second.begin(), second.end());

        // compelete zero in high index
        first.resize(max_len, '0');
        second.resize(max_len, '0');

        // calc
        int sum = 0;
        const int base = 2;
        for(int i = 0; i < max_len; i++)  {
            sum += (first[i] - '0') + (second[i] - '0');
            res.push_back('0' + (sum % base));
            sum /= base;
        }

        // delete zero in high index
        while(res.length() > 1 && res[res.length() - 1] == '0')  {
            res.pop_back();
        }

        // reverse result
        std::reverse(res.begin(), res.end());
        return res;
        
    }

        /* string addBinary(string a, string b) {
        int  adi = a.size() - 1, bdi = b.size() - 1;
        string ans = "";
        int ach, bch;
        int ret = 0;
        while(adi >= 0 || bdi >= 0)  {
            ach = (adi >=0 && a[adi--] == '1');
            bch = (bdi >=0 && b[bdi--] == '1');
            ans = static_cast<char>(((ach + bch + ret) & 0x1) + '0' ) + ans;
            ret = (ach + bch + ret) >= 2;   // 判断是否进位， 可用 >>1 代替
        }
        if(ret == 1) ans = static_cast<char>('1') + ans;
        return ans;
    } */

};

template <class ansType, class dataType1, class dataType2 = int>
void test(ansType &expectAns, dataType1 &firstData, dataType2 secondData = dataType2())
{
    Solution work;
    ansType ans;
    ans = work.addBinary(firstData, secondData);

    static int index = 0;
    index++;
    bool check = eq(ans, expectAns);
    printf("\n");
    if (!check) {
         printf("index %d: NO\n", index);
        output("firstData", firstData);
        output("secondData", secondData);
        output("ans", ans);
        output("expectAns", expectAns);
    } else {
        printf("index %d: YES\n", index);
    }
    printf("\n");
}

int main()
{
    string first;
    string second;
    string expectAns;


    first = "11";
    second = "1";
    expectAns = "100";
    test(expectAns, first, second);


    first = "1010";
    second = "1011";
    expectAns = "10101";
    test(expectAns, first, second);



    first = "0010";
    second = "0001";
    expectAns = "11";
    test(expectAns, first, second);

    return 0;

}
