#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(void){
  string input, exp, result = "";
  cin>>input>>exp;
  char endOfExp = exp[exp.size() - 1];
  for(int i = 0 ; i<input.size() ; i++){
    result += input[i];
    if(input[i] == endOfExp){
      bool flag = 1;
      for(int j = 1 ; j<=exp.size() - 1 ; j++){
        if(result.size() - j < 0){
          flag = 0;
          break;
        }
        if(result[result.size() - 1 - j] != exp[exp.size() - 1 - j]){
          flag = 0;
          break;
        }
      }
      if(flag){
        for(int j = 0 ; j<exp.size() ; j++) result.pop_back();
      }
    }

  }
  result = result == "" ? "FRULA" : result;
  cout<<result;
  return 0;
}
