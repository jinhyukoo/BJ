#include<iostream>
#include<string>
using namespace std;
int main(void)
{
  int N, answer = 0;
  cin>>N;
  for(int i = 1 ; i<=N ; i++)
  {
    string s = to_string(i);
    for(int j = 0 ; j<s.size() ; j++)
    {
      if(s[j] == '3' || s[j] == '6' || s[j] == '9') answer++;
    }
  }
  cout<<answer;
  return 0;
}
