## Search Algorithm

[TOC]

### Binary Search
find some element in an ordered array.
Time Complexity: O(log n)
```c++
int binary_search(int start, int end, int key)  {
  int ret = -1;  // return -1 Subscript when result no result
  int mid;
  while(start <= end)  {
    mid = start + ((end - start) >> 1)  // avoid overflow
    if(arr[mid] < key)
      start = mid + 1;
    else if(arr[mid] > key)
      start = mid - 1;
    else  {  // rare conditions
      ret = mid;
      break;
    }
  }
  return ret;
}
```
- 思考题：如何在 1000 万个整数中快速查找某个整数？ 

> 二分查找可以解决的问题，用**散列表、二叉树**都可以解决。但是，我们后面会讲，不管是散列表还是二叉树，都会需要比较多的额外的内存空间。如果用散列表或者二叉树来存储这 1000 万的数据，用 100MB 的内存肯定是存不下的。而二分查找底层依赖的是数组，除了数据本身之外，不需要额外存储其他信息，是**最省内存空间**的存储方式，所以刚好能在**限定的内存大小**下解决这个问题。


