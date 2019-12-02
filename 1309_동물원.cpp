#include<cstdio>
int main(void){
  int n,a,b;
  scanf("%d",&n);
  a=3;
  b=7;
  for(int i=3;i<=n;i++){
    if(i%2==1){
      int t=a;
      a=(b*2+a)%9901;
    }
    else{
      int t=b;
      b=(a*2+b)%9901;
    }
  }
  if(n%2)printf("%d",a);
  else printf("%d",b);
}
