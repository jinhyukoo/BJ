#include<iostream>
#include<deque>
using namespace std;
int main(void)
{
  deque<int> dq;
  int N;
  cin>>N;
  for(int i = 0 ; i<N; i++)
    dq.push_back(i+1);
  while(dq.size() > 1)
  {
    dq.pop_front();
    int temp = dq.front();
    dq.push_back(temp);
    dq.pop_front();
  }
  cout<<dq[0];
  return 0;
}
