#include "../../include/base.h"

int main()
{
    // int v[2][10] = {{1,2,3,4,5,6,7,8,9,10},{11,12,13,14,15,16,17,18,19,20}};
    // int (*a)[10] = v;
    // cout << **a << endl;
    // cout << **(a+1)  << endl;
    // cout << *(*a+1) << endl;
    // cout << *(a[0]+1) << endl;
    // cout << *(a[1]) << endl;
    // return 0;

    int x = 2, y, z;
    x *= (y=z=5); cout <<x << endl;
    z = 3;
    x == (y = z);cout <<x << endl;
    x = (y == z); cout <<x << endl;
    x = (y & z); cout <<x << endl;
    x = (y&& z); cout <<x << endl;
    y =4;
    x= (y|z);cout <<x << endl;
    x= (y||z);cout <<x << endl;
}
