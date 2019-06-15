#include <iostream>
#include <cstring>   // memset
#include <queue>    // priority queue
#include <cmath>    // sqrt, pow
#include <utility>  // pair
#include <stack> 

using namespace std;
typedef pair<int ,int> Pair;
const int ROW = 5;  // map row
const int COL = 5;  // map column

const int INT_MAX = 10000;

struct Node {
  int y;
  int x;
  int parent_x;
  int parent_y;
  double g;
  double h;
  double f;
};

/// compator
class Compare
{
  public:
    bool operator() (const Node& l, const Node& r)  {
      // min-heap
      return l.g > r.g;
    }
};


/// judge inside map
bool isVaild(int x, int y)  {
  if(x < 0 || x >= ROW || y < 0 || y >= COL)  {
    return false;
  }
  return true;
}

/// judeg block
bool isUnBlock(int grid[][COL], int row, int col)  {
  if(grid[row][col] == 1)
    return true;
  else
    return false;
}

bool isGoal(int x, int y, Node dest)  {
  if(x == dest.x && y == dest.y)
    return true;
  else
    return false;
}

/// trace path
void tracePath(Node node_map[][COL], Node dest)  {
  cout << "found goal \n The path is " << endl;

  int row = dest.x;
  int col = dest.y;

  stack<Pair> path;
  vector<Node> result_path;
  while(!( (node_map[row][col].x != -1) && (node_map[row][col].y != -1) &&
  (node_map[row][col].parent_x == row) && (node_map[row][col].parent_y == col)))  {
    path.push(make_pair(row, col));
    int temp_row = node_map[row][col].parent_x;
    int temp_col = node_map[row][col].parent_y;
    row = temp_row;
    col = temp_col;
    // printf("(%d, %d)", row, col);

  }


  path.push(make_pair(row, col));   // start node of path

  // reverse path : from start to end
  while(!path.empty())  {
    Pair tmp = path.top();
    path.pop();
    printf("(%d, %d)", tmp.first, tmp.second);
  }

  return ;
}

/// calc heuristic value
double calcHeurist(int x, int y, Node dest)  {
  // use euid distacne
  double h = (sqrt(pow((x - dest.x),2) + pow((y - dest.y),2)));
  return h;
}

void  aStar(int grid[][COL], Node src, Node dest)  {
  vector<Node> open;
  // judge start and dest vaildness
  if(isVaild(src.x, src.y) == false)  {
    printf("source is invaild");
    return;
  }
  if(isVaild(dest.x, dest.y) == false)  {
    printf("destination is invaild");
    return;
  }

  // check start and dest  block
  if(isUnBlock(grid, src.x, src.y) == false ||
      isUnBlock(grid, dest.x, dest.y) == false)  {
    printf("source or destination is blocked!");
    return;
  }

  if(isGoal(src.x, src.y, dest))  {
    printf(" destination is reached at source!");
    return;
  }

  // record expanded
  bool closed_list[ROW][COL];
  // memset(closed_list, false, sizeof(closed_list));

  // init  map
  Node node_map[ROW][COL];
  for(int x = 0; x < ROW; x++)  {
    for(int y = 0; y < COL; y++)  {
      node_map[x][y].x = x;
      node_map[x][y].y = y;
      node_map[x][y].parent_x = -1;
      node_map[x][y].parent_y = -1;
      node_map[x][y].g = INT_MAX;
      node_map[x][y].f = INT_MAX;
      node_map[x][y].h = INT_MAX;
      closed_list[x][y] = false;
    }
  }

  // initial start node 
  int x = src.x;
  int y = src.y;
 node_map[x][y].f = 0;
 node_map[x][y].g = 0;
 node_map[x][y].h = 0;
 node_map[x][y].parent_x = x;
 node_map[x][y].parent_y = y;

  priority_queue<Node,vector<Node>, Compare> open_list;
  open_list.push(node_map[x][y]);
  bool isReach = false;

  // start of A* process
  while(!open_list.empty())  {
    Node tmp;
    // to erase from open
    tmp = open_list.top();
    open_list.pop();
    int i = tmp.x;
    int j = tmp.y;
    closed_list[i][j] = false;


    // is goal
    if(isGoal(i , j , dest) == true)  {
        // found goal
        isReach = true;
        tracePath(node_map, dest);
        return;
    }
    
    // neighber child  for  4-connect
    for(int move_x = -1; move_x <= 1; move_x++)  {
      for(int move_y = -1; move_y <= 1; move_y++)  {
        double g_new, f_new, h_new;
        if(isVaild(i + move_x, j + move_y) && isUnBlock(grid,i + move_x, j + move_y))  {
          // not inside closed && isvaild && not blocked; 
          // not reopen node , considering if the heursitc is consistent
          if(closed_list[i + move_x][j + move_y] == false)  {
            g_new = tmp.g + 1.0;
            h_new = calcHeurist(i + move_x, j + move_y, dest);
            f_new = g_new + h_new;

            // update f cost
            if(node_map[i + move_x][j + move_y].f > f_new)  {
                node_map[i + move_x][j + move_y].g = g_new;
                node_map[i + move_x][j + move_y].h = h_new;
                node_map[i + move_x][j + move_y].f = f_new;
                node_map[i + move_x][j + move_y].parent_x = i;
                node_map[i + move_x][j + move_y].parent_y = j;
                open_list.push(node_map[i + move_x][j + move_y]);
            }
          }



        }
      }
    }
  }   // end of A* process

  if(isReach == false)  {
    cout << "goal is not reached!" << endl;
    return; 
  }
}



int main() {
  int map[ROW][COL] = 
  {
    {1,0,1,1,1},
    {1,0,1,1,1},
    {1,0,1,1,1},
    {1,1,1,1,1}
  };

  Node src, dest;
  // todo class init
  src.x = 0;
  src.y = 0;
  dest.x = 1;
  dest.y = 3;

  aStar(map, src, dest);

  return 0;
}
