#include<iostream>
using namespace std;

int main(void){
  int c;
  long long a[92];
  cin>>c;
  a[1] = 1;
  a[2] = 1;
  for(int i = 3 ; i<=c ;i++){
      a[i] = a[i-2] + a[i-1];
  }
  cout<<a[c];
  return 0;
}
