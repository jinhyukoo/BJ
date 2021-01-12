#include<iostream>
#include<vector>
using namespace std;
int main(void){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int N, H, min = 300000, count = 0;
  cin>>N>>H;
  vector<int> bottom(H+1, 0), top(H+1, 0);
  for(int i = 0 ; i<N ; i++){
    int input;
    cin>>input;
    if(i % 2 == 0) {
      bottom[input]++;
    }
    else {
      top[H+1-input]++;
    }
  }
  for(int i = 1 ; i<=H ; i++){
    top[i] += top[i-1];
    bottom[H-i] += bottom[H+1-i];
  }
  for(int i = 1 ; i<=H ; i++){
    if(min > top[i] + bottom[i]){
      min = top[i] + bottom[i];
      count = 1;
    }
    else if(min == top[i] + bottom[i]) count++;
  }
  cout<<min<<" "<<count;
  return 0;
}
