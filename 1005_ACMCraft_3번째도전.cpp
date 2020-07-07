#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(void)
{
  int T, N, K, X, Y, W;
  cin>>T;
  for(int i = 0 ; i<T ; i++)
  {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>K;
    vector<int> build_time(N+1), total_build_time(N+1), in_count(N+1, 0);
    vector<vector<int>> out(N+1);
    queue<int> q;
    for(int j = 1 ; j<=N ; j++)
    {
      cin>>build_time[j];
    }
    for(int j = 0 ; j<K ; j++)
    {
      cin>>X>>Y;
      out[X].push_back(Y);
      in_count[Y]++;
    }
    cin>>W;
    for(int j = 1 ; j<=N ; j++)
    {
      if(in_count[j] == 0) q.push(j);
      total_build_time[j] = build_time[j];
    }
    while(!q.empty())
    {
      int temp = q.front();
      q.pop();
      for(int j = 0 ; j<out[temp].size() ; j++)
      {
        int del = out[temp][j];
        total_build_time[del] = max(total_build_time[del], total_build_time[temp] + build_time[del]);
        in_count[del]--;
        if(in_count[del] == 0) q.push(del);
      }
    }
    cout<<total_build_time[W]<<'\n';
  }
  return 0;
}
