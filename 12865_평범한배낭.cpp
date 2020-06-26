#include<iostream>
using namespace std;
int main(void)
{
  int N, K, W[101] = {0, }, V[101] = {0, }, dp[100001] = {0, }, r=0;
  cin>>N>>K;
  for(int i = 0 ; i<N ; i++)
  {
    cin>>W[i]>>V[i];
  }
  for(int i = 0 ; i<N ; i++)
  {
    if(W[i] > K) continue; //K 보다 큰 것은 볼 필요 없음
    else
    {
      for(int j = K-W[i] ; j>=0 ; j--)
      {
        if(W[i] == K-W[i] && dp[W[i]] == V[i]) continue; // 똑같은 물건이 두 번 들어가는 것을 방지
        else
          dp[W[i] + j] = max(dp[W[i] + j], dp[j] + V[i]);
      }
    }
  }
  cout<<dp[K];
  return 0;
}
