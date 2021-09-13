# Array

## array usage:

```c++
#include <iostream>

int main() {
  // 1. Initialize
  int a0[5];
  int a1[5] = {1,2,3};
  // 2. Get length
  int size = sizeof(a1) / sizeof(*a1);
  cout << "the size of a1 is :" << size << endl;
  // 3. Access Element
  cout << "the first element is:" << a1[0] << end;
  // 4. Iterate all elements
  cout << "[version 1] the contents of a1 are:";
  for (int i = 0; i < size; ++i)  {
    cout << " " << a1[i];
  }
  cout << endl;
  cout << "[version 2] the contents of a1 are:";
  for (int& item :a1)  {
    cout << " " << item;
  }
  cout << endl;
  // 5. modifyy element
  a1[0] = 4;
  //6. sort
  sort(a1, a1 + size);
}
```

#### dynamic array
```c++
#include <iostrea>

int main()  {
   // 1. initialize
   vector<int> v0;
   vector<int> v1(5,0);
   // 2. make a copy
   vector<int> v2(v1.begin(), v1.end());
   vector<int> v3(v3);
   // 2. cast an array to a vector
   int a[5] = {0, 1, 2, 3, 4};
   vector<int> v4(a, *(&a + 1 ));
   // 3. get length
   cout << "the size of v4 is: " << v4.size() << endl;
   // 4. access element
   cout << "the first element in v4 is : " << v4[0] << endl;
   // 5. iterate the vector
   cout << "[version 1] the contents of v4 are:";
   for (int i = 0; i < v4.size(); ++i)  {
     cout << " " << v4[i];
   }
   cout << endl;
   cou << "[version 2] the contents of v4 are:";
   for (int& item : v4)  {
     cout << " " << item;
   }
   cout << endl;
   cout << "[version 3] the contents of v4 are:";
   for (auto item = v4.begin(); item != v4.end(); ++item)  {
     cout << " " << *item;
   }
   cout << endl;
   // 6. modify element
   v4[0] = 5;
   // 7. sort 
   sort(v4.begin(), v4.end());
   // 8. add new element at the end of the vector
   v4.push_back(-1);
   // 9. delete the last element
   v4.pop_back();
}
```

#### 2D array usage:
```c++
#include <iostream>

template <size_t n, size_t m>
void printArray(int (&a)[n][m])  {
  for (int i = 0; i < n; i++)  {
    for (int j = 0; j < n; j++)  {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  
int main()  {
  cout << "Example I : " << endl;
  int a[2][5];
  printArray(a);
  cout << "Example II:" << endl;
  int b[2][5] = {{1, 2, 3}};
  printArry(b);
  cout << "Example III:" << endl;
  int c[][5] = {1, 2, 3, 4, 5, 6, 7};
  printArray(c);
  cout << "Example IV:" << endl;
  int d[][5] = {{1, 2, 3, 4}, {5, 6}, {7}};
  printArray(d);
}
```

### Two-pointer Technique
#### Reverse the elements in an array
**use two pointers at the same time to do the iteration**
```c++
void reverse(int* v, int N)  {
  int i = 0;
  int j = N - 1;
  while(i < j )  {
    swap(v[i], v[j]);
    i++;
    j--;
  }
}
```
**Summary:**
use two-pointer when:
  - iterate the array from two ends to the middle
  - often used in a sorted array
  - One slow-runner and one fast-runner at the same time.
    - The key is to determine the movement strategy for both pointers

