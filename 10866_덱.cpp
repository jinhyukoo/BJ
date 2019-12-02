#include<iostream>
// #include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
// #include<stack>
#include<deque>
#include<cstdio>
using namespace std;

int main(void){
  deque<int> d;
  int count;
  string order;
  scanf("%d",&count);
  for(int i = 0 ;i<count;i++){
    cin>>order;
    if(order == "push_front"){
      int input;
      scanf("%d",&input);
      d.push_front(input);
    }
    else if(order == "push_back"){
      int input;
      scanf("%d",&input);
      d.push_back(input);
    }
    else if(order == "pop_front"){
      if(d.empty()==0){
        printf("%d\n",d.front());
        d.pop_front();
      }
      else{
        printf("-1\n");
      }
    }

    else if(order == "pop_back"){
      if(d.empty()==0){
        printf("%d\n",d.back());
        d.pop_back();
      }
      else{
        printf("-1\n");
      }
    }

    else if(order == "size"){
      printf("%d\n",d.size());
    }
    else if(order == "empty")
      printf("%d\n",d.empty());
    else if(order == "front"){
      if(d.empty()==0){
        printf("%d\n",d.front());
      }
      else{
        printf("-1\n");
      }
    }
    else if(order == "back"){
      if(d.empty()==0){
        printf("%d\n",d.back());
      }
      else{
        printf("-1\n");
      }
    }
  }
  return 0;
}
