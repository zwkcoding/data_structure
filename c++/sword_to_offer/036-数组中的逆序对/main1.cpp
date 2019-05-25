 // count += (mid - i + 1); 
 // 从左侧正数移动指针开始判断，若左边该元素大，那么左边该元素的后面元素(有mid - i + 1)一定也比右边对应元素大，
// 则左边该元素的逆序对为 mid - i + 1

class Solution {
private:
    int MergeElem(vector<int> &elem, int start, int mid, int end, vector<int> &temp)//数组的归并操作
    {
        // int leftLen=mid-start+1; //elem[start...mid]左半段长度
        // int rightLlen=end-mid;   //elem[mid+1...end]右半段长度
        int i = start;
        int j = mid+1;
        int k = 0;      //临时数组末尾坐标
        int count = 0;
        //设定两个指针ij分别指向两段有序数组的头元素，将小的那一个放入到临时数组中去。
        while(i <= mid && j <=end)
        {
            if(elem[i] > elem[j])
            {
                count += (mid - i + 1);  // key condition
                count %= 1000000007;
                temp[k++] = elem[j++];
            }
            else
            {
                temp[k++] = elem[i++];
            }
        }
       // 判断哪个子数组中有剩余的数据
        int  start0 = i, end0 = mid;
        if (j < end)  {
            start0 = j;
            end0 = end;
        }

        while(start0 <= end0)
        {
            temp[k++] = elem[start0++];
        }

        //将临时数组中的元素写回到原数组当中去。
        for(i = 0; i < k; i++)
        {
            elem[start+i] = temp[i];
        }
        
        return count;

    }
    
    int InverseCore(vector<int> &data, int i, int j, vector<int> &temp)  {
        int reverse_count = 0;
        if(i < j) {
        int mid = (i + j)/2;
        reverse_count += InverseCore(data, i, mid, temp);
        reverse_count += InverseCore(data, mid+1, j, temp);
        reverse_count += MergeElem(data, i, mid, j, temp);
        }
        return reverse_count%1000000007;
    }
    
public:
    int InversePairs(vector<int> data) {
        if(data.size() == 0) return 0;
        vector<int> temp(data.size());
        return (InverseCore(data, 0, data.size() - 1, temp))%1000000007;
    }
};
