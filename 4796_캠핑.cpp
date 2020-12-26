#include<iostream>
using namespace std;

int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  long long L=1, P=1, V=1;
  for(int i = 1 ; ; i++){
    cin>>L>>P>>V;
    if(L==0 && P==0 && V==0) break;
    cout<<"Case "<<i<<": "<<(V/P)*L + min(V%P, L)<<'\n';
  }
  return 0;
}
