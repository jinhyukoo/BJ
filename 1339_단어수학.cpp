#include<iostream>
#include<string>
#include<queue>

using namespace std;

int main(void){
  int N, result = 0, alphabetCounter[26][8] = {0, }, weight[8] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1}, multiplier = 9;
  priority_queue< int, vector<int>, less<int> > pq;
  string inputs[10];
  cin>>N;
  for(int i = 0 ; i<N ; i++){
    cin>>inputs[i];
  }
  for(int i = 0 ; i<N ; i++){
    for(int j = 0 ; j<inputs[i].size() ; j++){
      int alphabet = inputs[i][j] - 'A';
      int digit = 8 - inputs[i].size() + j;
      alphabetCounter[alphabet][digit] += 1;
    }
  }

  for(int i = 0 ; i<26 ; i++){
    int tempSum = 0;
    for(int j = 0 ; j<8 ; j++){
      tempSum += alphabetCounter[i][j] * weight[j];
    }
    if(tempSum != 0) pq.push(tempSum);
  }

  while(!pq.empty()){
    result += multiplier * pq.top();
    pq.pop();
    multiplier--;
  }
  cout<<result;
  return 0;
}
