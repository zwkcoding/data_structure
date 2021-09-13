## 跳表

### paper resources
[跳表（skiplist）的代码实现 - 刘浩de技术博客 - 博客园](https://www.cnblogs.com/liuhao/archive/2012/07/26/2610218.html)  
[(5条消息)浅析SkipList跳跃表原理及代码实现 - 庖丁解牛 - CSDN博客](https://blog.csdn.net/ict2014/article/details/17394259)


[Skip Lists](https://www.csee.umbc.edu/courses/341/fall01/Lectures/SkipLists/skip_lists/skip_lists.html)

[skiplists.pdf](https://www.cs.cmu.edu/~ckingsf/bioinfo-lectures/skiplists.pdf)

[An Analysis of Skip Lists](https://eugene-eeo.github.io/blog/skip-lists.html)



### geektime
- **链表加多级索引的结构，就是跳表**：跳表使用空间换时间的设计思路，通过构建多级索引来提高查询的效率，实现了基于链表的“二分查找”。
  ![](images/46d283cd82c987153b3fe0c76dfba8a9.jpg)
- 支持查找操作，还支持动态的插入、删除操作，而且插入、删除操作的时间复杂度也是 **O(logn)**
- 跳表索引动态更新![](images/a861445d0b53fc842f38919365b004a7.jpg)
- Redis 中的有序集合是通过跳表来实现的,Redis 中的有序集合支持的核心操作主要有下面这几个：

  *   插入一个数据；
  
  *   删除一个数据；
  
  *   查找一个数据；
  
  *   按照区间查找数据（比如查找值在 \[100, 356\] 之间的数据）；
  
  *   迭代输出有序序列。

- 按照区间来查找数据这个操作，红黑树的效率没有跳表高。
  >  - 对于按照区间查找数据这个操作，跳表可以做到 O(logn)  的时间复杂度定位区间的起点，然后在原始链表中顺序往后遍历就可以了。这样做非常高效。    
  >  - 跳表也不能完全替代红黑树。因为红黑树比跳表的出现要早一些，很多编程语言中的 Map 类型都是通过红黑树来实现的。我们做业务开发的时候，直接拿来用就可以了，不用费劲自己去实现一个红黑树，但是跳表并没有一个现成的实现，所以在开发中，如果你想使用跳表，必须要自己实现。

