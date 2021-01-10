#include<iostream>
#include<deque>
#include<string>
using namespace std;
int main(void){
  int N, K;
  string input;
  deque<char> dq;
  cin>>N>>K>>input;
  for(int i = 0 ; i<input.size() ; i++){
    char now = input[i];
    while(K && !dq.empty() && dq.back() < now){
      dq.pop_back();
      K--;
    }
    dq.push_back(now);
  }
  for(int i = 0 ; i<dq.size() - K ; i++) cout<<dq[i];
  return 0;
}
