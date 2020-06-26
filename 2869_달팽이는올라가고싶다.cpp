#include<iostream>
using namespace std;



int main(void)
{
  int A, B, V, left = 0, right, result = 0;
  cin>>A>>B>>V;
  right = V + 1;
  while(left <= right)
  {
    int mid = (left + right)/2;
    if(mid * (A - B) > V - A){
      right = mid - 1;
      result = mid;
    }
    else if(mid * (A - B) < V - A){
      left = mid + 1;
    }
    else
    {
      result = mid;
      break;
    }
  }
  cout<<result + 1;
  return 0;
}
