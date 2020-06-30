#include<iostream>
#include<vector>
using namespace std;
int N,M,parent[201],rank_arr[201] = {0, };
bool map[201][201] = {0, };
vector<int> route;
int find(int n)
{
  if(n == parent[n]) return n;
  return parent[n] = find(parent[n]);
}
void merge(int u, int v)
{
  u = find(u); v = find(v);
  if(u == v) return;
  if(rank_arr[u] > rank_arr[v]) swap(u,v);
  parent[u] = v;
  if(rank_arr[u] == rank_arr[v]) ++rank[v];
}

int main(void)
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  cin>>N>>M;
  for(int i = 1 ; i<=N ; i++) parent[i] = i;
  for(int i = 1 ; i<=N ; i++)
  {
    for(int j = 1 ; j<=N ; j++)
    {
      cin>>map[i][j];
      if(map[i][j]) merge(i,j);
    }
  }
  for(int i = 0 ; i<M ; i++)
  {
    int t;
    cin>>t;
    route.push_back(t);
  }
  int initial_route = find(route[0]);
  for(int i = 1 ; i<route.size() ; i++)
  {
    if(initial_route != find(route[i])){
      cout<<"NO";
      return 0;
    }
  }
  cout<<"YES";
  return 0;
}
