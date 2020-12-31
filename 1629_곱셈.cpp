#include<iostream>
using namespace std;
int power(int n, int k, int d){
  if(k == 0) return 1;

  int temp = power(n,k/2,d);
  int result = (1LL * temp * temp) % d;

	if(k%2) result = 1LL * result * n % d;
  return result;
}
int main(void){
  int a, b, c;
  cin>>a>>b>>c;
  cout<<power(a,b,c);
  return 0;
}
