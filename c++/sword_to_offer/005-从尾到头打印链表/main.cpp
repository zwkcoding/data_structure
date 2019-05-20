/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
private:
    vector<int> res;
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        if(head != nullptr)  {
            printListFromTailToHead(head->next);
            res.push_back(head->val);
        }
        return res;
        
        
    }
};
