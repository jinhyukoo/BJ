#include<iostream>
using namespace std;

int main(void){
  int count, arr[11];
  cin>>count;
  arr[0] = 1; arr[1] = 2; arr[2] = 4;
  for(int i = 3 ;i<11;i++){
    arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
  }
  for(int i = 0 ;i<count ;i++){
    int input;
    cin>>input;
    cout<<arr[input-1]<<'\n';
  }
  return 0;
}
