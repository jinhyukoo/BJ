#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<stack>
using namespace std;
struct info{
  int loc;
  int time;
};
vector<int> parents(100001), visited(100001, 0);
stack<int> s;
int find(int x){
  if(parents[x] == x) return x;
  s.push(parents[x]);
  return find(parents[x]);
}

void merge(int p, int x){
  if(p == x) return;
  parents[x] = p;
}

int main(void){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int N,K;
  cin>>N>>K;
  for(int i = 0 ; i<=N ; i++) parents[i] = i;
  deque<struct info> dq;
  dq.push_back({N, 0});
  visited[N] = 1;
  while(!dq.empty()){
    struct info now = dq.front();
    int loc = now.loc, time = now.time;
    dq.pop_front();
    if(loc == K){
      cout<<time<<'\n';
      find(K);
      while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
      }
      cout<<K<<" ";
      return 0;
    }
    int plus = loc + 1;
    int minus = loc - 1;
    int jump = loc * 2;
    if(plus <= 100001 && !visited[plus]){
      visited[plus] = 1;
      dq.push_back({plus, time + 1});
      merge(loc, plus);
    }
    if(minus >= 0 && !visited[minus]){
      visited[minus] = 1;
      dq.push_back({minus, time + 1});
      merge(loc, minus);
    }
    if(jump <= 100001 && !visited[jump]){
      visited[jump] = 1;
      dq.push_front({jump, time + 1});
      merge(loc, jump);
    }
  }
  return 0;
}
