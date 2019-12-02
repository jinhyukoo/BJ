#include<iostream>
using namespace std;
int main(void){
  int c, s[10001], d[10001];
  cin>>c;
  for(int i = 1 ;i<=c;i++)
    cin>>s[i];
  if(c==1){cout<<s[1]; return 0;}
  if(c==2){cout<<s[1]+s[2]; return 0;}
  d[1] = s[1]; d[2] = d[1] + s[2]; d[3] = max(max(s[1]+s[3],s[2]+s[3]),s[1]+s[2]);
  int r = d[3];
  for(int i = 4 ;i<=c ;i++){
    //해당 index까지 올 수 있는 경우의 수를 따져보면 다음과 같이 나온다.
    //1. 한 잔 마시고 2칸 뛰어 넘은 경우
    //2. 두 칸 뛰어넘어와서 2잔을 연속으로 마시는 경우
    //3. 두 잔 스킵 후 두칸 넘어와서 연속으로 2잔을 연속으로 마시는 경우
    //마지막 경우의 수가 생각하기 어려웠는데 예제로 6    1 2 0 0 3 4 를 넣어보면 이유를 쉽게 알 수 있다.
    d[i] = max(max(d[i-2]+s[i], d[i-3]+s[i-1]+s[i]), max(d[i-4]+s[i-1]+s[i],d[i-1]));
    r = max(r,d[i]);
  }
  cout<<r;
  return 0;
}
