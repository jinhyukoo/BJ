#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int R, C, mineral = 0, d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
char map[101][101] = {};
vector<int> input_v;
int check[101][101] = {0, };
//todo : input 받기
void input()
{
  int N, temp;
  cin>>R>>C;
  for(int i = 1 ; i<=R ; i++)
  {
    for(int j = 1 ; j<=C ; j++)
    {
      cin>>map[i][j];
      if(map[i][j] == 'x') mineral++;
    }
  }
  cin>>N;
  for(int i = 0 ; i<N ;i++)
  {
    cin>>temp;
    input_v.push_back(temp);
  }
}
//todo : map밖으로 나가지 않게 범위 측정
bool check_bound(int y, int x)
{
  return (y>0 && y<=R && x>0 && x<=C);
}
//todo : 왼쪽 오른쪽 구분하여 미네랄 제거, 제거 할 미네랄 없을 시도 고려
bool crash(int h, int n)//h는 높이, n은 홀수 짝수 구분, h를 넣을 때 R-h로 넣어줘야 함.
{
  bool flag = 0;
  if(n%2 == 0)//왼쪽 부수는 경우
  {
    for(int i = 1 ; i<=C ; i++)
    {
      if(map[h][i] == 'x')
      {
        map[h][i] = '.';
        flag = 1;
        mineral--;
        break;
      }
    }
  }
  else//오른쪽 부수는 경우
  {
    for(int i = C ; i>0 ; i--)
    {
      if(map[h][i] == 'x')
      {
        map[h][i] = '.';
        flag = 1;
        mineral--;
        break;
      }
    }
  }
  return flag; //flag가 1이면 부숴진 것, 아니면 안 부숴진 것
}
void print_map()
{
  for(int i = 1 ; i<=R ; i++)
  {
    for(int j = 1 ; j<=C ; j++)
      cout<<map[i][j];
    cout<<'\n';
  }
}
//todo : 클러스터 찾아낸 후 공중에 떠 있는 클러스터 아래로 내리기
bool floor_BFS() //공중에 떠 있는 클러스터가 있는지 확인
{
  memset(check, 0, sizeof(check));
  int temp_mineral = 0;
  queue<pair<int, int>> q;
  for(int i = 1 ; i<=C ; i++) //바닥을 돌며 BFS 실행
  {
    if(map[R][i] == 'x')
    {
      q.push({R,i});
    }
  }
  while(!q.empty())
  {
    pair<int, int> t = q.front();
    q.pop();
    temp_mineral++;
    check[t.first][t.second] = 1;
    for(int i = 0 ; i<4 ; i++)
    {
      int nextY = t.first + d[i][0], nextX = t.second + d[i][1];
      if(check_bound(nextY, nextX) && !check[nextY][nextX] && map[nextY][nextX] == 'x')
      {
        q.push({nextY, nextX});
        check[nextY][nextX] = 1;
      }
    }
  }

  if(temp_mineral == mineral)
  {
    return 0;
  }
  for(int i = 1 ; i<=R ; i++)
  {
    for(int j = 1 ; j<=C ; j++)
    {
      if(map[i][j] == 'x' && check[i][j] == 0)
      {
        q.push({i,j});
        break;
      }
    }
  }
  while(!q.empty())
  {
    pair<int, int> t = q.front();
    q.pop();
    check[t.first][t.second] = 2;
    for(int i = 0 ; i<4 ; i++)
    {
      int nextY = t.first + d[i][0], nextX = t.second + d[i][1];
      if(check_bound(nextY, nextX) && !check[nextY][nextX] && map[nextY][nextX] == 'x')
      {
        q.push({nextY, nextX});
        check[nextY][nextX] = 2;
      }
    }
  }
  return 1;
}
int check_Distance(int y, int x)
{
  int distance = 0;
  for(int i = y+1 ; i<=R ; i++)
  {
    if(check[i][x] == 2) //아래쪽에 클러스터의 일부분이 존재하는 경우 처리할 필요 없음.
    {
      return 1000;
    }
    if(check[i][x] == 0) distance++; //비어있는 경우 거리 증가
    if(check[i][x] == 1) return distance; //떠있는 클러스터가 아닌 다른 클러스터를 만나면 return;
  }
  return distance; //바닥에 닿으면 return
}
void drop_Cluster()
{
  //todo : 떨어져야 할 거리 측정
  int drop_distance = 1000;
  for(int i = R ; i>0 ; i--)
  {
    for(int j = 1 ; j<=C ; j++)
    {
      if(check[i][j] == 2)
      {
        int temp_distance = check_Distance(i,j);
        drop_distance = min(drop_distance, temp_distance); //최소 값을 찾아서 넣어준다.
      }
    }
  }
  //todo : 클러스터 떨구기
  for(int i = R ; i>0 ; i--)
  {
    for(int j = 1 ; j<=C ; j++)
    {
      if(check[i][j] == 2)
      {
        map[i][j] = '.';
        map[i+drop_distance][j] = 'x';
      }
    }
  }
}

int main(void)
{
  input();
  for(int i = 0 ; i<input_v.size() ; i++)
  {
    bool tf;
    tf = crash(R-input_v[i]+1, i);
    if(!tf) continue;
    tf = floor_BFS();
    if(!tf) continue;
    drop_Cluster();
  }
  print_map();
  return 0;
}
