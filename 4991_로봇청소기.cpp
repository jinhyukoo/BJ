#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<deque>
#include<algorithm>

using namespace std;
int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int main(void){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int w=-1, h=-1;
  while(1){
    cin>>w>>h;
    if(w == 0 && h == 0) return 0;
    vector<vector<char>> map(h, vector<char>(w));
    deque<pair<int, int>> pos;
    queue<pair<int, int>> q;
    for(int i = 0 ; i<h ; i++){
      for(int j = 0 ; j<w ; j++){
        cin>>map[i][j];
        if(map[i][j] == 'o') pos.push_front({i,j});
        if(map[i][j] == '*') pos.push_back({i,j});
      }
    }
    vector<vector<int>> dist(pos.size(), vector<int>(pos.size(), 0));
    for(int i = 0 ; i<pos.size() ; i++){
      vector<vector<int>> visited(h, vector<int>(w, -1));
      int initX = pos[i].first, initY = pos[i].second;
      q.push({initX, initY});
      visited[initX][initY] = 0;
      while(!q.empty()){
        pair<int, int> now = q.front();
        int nowY = now.first, nowX = now.second;
        q.pop();
        for(int j = 0 ; j<4 ; j++){
          int nextY = nowY + d[j][0], nextX = nowX + d[j][1];
          bool boundCheck = nextY>=0 && nextX>=0 && nextY<h && nextX<w;
          if(!boundCheck) continue;
          bool mapCheck = map[nextY][nextX] != 'x';
          bool visitCheck = visited[nextY][nextX] == -1;
          if(mapCheck && visitCheck){
            q.push({nextY, nextX});
            visited[nextY][nextX] = visited[nowY][nowX] + 1;
          }
        }
      }
      for(int j = 0 ; j<pos.size() ; j++){
        pair<int, int> target = pos[j];
        dist[i][j] = visited[target.first][target.second];
      }
    }
    vector<int> v(pos.size() - 1);
    int result = 10000000, temp = 0;
    bool flag = 0;
    for(int j = 0 ; j<pos.size() - 1 ; j++) v[j] = j+1;
    do{
      if(dist[0][v[0]] == -1){
        cout<<-1<<'\n';
        flag = 1;
        break;
      }
      temp += dist[0][v[0]];
      for(int j = 0 ; j<pos.size() - 2 ; j++){
        temp += dist[v[j]][v[j+1]];
      }
      if(result > temp) result = temp;
      temp = 0;
    }while(next_permutation(v.begin(),v.end()));
    if(!flag) cout<<result<<'\n';
  }
  return 0;
}
