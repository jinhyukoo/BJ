#include<iostream>
#include<set>
using namespace std;
int main(void)
{
  int N, L;
  set<int> answer;
  set<int>::iterator iter;
  cin>>N>>L;
  for(int i = L ; i<=100 ; i++)
  {
    long long left = 0, right = N;
    if(i % 2)//홀수
    {
      while(left<=right)
      {
        long long mid = (left + right)/2;

        if(mid * i == N)
        {
          if(mid - i/2 < 0) break; //사소하지만 중요한 부분
          answer.insert(mid);
          for(int j = 1 ; j<=i/2 ; j++)
          {
            answer.insert(mid - j);
            answer.insert(mid + j);
          }

          for(iter = answer.begin() ; iter != answer.end() ; iter++) cout<<*iter<<" ";
          return 0;
        }
        else if(mid * i > N) right = mid - 1;
        else left = mid + 1;
      }
    }
    else //짝수
    {
      while(left<=right)
      {
        long long mid = (left + right)/2;

        if((i/2) * (mid * 2 + 1) == N)
        {
          if(mid - i/2 + 1 < 0) break;
          answer.insert(mid);
          for(int j = 1 ; j<i/2 ; j++) answer.insert(mid - j);
          for(int j = 1 ; j<=i/2 ; j++) answer.insert(mid + j);

          for(iter = answer.begin() ; iter != answer.end() ; iter++) cout<<*iter<<" ";
          return 0;
        }
        else if((i/2) * (mid * 2 + 1) > N) right = mid - 1;
        else left = mid + 1;
      }
    }
  }
  cout<<-1;
  return 0;
}
