#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> v[1001];
void doDFS(int chk[1001]){
  stack<int> s;
  s.push(1);
  chk[1] = 1;
  while(!s.empty()){
    int temp = s.top();
    s.pop();
    for(int j = 0 ;j<v[temp].size();j++){
      if(chk[v[temp][j]] == 0){
        chk[v[temp][j]] = 1;
        s.push(v[temp][j]);
      }
    }
  }
}

int main(void){
  ios_base :: sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin>>t;
  for(int i = 0 ;i<t;i++){
    int N,M,t1,t2,f1=0,chk1[1001] = {0, };
    cin>>N>>M;
    for(int j = 0 ;j<M;j++){
      cin>>t1>>t2;
      v[t1].push_back(t2);
      v[t2].push_back(t1);
    }
    if(M != N-1){
      cout<<"graph\n";
    }
    else{
      doDFS(chk1);
      for(int j = 1 ;j<=N; j++){
        if(chk1[j] == 0) f1 = 1;
      }
      if(f1 == 1){
        cout<<"graph\n";
        continue;
      }
      cout<<"tree\n";
    }
  }
  return 0;
}
