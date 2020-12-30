#include<iostream>
#include<string>
using namespace std;

int main(void){
  string A, B;
  cin>>A>>B;
  //A&B
  for(int i = 0 ; i<A.size() ; i++){
    int now = A[i] == '1' && B[i] == '1' ? 1 : 0;
    cout<<now;
  }
  cout<<'\n';
  //A|B
  for(int i = 0 ; i<A.size() ; i++){
    int now = A[i] == '1' || B[i] == '1' ? 1 : 0;
    cout<<now;
  }
  cout<<'\n';
  //A^B
  for(int i = 0 ; i<A.size() ; i++){
    int now = (A[i] == '1' && B[i] == '1') || (A[i] == '0' && B[i] == '0') ? 0 : 1;
    cout<<now;
  }
  cout<<'\n';
  //~A
  for(int i = 0 ; i<A.size() ; i++){
    int now = A[i] == '1' ? 0 : 1;
    cout<<now;
  }
  cout<<'\n';
  //~B
  for(int i = 0 ; i<A.size() ; i++){
    int now = B[i] == '1' ? 0 : 1;
    cout<<now;
  }
  return 0;
}
