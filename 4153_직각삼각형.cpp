#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
  while(1)
  {
    int arr[3];
    cin>>arr[0]>>arr[1]>>arr[2];
    if(!arr[0] && !arr[1] && !arr[2]) break;
    sort(arr, arr+3);
    if(arr[2]*arr[2] == arr[0]*arr[0] + arr[1]*arr[1]) cout<<"right\n";
    else cout<<"wrong\n";
  }
  return 0;
}
