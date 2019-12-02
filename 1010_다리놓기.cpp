#include<iostream>
using namespace std;
int main(void){
  int c,a,b;
  cin>>c;
  for(int i = 0 ;i<c;i++){
    cin>>a>>b;
    int iter;
    if(a>(b/2)) iter = b-a;
    else iter = a;
    unsigned long long r=1, d=1;
    for(int j = 0 ;j<iter;j++) r*=(b-j);
    for(int k = 1 ;k<=iter;k++) d*=k;
    cout<<r/d<<endl;
  }
  return 0;
}
