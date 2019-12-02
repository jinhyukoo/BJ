#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<cstdio>
#include<string.h>
using namespace std;
void doBFS(int arr[20001], int start, int find);
int main(void){
  int arr[20001];
  // memset(arr, 100000, sizeof(arr));
  fill_n(arr, 20001, 200001);
  int start, find;
  // printf("%d",arr[10000]);
  scanf("%d %d",&start, &find);

  doBFS(arr,start,find);
  // printf("%d",arr[0]);
  printf("%d",arr[find]-1);

  return 0;
}

void doBFS(int arr[20001], int start, int find){
  queue<int> q;
  arr[start] = 1;
  q.push(start);
  while(q.empty()==0){
    int n_value = q.front();
    // printf("%d\n",n_value);
    q.pop();
    if(arr[n_value]+1<arr[n_value+1] && n_value+1<=10000){
      arr[n_value+1] = arr[n_value]+1;
      q.push(n_value+1);
      // printf("%dth : %d\n",n_value+1,arr[n_value+1]);
    }
    if(arr[n_value]+1<arr[n_value-1] && n_value-1>=0){
      arr[n_value-1] = arr[n_value]+1;
      q.push(n_value-1);
      // printf("%dth : %d\n",n_value-1,arr[n_value-1]);
    }
    if(arr[n_value]+1<arr[n_value*2] && n_value*2<=10000){
      arr[n_value*2] = arr[n_value]+1;
      q.push(n_value*2);
      // printf("%dth : %d\n",n_value*2,arr[n_value*2]);
    }
  }
}
