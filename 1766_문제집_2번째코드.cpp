#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//todo : 인풋 입력받기
//todo : 위상정렬하기, 오름차순으로 해야함.
//todo : greedy 느낌으로 인접차수가 없는 것을 계속 찾아서 answer에 입력하자
int main(void)
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, M;
  cin>>N>>M;
  vector<int> answer, in(N+1, 0);
  vector<vector<int>> input(N+1);
  priority_queue<int, vector<int>, greater<int>> pq;
  for(int i = 0 ; i<M ; i++)
  {
    int n1, n2;
    cin>>n1>>n2;
    input[n1].push_back(n2);
    in[n2]++;
  }
  for(int i = 1 ; i<=N ; i++)
  {
    if(in[i] == 0)
    {
      pq.push(i);
    }
  }
  while(!pq.empty())
  {
    int temp = pq.top();
    cout<<temp<<" ";
    pq.pop();
    for(int i = 0 ; i<input[temp].size() ; i++)
    {
      int des = input[temp][i];
      in[des]--;
      if(in[des] == 0) pq.push(des);
    }
  }
  return 0;
}
