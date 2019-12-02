#include<iostream>
using namespace std;
int main(void){
  int c;
  cin>>c;
  for(int i = 0 ;i<c;i++){
    int x1,y1,r1,x2,y2,r2,xl,yl,rp,rm;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    xl = max(x2 - x1, x1 - x2);
    yl = max(y2 - y1, y1 - y2);
    rp = r1 + r2;
    rm = max(r2 - r1, r1 - r2);
    if(x1==x2 && y1==y2 && r1==r2) cout<<-1<<'\n';
    else if(rp*rp>xl*xl+yl*yl && rm*rm<xl*xl+yl*yl) cout<<2<<'\n';
    else if(rp*rp == xl*xl+yl*yl) cout<<1<<'\n';
    else if(rm*rm == xl*xl+yl*yl) cout<<1<<'\n';
    else if(rp*rp < xl*xl+yl*yl) cout<<0<<'\n';
    else if(rm*rm > xl*xl+yl*yl) cout<<0<<'\n';
    else if(xl == 0 && yl == 0 && r1!=r2) cout<<0<<'\n';
    else cout<<-1<<'\n';
  }
  return 0;
}
