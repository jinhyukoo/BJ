//todo : BFS를 실행하되 방향을 체크하면서 방향이 달라질 경우 거울 횟수 + 1
//목표 C 지점에 도착했을 때 거울 갯수 체크하고 최소값으로 계속 초기화
#include<iostream>
#include<vector>
#include<queue>
#include<deque>
using namespace std;
int W, H, d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
vector<pair<int, int>> C_loc;
char map[101][101];
int use_mirror[101][101] = {0, };
struct data{
  int y;
  int x;
  int dir;
  int mirror;
};

bool check(int y, int x)
{
  return (y>=0 && y<H && x>=0 && x<W);
}
void input()
{
  cin>>W>>H;
  for(int i = 0 ; i<H ; i++)
  {
    for(int j = 0 ; j<W ; j++)
    {
      use_mirror[i][j] = 100000;
      cin>>map[i][j];
      if(map[i][j] == 'C') C_loc.push_back({i,j});
    }
  }
}
void doBFS()
{
  deque<struct data> dq;
  dq.push_back({C_loc[0].first, C_loc[0].second, -1, 0});
  use_mirror[C_loc[0].first][C_loc[0].second] = 0;
  while(!dq.empty())
  {
    struct data t = dq.front();
    dq.pop_front();
    for(int i = 0 ; i<4 ; i++)
    {
      int nextY = t.y + d[i][0], nextX = t.x + d[i][1];

      if(check(nextY, nextX) && map[nextY][nextX] != '*')
      {
        if(t.dir == i || t.dir == -1)
        {
          if(t.mirror <= use_mirror[nextY][nextX])
          {
            dq.push_front({nextY, nextX, i, t.mirror});
            use_mirror[nextY][nextX] = t.mirror;
          }
        }
        else
        {
          if(t.mirror + 1 <= use_mirror[nextY][nextX])
          {
            dq.push_back({nextY, nextX, i, t.mirror + 1});
            use_mirror[nextY][nextX] = t.mirror + 1;
          }
        }
      }
    }
  }
}
int main(void)
{
  input();
  doBFS();
  cout<<use_mirror[C_loc[1].first][C_loc[1].second];
  return 0;
}
