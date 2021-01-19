#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 987654321;

int main(void){
  int t;
  cin>>t;
  while(t--){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int N, D, C, count = 0, time = 0;
    cin>>N>>D>>C;
    vector<pii> v[N+1];
    vector<int> dist(N+1, MAX);
    priority_queue<pii, vector<pii>, greater<>> pq;
    for(int i = 0 ; i<D ; i++){
      int a, b, s;
      cin>>a>>b>>s;
      v[b].push_back({s, a});
    }
    dist[C] = 0;
    pq.push({0, C});
    while(!pq.empty()){
      pii now = pq.top();
      int nowIdx = now.second, nowValue = now.first;
      pq.pop();
      for(int i = 0 ; i<v[nowIdx].size() ; i++){
        pii next = v[nowIdx][i];
        int nextIdx = next.second, nextValue = next.first;
        if(dist[nextIdx] > nowValue + nextValue){
          dist[nextIdx] = nowValue + nextValue;
          pq.push({dist[nextIdx], nextIdx});
        }
      }
    }
    for(int i = 1 ; i<=N ; i++){
      if(dist[i] != MAX){
        count++;
        time = max(time, dist[i]);
      }
    }
    cout<<count<<" "<<time<<'\n';
  }

  return 0;
}
