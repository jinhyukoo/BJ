#include<iostream>
#include<vector>
using namespace std;
struct OptimizedDisjointSet {
    vector<int> parent, rank;
    OptimizedDisjointSet (int n) : parent(n), rank(n,1) {
        for (int i=0 ; i < n; i++)
        {
          parent[i] = i;
        }
    }

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]); //find 최적화를 위한 작업, 부모가 같은 것들에 대해 동일한 부모로 바꿔준다.
    }

    void merge (int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return;
        if (rank[u] > rank[v]) swap(u, v); //tree의 높이를 줄이기 위해 rank를 설정한다.
        parent[u] = v;
        if (rank[u] == rank[v]) ++rank[v];
    }
};
int main(void)
{
  //입력값이 매우 많기 때문에 입력 속도에서 시간을 줄여줘야 시간초과가 나지 않는다.
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin>>n>>m;
  struct OptimizedDisjointSet DJS(n+1);
  for(int i = 0 ; i<m ; i++)
  {
    int t, a, b;
    cin>>t>>a>>b;
    if(t == 0)
    {
      DJS.merge(a, b);
    }
    else
    {
      int t1, t2;
      t1 = DJS.find(a);
      t2 = DJS.find(b);
      if(t1 == t2) cout<<"YES\n";
      else cout<<"NO\n";
    }
  }
  return 0;
}
