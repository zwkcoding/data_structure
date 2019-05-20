/*
 * Filename: /home/zwk/code/data_structrue/c++/sword_to_offer/001/main.cpp
 * Path: /home/zwk/code/data_structrue/c++/sword_to_offer/001
 * Created Date: Monday, May 20th 2019, 6:53:38 pm
 * Author: zwk
 * 
 * Copyright (c) 2019 Your Company
 */


#include "../../include/base.h"

/// Time Complexity:  
/// Space Complexity: 
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int v_start = 0, v_end = array.size() - 1;
        int h_start = 0, h_end = array[0].size() -1;
        int v_mid = -1, h_mid  = -1;
        // first check
        int v = array.size();
        int h = array[0].size();
        if(array[0][0] > target || array[v-1][h-1] < target)  {
            return false;
        }
        while(v_start <= v_end)  {
            v_mid = v_start + (v_end-v_start)/2;
            if(array[v_mid][0] < target)  {
                v_start = v_mid + 1;
            } else if(array[v_mid][0] > target)  {
                v_end = v_mid - 1;
            } else {
                return true;
            }
        }
        if(v_mid == -1)  {
            return false;
        }
        
        while(h_start <= h_end)  {
            h_mid = h_start + (h_end-h_start)/2;
            if(array[v_mid][h_mid] < target)  {
                h_start = h_mid + 1;
            } else if(array[v_mid][h_mid] > target)  {
                h_end = h_mid - 1;
            } else {
                return true;
            }
        }
        return false;

    }
};


int main() {
    vector<vector<int>> second;   
    int first;
    bool  expectAns;

    second = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    first = 8;
    expectAns = true;
    TEST_SMP2(Solution, Find, expectAns, first, second);

    second = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    first = 10;
    expectAns = false;
    TEST_SMP2(Solution, Find, expectAns, first, second);

    second = {
    {1, 2, 8, 9},
    {2, 4, 9, 12},
    {4, 7, 10, 13},
    {6, 8, 11, 15}};
    first = 5;
    expectAns = false;
    TEST_SMP2(Solution, Find, expectAns, first, second);


    second = {
    {1},
    {2}};
    first = 5;
    expectAns = false;
    TEST_SMP2(Solution, Find, expectAns, first, second);

    second = {
    {1}
    };
    first = 5;
    expectAns = false;
    TEST_SMP2(Solution, Find, expectAns, first, second);



    return 0;
}


