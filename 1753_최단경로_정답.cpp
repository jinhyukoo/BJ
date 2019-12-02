#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define INF 1000000000
struct node{
  int end;
  int value;
};
struct vertex{
  int idx;
  int d;
  int p;
};
struct cmp{
  bool operator()(vertex a, vertex b){
      return a.d>b.d;
  }
};
int main(void){
  cin.tie(NULL); cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  priority_queue<vertex, vector<vertex>, cmp> pq;
  vector<struct node> n[20001];
  int V,E,S,dist[20001];
  cin>>V>>E>>S;
  for(int i = 0 ;i<E;i++){
    int t1,t2,t3;
    cin>>t1>>t2>>t3;
    n[t1].push_back({t2,t3});
  }
  for(int i = 1 ;i<=V;i++){
    dist[i] = INF;
  }
  dist[S] = 0;
  pq.push({S,0,0});
  while(!pq.empty()){
    struct vertex temp = pq.top();
    pq.pop();
    for(int i = 0;i<n[temp.idx].size();i++){
      if(dist[n[temp.idx][i].end]>n[temp.idx][i].value + temp.d){
        dist[n[temp.idx][i].end] = n[temp.idx][i].value + temp.d;
        pq.push({n[temp.idx][i].end,dist[n[temp.idx][i].end],temp.idx});
      }
    }
  }
  for(int i = 1; i<=V;i++){
    if(dist[i]==INF) cout<<"INF"<<endl;
    else cout<<dist[i]<<endl;
  }
  return 0;
}
