#include<iostream>
#include<string>
#include<bitset>
using namespace std;
string S = bitset<20>(0).to_string();
void add(int x){
  S[20-x] = '1';
}
void remove(int x){
  S[20-x] = '0';
}
void check(int x){
  cout<<S[20-x]<<'\n';
}
void toggle(int x){
  if(S[20-x] - '0') remove(x);
  else add(x);
}
void all(){
  S = bitset<20>(1048575).to_string();
}
void empty(){
  S = bitset<20>(0).to_string();
}
int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int M;
  cin>>M;
  for(int i = 0 ; i<M ; i++){
    string order;
    int num;
    cin>>order;
    if(order == "add"){
      cin>>num;
      add(num);
    }
    if(order == "remove"){
      cin>>num;
      remove(num);
    }
    if(order == "check"){
      cin>>num;
      check(num);
    }
    if(order == "toggle"){
      cin>>num;
      toggle(num);
    }
    if(order == "all"){
      all();
    }
    if(order == "empty"){
      empty();
    }
  }
  return 0;
}
