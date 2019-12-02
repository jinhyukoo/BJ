#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<math.h>
#include<cstdio>
using namespace std;
int main(void){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int inputcount, wantcount, input[10001], want[10001];
  cin>>inputcount;
  for(int i = 0; i < inputcount; i++){
    cin>>input[i];
  }
  cin>>wantcount;
  for(int i = 0; i< wantcount; i++){
    cin>>want[i];
  }
  sort(input,input+inputcount);
  for(int i = 0; i<wantcount;i++){
    int a = binary_search(input, input+inputcount, want[i]);
    if(a == 0){
      cout<<"0\n";
    }
    else cout<<"1\n";
  }
  return 0;
}
