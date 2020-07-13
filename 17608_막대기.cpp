#include<iostream>
using namespace std;
int main(void)
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int arr[100001];
  int N, max = 0, answer = 0;
  cin>>N;
  for(int i = 0 ; i<N ; i++) cin>>arr[i];
  for(int i = N-1 ; i>=0 ; i--)
  {
    if(arr[i] > max)
    {
      answer++;
      max = arr[i];
    }
  }
  cout<<answer;
  return 0;
}
