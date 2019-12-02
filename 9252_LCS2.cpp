#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(void){
  stack<char> s;
  string s1, s2;
  int dp[102][102] = {0, }, check1[1001] = {0, }, check2[1001] = {0, }, colchk = 0;
  cin>>s1>>s2;
  for(int i = 0 ; i<s1.size() ; i++){
    for(int j = 0 ; j<s2.size() ; j++){
      if(s1[i] == s2[j]) dp[i+1][j+1] = dp[i][j] + 1; //같은 글자라면 dp를 왼쪽 대각선 위의 값에서 1추가시켜줌
      else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]); //그렇지 않으면 최근까지 계산한 dp중 가장 큰 값을 가져와서 저장
      dp[i+2][j+1] = dp[i+1][j+1]; //아래 행은 현재 행으로 채워준다. (그 이후에 위의 동작을 계속 반복하면 LCS 구하는 알고리즘 완성!)
    }
  }
  colchk = dp[s1.size()][s2.size()];
  for(int i = s1.size() ; i>0 ; i--){
    for(int j = s2.size() ; j>0 ; j--){
      if(dp[i][j] < colchk) break;
      else if(dp[i][j] > colchk) continue;
      else{
          if(check1[i-1] == 0 && check2[j-1] == 0 && s1[i-1] == s2[j-1]){ //한 열과 행에 하나의 check만 있어야함.
            s.push(s1[i-1]);
            check1[i-1] = 1;
            check2[j-1] = 1;
            colchk--;
          }
      }

    }
  }
  cout<<dp[s1.size()][s2.size()]<<'\n';
  while(!s.empty()){
    cout<<s.top();
    s.pop();
  }
  return 0;
}
