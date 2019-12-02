#include<bits/stdc++.h>
using namespace std;
int main(void){
  int a,b,n,w,r1=-1,r2=-1,count=0;
  cin>>a>>b>>n>>w;
  for(int i = 1 ; i<n;i++){
      if(((a*i)+(b*(n-i))) == w){r1=i;r2=n-i;count++;}
    }
  if((r1 == -1 && r2==-1)||(count!=1)) cout<<-1;
  else cout<<r1<<" "<<r2;
  return 0;
}
