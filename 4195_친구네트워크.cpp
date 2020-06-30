#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
struct DisjointSet {
    map<string, int> m, rank;
    map<string, string> parent;
    string find(string u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]); //find 최적화를 위한 작업, 부모가 같은 것들에 대해 동일한 부모로 바꿔준다.
    }

    void merge (string u, string v) {
        u = find(u); v = find(v);
        if (u == v) return;
        if (rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        m[v] += m[u];
        if (rank[u] == rank[v]) ++rank[v];
    }
};
int main(void)
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int T;

  cin>>T;
  for(int i = 0 ; i<T ; i++)
  {
    struct DisjointSet DJS;
    int F;
    cin>>F;
    for(int j = 0 ; j<F ; j++)
    {

      bool friend1_flag = 0, friend2_flag = 0;
      string friend1, friend2;
      cin>>friend1>>friend2;
      if(DJS.parent.find(friend1) == DJS.parent.end())
      {
        DJS.m.insert({friend1,1});
        DJS.parent.insert({friend1,friend1});
        DJS.rank.insert({friend1,1});
      }
      if(DJS.parent.find(friend2) == DJS.parent.end())
      {
        DJS.m.insert({friend2,1});
        DJS.parent.insert({friend2,friend2});
        DJS.rank.insert({friend1,2});
      }
      DJS.merge(friend1, friend2);
      cout<<DJS.m.find(DJS.find(friend2))->second<<'\n';
    }
  }
  return 0;
}
