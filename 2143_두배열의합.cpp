#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void){
  int T, N, M;
  long long result = 0;
  cin>>T;
  cin>>N;
  vector<int> A(N);
  for(int i = 0 ; i<N ; i++) cin>>A[i];
  cin>>M;
  vector<int> B(M);
  vector<long long> sumA, sumB;
  for(int i = 0 ; i<M ; i++) cin>>B[i];
  for(int i = 0 ; i<N ; i++){
    long long sum = A[i];
    sumA.push_back(sum);
    for(int j = i + 1 ; j<N ; j++){
      sum += A[j];
      sumA.push_back(sum);
    }
  }
  for(int i = 0 ; i<M ; i++){
    long long sum = B[i];
    sumB.push_back(sum);
    for(int j = i + 1 ; j<M ; j++){
      sum += B[j];
      sumB.push_back(sum);
    }
  }
  sort(sumA.begin(), sumA.end());
  sort(sumB.begin(), sumB.end());
  for(int i = 0 ; i<sumA.size() ; i++){
    long long target = T - sumA[i];
    int lower = lower_bound(sumB.begin(), sumB.end(), target) - sumB.begin();
    int upper = upper_bound(sumB.begin(), sumB.end(), target) - sumB.begin();
    result += upper - lower;
  }
  cout<<result;
  return 0;
}
