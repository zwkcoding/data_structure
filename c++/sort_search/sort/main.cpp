#include <iostream>
#include <vector>

#define debugcout

#ifdef debugcout
#define debug  cout
#else
#define debug  0 && cout
#endif


using namespace std;

void swap(int& a, int & b)  {
    int temp = a;
    a = b;
    b = temp;
}

/// 获取分区点
int partition(std::vector<int>&  data, int start, int end)  {
    int pivot = end;
    int i = start;
    for(int j = start; j < end; j++)  {
        if(data[j] < data[pivot])  {
            //  考虑相等的情况
            if(data[i]  != data[j])  {
                swap(data[i] , data[j]);
            }
            i++;
        }
    }
    swap(data[i] , data[pivot]);
    return i;
}

void quick_sort(std::vector<int>&  data, int start, int end)  {
        // 主要要置于分区函数之前，否则会产生 “double free or corruption”错误
        if(start >= end)  {
            return;
        }

        int i = partition(data, start, end);  // 当前分区点为 i
        // debug << i << endl;

        quick_sort(data, start, i - 1); 
        quick_sort(data, i + 1, end);
        // if( i == start)  {
        //     quick_sort(data, i + 1, end);
        // } else if(i == end)   {
        //     quick_sort(data, start, i - 1);
        // } else  {
        //     // 左分和右分
        //     quick_sort(data, start, i - 1); 
        //     quick_sort(data, i + 1, end);
        // }
       
}

void bubble_sort(std::vector<int>&  data)  {
    bool flag = false;  // 哨兵
    int n = data.size();
    if(n == 0) return;
    for(int i = n - 1; i >= 0; i--)  {
        flag = false;
        for(int j = 0; j < i ;  j++)  {
            if(data[j] > data[j+1] )  {
                swap(data[j] , data[j+1]);
                flag = true;
            }
        }
        if(flag == false)  return;
    }
}

std::vector<int> merge_sort(std::vector<int>&  d1, std::vector<int>&  d2 )  {
    std::vector<int> res;
    int n1 = d1.size(), n2 = d2.size();
    int i,j;
    for(i = 0 , j = 0; i < n1 && j < n2;)  {
        if(d1[i] > d2[j])  {
            res.push_back(d2[j]);
            j++;
        } else {
            res.push_back(d1[i]);
            i++;
        }
    }

    // 判断哪个子数组中有剩余的数据
    while(i < n1)  res.push_back(d1[i++]);
    while(j < n2)  res.push_back(d2[j++]);

    return res;
}


std::vector<int> merge_sort_with_sentinel(std::vector<int>&  d1, std::vector<int>&  d2 )  {
    std::vector<int> res;
    int n1 = d1.size(), n2 = d2.size();
    int i,j;
    //  利用哨兵技术，在尾部多放一个和原有最后值相同的值
    for(i = 0 , j = 0; i < n1 || j < n2;)  {
        if( i < n1 && d1[i] <  d2[j] )  {
                res.push_back(d1[i++]);
        } else {
                res.push_back(d2[j++]);
        } 
    }
    return res;
}

int main()
{
    std::cout << "quick_sort:" << std::endl;
    std::vector<int> data_raw = { 34, 65, 12, 43, 67, 5, 78, 10, 3, 70 };
    auto data = data_raw;
    std::cout << "raw:" << std::endl;
    for (auto d : data)
        std::cout << d << ",";
    std::cout << std::endl;
    quick_sort(data, 0, data.size() - 1);
    std::cout << "sort:" << std::endl;
    for (auto d : data)
        std::cout << d << ",";
    std::cout << std::endl;

    data = data_raw;
    std::cout << "\nbubble_sort:" << std::endl;
    std::cout << "raw:" << std::endl;
    for (auto d : data)
        std::cout << d << ",";
    std::cout << std::endl;
    bubble_sort(data);
    std::cout << "sort:" << std::endl;
    for (auto d : data)
        std::cout << d << ",";
    std::cout << std::endl;

    std::cout << "\nmerge_sort:" << std::endl;
    std::vector<int> data0 = { 0, 2, 4, 6, 8, 10 };
    std::vector<int> data1 = { 1, 3, 5, 7, 9 };
    std::cout << "raw:" << std::endl;
    for (auto d : data0) std::cout << d << ", ";
    std::cout << std::endl;
    for (auto d : data1) std::cout << d << ", ";
    std::cout << std::endl;
    auto res = merge_sort_with_sentinel(data0, data1);
    std::cout << "sort:" << std::endl;
    for (auto d : res) std::cout << d << ", ";
    std::cout << std::endl;

    return 0;
}
