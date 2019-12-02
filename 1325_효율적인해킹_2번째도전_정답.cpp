//vector<vector<int> >를 쓰면 시간초과가 뜨고 vector<int> v[10002]이걸 쓰면 잘 맞음... 새로운 깨달음...
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
struct vtx{
  int idx;
  int value;
};
int maxvalue;
vector<struct vtx> result;
// void doBFS(int start, vector<vector<int> > v, int max);
void doBFS(int start, vector<int> v[10002], int max);
int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  maxvalue = 0;
  // vector<vector<int> > v(10002);
  vector<int> v[10002];
  int n, m;
  queue<int> q;
  int check[10002] = {0, };
  // scanf("%d %d",&n,&m);
  cin>>n>>m;
  for(int i = 0 ;i<m ; i++){
    int from, to;
    // scanf("%d %d",&from, &to);
    cin>>from>>to;
    v[to].push_back(from);
  }
  for(int i = 1 ;i<=n;i++){
    doBFS(i, v, maxvalue);
  }
  for(int i = 0 ;i < result.size();i++){
    if(result[i].value == maxvalue)
      cout<<result[i].idx<<" ";
      // printf("%d ",result[i].idx);
  }
  return 0;
}
// void doBFS(int start, vector<vector<int> > v, int max){
void doBFS(int start, vector<int> v[10002], int max){
  queue<int> q;
  int check[10002] = {0, };
  int count = 0;
  q.push(start);
  while(!q.empty()){
    int temp = q.front();
    check[temp] = 1;
    q.pop();
    for(int i = 0 ;i<v[temp].size();i++){
      if(check[v[temp][i]]==0){
        q.push(v[temp][i]);
        check[v[temp][i]] = 1;
      }
    }
    count++;
  }
  if(count>maxvalue)
    maxvalue=count;
  struct vtx temp2;
  temp2.idx = start;
  temp2.value = count;
  result.push_back(temp2);
}
