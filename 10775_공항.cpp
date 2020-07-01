#include<iostream>
using namespace std;
int parent[100001];
int find(int u)
{
  if(u == parent[u]) return u;
  return parent[u] = find(parent[u]);
}
void merge(int u, int v)
{
  u = find(u); v = find(v);
  if(u == v) return;
  parent[v] = u;
}
int main(void)
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int G,P,p_count = 0;
  cin>>G>>P;
  for(int i = 0 ; i<=G ; i++) parent[i] = i;
  for(int i = 0 ; i<P ; i++)
  {
    int g, temp;
    cin>>g;
    temp = find(g);
    if(temp == 0) break;
    if(temp == g) merge(g-1,g);
    else if(temp < g) merge(temp-1,temp);
    p_count++;
  }
  cout<<p_count;
  return 0;
}
