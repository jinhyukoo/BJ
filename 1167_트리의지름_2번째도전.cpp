/*
첫번째 방법으로 풀고 실패한 후 질문 검색을 통해 찾은 두 번째 방법
트리 내의 임의의 아무 점이나 선택한 후 가장 먼 점을 찾는다. 그리고 그 점에서 가장 먼 점을 찾으면 그게 트리의 지름이 된다.
DFS를 통해 가장 먼 점을 찾은 후에 동일한 방법으로 다시 가장 먼 점을 찾는다.
그 후 구해진 두 점 사이의 거리를 구해주면 정답
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct NODE{
  int num;
  int weight;
};
int main(void){
  int V;
  vector<struct NODE> arr[100001];
  cin>>V;
  for(int i = 0 ;i<V;i++){
    int v, t1, t2;
    cin>>v;
    while(1){
      cin>>t1;
      if(t1 == -1) break;
      cin>>t2;
      arr[v].push_back({t1,t2});
    }
  }
  stack<int> s;
  stack<int> l;
  vector<struct NODE> data;
  int chk[100001] = {0, };
  s.push(1);
  l.push(0);
  chk[1] = 1;
  while(!s.empty()){
    int t = s.top(), tl = l.top(), flag = 0;
    s.pop();
    l.pop();
    for(int i = 0 ;i<arr[t].size();i++){
      if(chk[arr[t][i].num] == 0){
        s.push(arr[t][i].num);
        l.push(tl+arr[t][i].weight);
        chk[arr[t][i].num] = 1;
        flag = 1;
      }
    }
    if(flag == 0){
      data.push_back({t,tl});
    }
  }
  int maxvalue = 0, maxindex = 0;
  for(int i = 0 ; i<data.size();i++){
    if(data[i].weight > maxvalue){
      maxvalue = data[i].weight;
      maxindex = data[i].num;
    }
  }
  vector<struct NODE> data2;
  for(int i = 1 ; i<=V;i++) chk[i] = 0;
  s.push(maxindex);
  l.push(0);
  chk[maxindex] = 1;
  while(!s.empty()){
    int t = s.top(), tl = l.top(), flag = 0;
    s.pop();
    l.pop();
    for(int i = 0 ;i<arr[t].size();i++){
      if(chk[arr[t][i].num] == 0){
        s.push(arr[t][i].num);
        l.push(tl+arr[t][i].weight);
        chk[arr[t][i].num] = 1;
        flag = 1;
      }
    }
    if(flag == 0){
      data2.push_back({t,tl});
    }
  }
  int maxvalue2 = 0, maxindex2 = 0;
  for(int i = 0 ; i<data2.size();i++){
    if(data2[i].weight > maxvalue2){
      maxvalue2 = data2[i].weight;
      maxindex2 = data2[i].num;
    }
  }
  int r = 0;
  for(int i = 1 ; i<=V;i++) chk[i] = 0;
  s.push(maxindex);
  l.push(0);
  chk[maxindex] = 1;
  while(!s.empty()){
    int t = s.top(), tl = l.top(), flag = 1;
    s.pop();
    l.pop();
    for(int i = 0 ;i<arr[t].size();i++){
      if(chk[arr[t][i].num] == 0){
        if(arr[t][i].num == maxindex2){
          r = tl+arr[t][i].weight;
          flag = 0;
          break;
        }
        s.push(arr[t][i].num);
        l.push(tl+arr[t][i].weight);
        chk[arr[t][i].num] = 1;
      }
    }
    if(flag == 0){
      break;
    }
  }
  cout<<r;
  return 0;
}
