#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(void){
  int N;
  double result = 0;
  cin>>N;
  vector<double> x(N), y(N);
  for(int i = 0 ; i<N ; i++){
    cin>>x[i]>>y[i];
  }
  for(int i = 0 ; i<N ; i++){
    if(i == N-1) result += (x[i] * y[0]) - (x[0] * y[i]);
    result += (x[i] * y[i+1]) - (x[i+1] * y[i]);
  }
  cout<<fixed;
  cout.precision(1);
  cout<<abs(round(result/2 * 10)/10);
  return 0;
}
