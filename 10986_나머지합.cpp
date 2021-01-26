#include<iostream>
#include<vector>
using namespace std;
int main(void){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  long long N, M, result = 0;
  cin>>N>>M;
  vector<long long> sum(N+1)
  vector<int> remain(M+1);
  for(int i = 1 ; i<=N ; i++){
    cin>>sum[i];
    sum[i] += sum[i-1];
    long long r = sum[i] % M;
    if(r == 0) result++;
    result += remain[r];
    remain[r]++;
  }
  cout<<result;
  return 0;
}
