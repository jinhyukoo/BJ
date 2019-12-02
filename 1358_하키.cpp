#include<iostream>
using namespace std;
struct xy{
  int x;
  int y;
};
int main(void){
  int W,H,X,Y,P,r=0;
  struct xy loc[101];
  cin>>W>>H>>X>>Y>>P;
  for(int i = 0 ;i<P;i++) cin>>loc[i].x>>loc[i].y;
  for(int i = 0; i<P;i++){
    int x = loc[i].x, y = loc[i].y;
    if(x<X || y<Y){
      if((X-x)*(X-x) + (Y+H/2-y)*(Y+H/2-y) <= (H*H)/4) r++;
    }
    else if(x>X+W || y>Y+H){
      if((X+W-x)*(X+W-x) + (Y+H/2-y)*(Y+H/2-y) <= (H*H)/4) r++;
    }
    else{
      if(x>=X && x<=X+W && y>=Y && y<=Y+H) r++;
    }
  }
  cout<<r;
  return 0;
}
