class Solution {
private:
    bool judge(vector<int> &seq, int left, int right)  {
        if(left >= right)  {
            return true;    // terminate condition
        }
        
        int mid  = right - 1;
        while(seq[mid] > seq[right])  {
            mid--;
            if(mid <= left)  {
                return true;    // 退化成链表
            }
        }
        
        // 退化成链表 
        // if(mid < left)  {
        //    return false;    // no left subtree
        // }
        
        int i = left;
        while(seq[i] < seq[right] && i < mid)  {
            i++;
        }
        if(i < mid)  {
            return false;    // it should less than root for all left subtree node
        }
        return judge(seq, left, mid)  && judge(seq, mid+1, right-1);
    }
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size( ) == 0)
        {
            return false;
        }

        return judge(sequence, 0, sequence.size( ) - 1);

    }
};
