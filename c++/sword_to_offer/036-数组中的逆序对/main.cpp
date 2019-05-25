// count += j-mid;
// 从左侧倒数移动指针开始判断，若左边大，则左边该元素的逆序对为 j-mid
class Solution {
private:
    int merge(vector<int> &data, int l, int r, vector<int> &temp)  {
        int mid = (l + r)/2 ;
        int i = mid;
        int j = r;
        int k = 0;      //临时数组末尾坐标
        int count = 0;
        while(i >= l && j > mid)  {
            if(data[i] > data[j])  {
                temp[k++] = data[i--];
                count += j-mid;    // 因为elem[mid+1...j...end]是有序的，如果elem[i]>elem[j]，那么也大于elem[j]之前的元素，从a[mid+1...j]一共有j-(mid+1)+1=j-mid
                count %= 1000000007;
            } else  {
                temp[k++] = data[j--];
            }
        }
        
        if(i >= l )  {
            // 左边还有元素
            while(i >= l) {
                temp[k++] = data[i--];
            }
        }
        if(j > mid)  {
            //  右边还有元素
            while(j > mid) {
                temp[k++] = data[j--];
            }
        }
         // 将临时数组中的元素写回到原数组当中去
        for(int i = 0; i < k; i++)  {
            data[r-i] = temp[i];
        }
        return count;

    }
    int InverseCore(vector<int> &data, int i, int j, vector<int> &temp)  {
        int reverse_count = 0;
        if(i < j) {
        int mid = (i + j)/2;
        reverse_count += InverseCore(data, i, mid, temp);
        reverse_count += InverseCore(data, mid+1, j, temp);
        reverse_count += merge(data, i, j, temp);
        }
        return reverse_count%1000000007;
    }
public:
    int InversePairs(vector<int> data) {
        if(data.size() == 0) return 0;
        vector<int> temp(data.size());
        return InverseCore(data, 0, data.size() - 1, temp);
    }
};
