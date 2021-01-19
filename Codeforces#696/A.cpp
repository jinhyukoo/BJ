// 길이가 n인 2진수 a,b
// 정수 d를 주어진 규칙에 따라 만드려고 한다.

// a, b의 합을 구하는데 그냥 더함.
// 0110과 1101의 합은 1211임
// 연속된 숫자들은 하나의 숫자로 만든다.
// 1211은 121이 되고 022000은 020이 된다.

// a를 잃어버림
// d가 최대가 되게 a를 구해야함.

#include<iostream>
#include<string>
using namespace std;
int main(void){
  int t;
  cin>>t;
  while(t--){
    int n;
    string b, a = "1", d;
    cin>>n>>b;
    d = b[0] == '0' ? "1" : "2";
    for(int i = 1 ; i<b.size() ; i++){
      if(d[i-1] == '2'){
        if(b[i] == '1'){
          a += '0';
          d += '1';
        }
        else{
          a += '1';
          d += '1';
        }
      }
      else if(d[i-1] == '1'){
        if(b[i] == '1'){
          a += '1';
          d += '2';
        }
        else{
          a += '0';
          d += '0';
        }
      }
      else{
        if(b[i] == '1'){
          a += '1';
          d += '2';
        }
        else{
          a += '1';
          d += '1';
        }
      }
    }
    cout<<a<<'\n';
  }
  return 0;
}
