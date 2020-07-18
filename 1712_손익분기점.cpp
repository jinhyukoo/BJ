#include<cstdio>
int main(void){
  int A,B,C;
  scanf("%d%d%d",&A,&B,&C);
  if(B>=C) printf("-1");
  else printf("%d",A/(C-B)+1);
}
