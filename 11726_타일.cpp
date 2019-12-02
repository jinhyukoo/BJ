#include<iostream>
using namespace std;
int main(void){
  long long a[1002], c;
  cin>>c;
  a[1] = 1;
  a[2] = 2;
  if(c>2){
    for(int i = 3 ;i<=c;i++)
      a[i] = (a[i-1] + a[i-2])%10007;
  }
  cout<<a[c];
  return 0;
}
