#include<iostream>
#include<queue>
#include<deque>
#include<vector>
using namespace std;
char map[102][102];
pair<int, int> prisoner[3];
int T, h, w, dist[102][102][4], d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}, answer;
bool check_bound(int y, int x)
{
  return(y>=0 && y<=h+1 && x>=0 && x<=w+1);
}
void input()
{
  //죄수 위치 미리 확인
  //맵의 바깥쪽은 .으로 채워주기
  bool flag = 0;
  cin>>h>>w;
  for(int i = 0 ; i<=h+1 ; i++)
  {
    for(int j = 0 ; j<=w+1 ; j++)
    {
      dist[i][j][0] = -1; dist[i][j][1] = -1; dist[i][j][2] = -1; dist[i][j][3] = 0;
      if(i == 0 || i == h+1 || j == 0 || j == w+1){
        map[i][j] = '.';
        continue;
      }
      cin>>map[i][j];
      if(map[i][j]=='$')
      {
        if(!flag){
          prisoner[flag].first = i;
          prisoner[flag].second = j;
          flag = 1;
        }
        else{
          prisoner[flag].first = i;
          prisoner[flag].second = j;
        }
      }
    }
  }
  //상근이의 위치도 입력
  prisoner[2].first = 0; prisoner[2].second = 0;
}
void doBFS(int y, int x, int n)
{
  deque<pair<int, int>> q;
  q.push_back({y,x});
  dist[y][x][n] = 0;
  while(!q.empty())
  {
    pair<int, int> t = q.front();
    q.pop_front();
    for(int i = 0 ; i<4 ; i++)
    {
      int nextY = t.first + d[i][0], nextX = t.second + d[i][1];
      if(check_bound(nextY, nextX) && map[nextY][nextX] != '*' && dist[nextY][nextX][n] == -1)
      {
        //비용이 적은 것을 우선적으로 탐색한다. '.'일 경우 push_front를 해줌으로써 먼저 탐색
        if(map[nextY][nextX] == '#')
        {
          dist[nextY][nextX][n] = dist[t.first][t.second][n] + 1;
          q.push_back({nextY, nextX});
        }
        else
        {
          dist[nextY][nextX][n] = dist[t.first][t.second][n];
          q.push_front({nextY, nextX});
        }
      }
    }
  }
}
void find_answer()
{
  //값들 더하기
  int temp = 1000000;
  for(int i = 0 ; i<=h+1 ; i++)
  {
    for(int j = 0 ; j<=w+1 ; j++)
    {
      if(map[i][j] == '#') dist[i][j][3] = dist[i][j][0] + dist[i][j][1] + dist[i][j][2] - 2;
      else dist[i][j][3] = dist[i][j][0] + dist[i][j][1] + dist[i][j][2];
    }
  }
  //최소값 찾기
  for(int i = 0 ; i<=h+1 ; i++)
  {
    for(int j = 0 ; j<=w+1 ; j++)
    {
      if(map[i][j] != '*' && dist[i][j][3] < temp) temp = dist[i][j][3];
    }
  }
  cout<<temp<<'\n';
}
int main(void)
{
  cin>>T;
  for(int i = 0 ; i<T ; i++)
  {
    input();
    for(int j = 0 ; j<3 ; j++) doBFS(prisoner[j].first, prisoner[j].second, j);
    find_answer();
  }
  return 0;
}
