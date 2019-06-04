const int maxsize = 100;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};    //四个方向 
int visit_ay[maxsize][maxsize] = {0};
int sum;
class Solution {
private:
    void dfs(int x, int y, int rows, int cols, int threshold)  {
        visit_ay[x][y] = 1;
        sum++;
        for(int i = 0; i < 4; i++)  {
            int new_x = x + dx[i];    // 必须新生成一个变量，不能直接在原变量上操作
            int new_y = y + dy[i];
            int temp = new_x/10 + new_x%10 + new_y/10 + new_y%10;
            if(new_x >= 0 && new_x < cols && new_y >= 0 && new_y < rows && temp <= threshold && visit_ay[new_x][new_y] == 0)  {
                dfs(new_x,new_y, rows,cols,threshold);
            }
        }
    }
public:
    int movingCount(int threshold, int rows, int cols)
    {
         if(threshold<0)
            return 0;
        memset(visit_ay,0,sizeof(visit_ay));
        sum = 0;
        dfs(0,0,rows,cols,threshold);
        return sum;
    }
};
