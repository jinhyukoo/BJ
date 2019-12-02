// #include<iostream>
#include<cstdio>
using namespace std;
int main(void){
  int n, dp[1001], arr[1001],r=0;
  // cin>>n;
  scanf("%d",&n);
  // for(int i = 0 ;i<n;i++) cin>>arr[i];
  for(int i=0;i<n;i++)scanf("%d",&arr[i]);
  dp[0]=1;
  for(int i=0;i<n;i++){
    int m = 0;
    for(int j=0;j<i;j++){
      if(arr[j]<arr[i]&&dp[j]>m)m=dp[j];
    }
    dp[i]=m+1;
  }
  for(int i=0;i<n;i++){
    if(dp[i]>r)r=dp[i];
  }
  // cout<<r;
  printf("%d",r);
  return 0;
}
