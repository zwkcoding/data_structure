/*
 * Filename: /home/zwk/code/data_structrue/c++/sword_to_offer/001/main.cpp
 * Path: /home/zwk/code/data_structrue/c++/sword_to_offer/001
 * Created Date: Monday, May 20th 2019, 6:53:38 pm
 * Author: zwk
 * 
 * Copyright (c) 2019 Your Company
 */


#include "../../include/base.h"

/// Time Complexity:  O(n)
/// Space Complexity: O(1)
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int count = 0;
        for(int i = 0; i < length; i++)  {
            if(str[i] == ' ')  {
                count++;
            }
        }
        int len = length + count*2;
        int i,j;
        for(i = length - 1, j = len - 1; i >= 0 && j >= 0;)  {
            if(str[i] == ' ')  {
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
                i--;
            } else {
                str[j--] =  str[i--];
            }
        }
        str[len] = '\0';
	}
};


int main() {
   char str[7 + 1] = "a b c d";
   char expectAns[13 + 1] = "a%20b%20c%20d";  


    Solution solu;
    solu.replaceSpace(str, 7);

    cout <<str <<endl;


    return 0;
}


