#include<iostream>
using namespace std;
int cmp(int a, int b){if(a>b) return b; else return a;}
struct rgb{
  int r;
  int g;
  int b;
};
int main(void){
  int count, r[1003],g[1003],b[1003];
  struct rgb c[1003];
  cin>>count;
  for(int i = 1 ;i<=count;i++){
      cin>>c[i].r>>c[i].g>>c[i].b;
  }
  r[1] = c[1].r; g[1] = c[1].g; b[1] = c[1].b;
  r[2] = min(g[1],b[1]) + c[2].r; g[2] = min(r[1],b[1]) + c[2].g; b[2] = min(g[1],r[1]) + c[2].b;
  for(int i = 3 ; i<=count ;i++){
    r[i] = min(b[i-1], g[i-1]) + c[i].r;
    g[i] = min(r[i-1], b[i-1]) + c[i].g; //값을 갱신 할 때 들어 올 수 있는 양쪽의 값을 모두 고려해 주므로 그 전까지 가서 확인할 필요가 없다...ㅠ
    b[i] = min(r[i-1], g[i-1]) + c[i].b;
  }
  int result = min(r[count],g[count]);
  result = min(result, b[count]);
  cout<<result;
  return 0;
}
