#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(void){
  int N,K,time=100001,count=0;
  cin>>N>>K;
  vector<bool> visited(100001, 0);
  queue<pair<int, int>> q;
  q.push({N, 0});
  visited[N] = 1;
  while(!q.empty()){
    pair<int, int> now = q.front();
    visited[now.first] = 1;
    if(now.first == K){
      time = min(time, now.second);
      if(now.second == time) count++;
    }
    q.pop();
    int next1 = now.first - 1;
    int next2 = now.first + 1;
    int next3 = now.first * 2;
    if(next1>=0 && !visited[next1]){
      q.push({next1, now.second + 1});
    }
    if(next2<=100000 && !visited[next2]){
      q.push({next2, now.second + 1});
    }
    if(next3<=100000 && !visited[next3]){
      q.push({next3, now.second + 1});
    }
  }
  cout<<time<<'\n'<<count;
  return 0;
}
