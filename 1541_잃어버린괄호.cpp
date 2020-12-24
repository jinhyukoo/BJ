#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(void){
  int result = 0, tempResult = 0, zeroChecker[51] = {0, };
  string input, number = "";
  vector<string> numbers;
  vector<char> oper;
  oper.push_back('+');
  cin>>input;

  for(int i = 0 ; i<input.size() ; i++){
    if(input[i] == '0'){
      while(input[i] != '0'){
        zeroChecker[i] = 1;
        i++;
      }
    }
  }

  for(int i = 0 ; i<input.size() ; i++){
    int now = input[i];
    if(zeroChecker[i]) continue;
    if(now == '-' || now == '+'){
      oper.push_back(now);
      numbers.push_back(number);
      number = "";
      continue;
    }
    number += input[i];
  }
  numbers.push_back(number);
  for(int i = 0 ; i<numbers.size() ; i++){
    if(oper[i] == '-'){
      if(tempResult){
        result -= tempResult;
        tempResult = 0;
        tempResult += stoi(numbers[i]);
      }
      else tempResult += stoi(numbers[i]);
    }
    else {
      if(!tempResult) result += stoi(numbers[i]);
      else tempResult += stoi(numbers[i]);
    }
  }
  if(tempResult) result -= tempResult;
  cout<<result;
  return 0;
}
