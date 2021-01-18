#include<iostream>
#include<queue>
#include<deque>
using namespace std;
int main(void){
  int N,K,time=100001;
  cin>>N>>K;
  vector<bool> visited(100001, 0);
  deque<pair<int, int>> dq;
  dq.push_back({N, 0});
  visited[N] = 1;
  while(!dq.empty()){
    pair<int, int> now = dq.front();
    visited[now.first] = 1;
    if(now.first == K){
      cout<<now.second;
      return 0;
    }
    dq.pop_front();
    int next1 = now.first - 1;
    int next2 = now.first + 1;
    int next3 = now.first * 2;
    if(next1>=0 && !visited[next1]){
      dq.push_back({next1, now.second + 1});
    }
    if(next2<=100000 && !visited[next2]){
      dq.push_back({next2, now.second + 1});
    }
    if(next3<=100000 && !visited[next3]){
      dq.push_front({next3, now.second});
    }
  }
}
