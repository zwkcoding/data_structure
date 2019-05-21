class Solution {
public:
    void reOrderArray(vector<int> &array) {
        
        for(int i = 0; i < array.size(); i++)  {
            bool isComplete = false;
            for(int j = array.size() - 1; j > i; j--)  {
                if((array[j] % 2 != 0)&&(array[j-1] % 2 == 0))  {
                    // 前偶后奇
                    swap(array[j], array[j-1]);
                    isComplete = true;
                }
            }
            if(!isComplete)  {
                return ;
            }
        }
    }
};
