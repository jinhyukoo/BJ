#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string addNumByString(string A, string B){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int sum = 0;
  string result = "";
  while(!A.empty() || !B.empty() || sum){
    if(!A.empty()){
      sum += A.back() - '0';
      A.pop_back();
    }
    if(!B.empty()){
      sum += B.back() - '0';
      B.pop_back();
    }
    result += (sum % 10) + '0';
    sum /= 10;
  }
  reverse(result.begin(), result.end());
  return result;
}

int main(void){
  int N, min=1000000000;
  cin>>N;
  vector<unsigned long long> dist(N-1), price(N);
  vector<string> sums(N-1);
  for(int i = 0 ; i<N-1 ; i++) cin>>dist[i];
  for(int i = 0 ; i<N ; i++) cin>>price[i];
  for(int i = 0 ; i<N-1 ; i++){
    min = min > price[i] ? price[i] : min;
    unsigned long long sum = min*dist[i];
    sums[i] = to_string(sum);
  }
  string now = sums[0];
  for(int i = 1 ; i<N-1 ; i++){
    now = addNumByString(now, sums[i]);
  }
  cout<<now;
  return 0;
}
