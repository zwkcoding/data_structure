## Linked List

### Singly Linked List
#### Node Definition
```c++
struct SinglyListNode  {
  int val;
  SinglyListNode *nect;
  SinglyListNode(int x) : val(x), next(NULL)  {}
};
```
#### Add Operation
time complexity: O(1)
  - add a node at the beginning  
  ```c++

      node* new_node = new node();
      if(head == nullptr)  {
        head = new_node;
      }
  ```
  - add a node at the end

#### Delete Operation
  - delete the tail node 
  ```c++
  
    if(cur->next == nullptr)  {
      cur = nullptr;
    }
  ```

#### Two Pointer Technique
##### slow-pointer and fast-pointer problem
**A classic problem**  
  - just check
```c++
bool hasCycle(ListNode* head)  {
  ListNode* slow = head;
  ListNode* fast = head;
  while/*slow != NULL && */ fast != NULL && fast->next != NULL)  {
    slow = slow->next;
    fast = fast->next->next;
    
    if(slow == fast)  return true;
  }
  
  return false;
}
```
Above Time Complexity: set the list length is M, then the O = O(M)

  - first check, then find the entry node of the circle
  ```c++
    ListNode* detectCircle(ListNode* head)  {
      if(head == NULL || head->next == NULL)
        return NULL;
      
      ListNode* slow = head;
      ListNode* fast = head;
      ListNode* entry = head;
      
      while(fast->next && fast->next->next)  {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast)  {
          while(slow != entry)  {
            slow = slow->next;
            entry = entry->next;
          }
          return entry;
        }
      }
      return NULL;
    }
  ```
  


