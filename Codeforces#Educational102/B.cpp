// string a와 양의 정수 x의 곱셈을 정의해보자. abc * 2 = abcabc
// string a는 b로 나누어진다. b*x = a일 경우
// LCM(s,t)는 비어있지 않은 가장 짧은 스트링이다. s와 t 모두로 나누어지는
// s,t가 주어졌을 때 LCM을 찾아라. LCM이 없다면 -1을 출력해라.
// 1번 라인에 test case 주어짐
// 두 줄씩(s, t) 주어짐
#include<iostream>
#include<string>
using namespace std;
int main(void){
  int q;
  cin>>q;
  for(int i = 0 ; i<q ; i++){
    string s, t, news, newt;
    cin>>s>>t;
    news = s;
    newt = t;
    while(news.size() != newt.size()){
      if(news.size() < newt.size()) news += s;
      else newt += t;
    }
    if(news==newt) cout<<news<<'\n';
    else cout<<"-1"<<'\n';
  }
  return 0;
}
