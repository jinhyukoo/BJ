#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(void){
  int N, p[100001] = {0, };
  vector<int> v[100001];
  queue<int> q;
  cin>>N;
  for(int i = 0 ;i<N-1;i++){
    int t1, t2;
    cin>>t1>>t2;
    v[t1].push_back(t2);
    v[t2].push_back(t1);
  }
  q.push(1);
  while(!q.empty()){
    int t = q.front();
    q.pop();
    for(int i = 0 ; i<v[t].size(); i++){
      if(p[v[t][i]] == 0){
        p[v[t][i]] = t;
        q.push(v[t][i]);
      }
    }
  }
  for(int i = 2 ;i<=N;i++) cout<<p[i]<<'\n';
  return 0;
}
