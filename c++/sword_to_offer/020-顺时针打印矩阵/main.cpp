class Solution {
private:
    int rows, cols;
    bool check(int i, int j, vector<vector<bool> >& flag)  {
        // inside mat and not visit record
        return (0 <= i && (i < rows) && 0 <= j && (j < cols)  && !flag[i][j]);
    }
public:
    vector<int> printMatrix(vector<vector<int> > mat) {
        rows = mat.size();
        cols = mat[0].size();
        vector<int> ans;
        if(rows == 0 || cols== 0)  {
            return ans;
        }
        int count = rows*cols;
        vector<vector<bool> > flag(rows, vector<bool>(cols,false));  // 标识矩阵
        vector<vector<int> > dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int i = 0, j = 0;
        flag[0][0] = true;
        int cur_dir = 0;
        while(count--)  {
            // push back
            ans.push_back(mat[i][j]);
            flag[i][j] = true;
            if(!check(i + dir[cur_dir][0],j + dir[cur_dir][1],flag))  {
                 // change dir when touch edge
                cur_dir++;
                cur_dir %= 4; 
            }
             // move forward 一点要放在 check 之后，否则很容易出现数组越界
            i += dir[cur_dir][0];
            j += dir[cur_dir][1];
        }
        return ans;

    }
};
