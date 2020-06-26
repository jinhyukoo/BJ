#include<iostream>
#include<queue>
using namespace std;
int R, C, d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}, r = 0;
char map[1501][1501];
bool check[1501][1501] = {0, }, result_flag = 0;
pair<int, int> swan1, swan2;
queue<pair<int, int>> Q, WQ;
bool check_bound(int y, int x)
{
  return (y>=0 && y<R && x>=0 && x<C);
}
void input()
{
  cin>>R>>C;
  bool flag = 0;
  for(int i = 0 ; i<R ; i++)
  {
    for(int j = 0 ; j<C ; j++)
    {
      cin>>map[i][j];
      if(map[i][j] == 'L')
      {
        if(flag == 0)
        {
          swan1.first = i;
          swan1.second = j;
        }
        else
        {
          swan2.first = i;
          swan2.second = j;
        }
        WQ.push({i,j});
      }
      else if(map[i][j] == '.')
        WQ.push({i,j});
    }
  }
}
void search()
{
  queue<pair<int, int>> NQ;

  check[swan1.first][swan1.second] = 1;
  while(!Q.empty())
  {
    pair<int, int> t = Q.front();
    Q.pop();
    if(t.first == swan2.first && t.second == swan2.second)
    {
      result_flag = 1;
      break;
    }
    for(int i = 0 ; i<4 ; i++)
    {
      int nextY = t.first + d[i][0], nextX = t.second + d[i][1];
      if(!check_bound(nextY, nextX) || check[nextY][nextX] == 1) continue;
      check[nextY][nextX] = 1;
      if(map[nextY][nextX] == '.')
      {
        Q.push({nextY, nextX});
      }
      else if(map[nextY][nextX] == 'X')
      {
        NQ.push({nextY, nextX});
      }
    }
  }
  Q = NQ;
}
void changeMap()
{
  int q_size = WQ.size();
  while(q_size>0)
  {
    pair<int, int> t = WQ.front();
    WQ.pop();
    q_size--;
    for(int i = 0 ; i<4 ; i++)
    {
      int nextY = t.first + d[i][0], nextX = t.second + d[i][1];
      if(!check_bound(nextY, nextX)) continue;
      if(map[nextY][nextX] == 'X')
      {
        WQ.push({nextY, nextX});
        map[nextY][nextX] = '.';
      }
    }
  }
}
int main(void)
{
  input();
  Q.push(swan1);
  while(1)
  {
    search();
    if(result_flag == 1)
    {
      cout<<r;
      break;
    }
    changeMap();
    r++;
  }
  return 0;
}
