#include<iostream>
#include<string>
using namespace std;
string s[65];
void divide(int y, int x, int n){
  int flag = 0;
  for(int i = y ;i<y+n;i++){
    for(int j = x ;j<x+n;j++){
      if(s[i][j] != s[y][x]) flag = 1;
    }
  }
  if(flag == 0){
    cout<<s[y][x];
  }
  else{
    cout<<"(";
    divide(y, x, n/2);
    divide(y, x + n/2, n/2);
    divide(y + n/2, x, n/2);
    divide(y + n/2, x + n/2, n/2);
    cout<<")";
  }
}
int main(void){
  int n;

  cin>>n;
  for(int i = 0 ;i<n;i++) cin>>s[i];
  divide(0,0,n);
  return 0;
}
