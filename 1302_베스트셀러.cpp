#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(void)
{
  map<string, int> m;
  map<string, int> ::iterator iter;
  int N, answer = 0;
  string answer_s;
  cin>>N;
  for(int i = 0 ; i<N ; i++)
  {
    string s;
    cin>>s;
    if(!m.insert({s,1}).second)
    {
      m.find(s)->second++;
    }
  }
  for(iter = m.begin() ; iter != m.end() ; iter++)
  {
    if(iter->second > answer)
    {
      answer = iter->second;
      answer_s = iter->first;
    }
  }
  cout<<answer_s;
  return 0;
}
