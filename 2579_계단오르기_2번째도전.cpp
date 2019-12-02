#include<iostream>
using namespace std;
int M(int a, int b){if(a>b) return a; else return b;}
int main(void){
  int c, s[304], d[304];
  cin>>c;
  for(int i = 1 ;i<=c;i++)
    cin>>s[i];
  d[1] = s[1]; d[2] = d[1] + s[2]; d[3] = M(s[1]+s[3],s[2]+s[3]);
  for(int i = 4 ;i<=c ;i++){
    d[i] = M(d[i-2]+s[i], d[i-3]+s[i-1]+s[i]);
  }
  cout<<d[c];
  return 0;
}
