#include<iostream>
using namespace std;
int main(void){
  long long n;
  int arr[1500002] = {0, };
  cin>>n;
  arr[0] = 0, arr[1] = 1;
  for(int i = 2 ;i<=1500000;i++){
    arr[i] = arr[i-2] + arr[i-1];
    arr[i] = arr[i]%1000000;
  }
  cout<<arr[n%1500000];
  return 0;
}
