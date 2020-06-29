#include<iostream>
#include<cmath>
#define D 1000000007
using namespace std;
long long power(long long x, long long y) {
    long long ret = 1;
    while (y > 0) {
        if (y % 2) {
            ret *= x;
            ret %= D;
        }
        x *= x;
        x %= D;
        y /= 2;
    }
    return ret;
}
int main(void)
{
  long long N, K, fac[40001] = {0, 1, }, arr[40001], r;
  cin>>N>>K;
  for(int i = 2 ; i<=40000 ; i++)
    fac[i] = (fac[i-1] * i) % D;
  arr[40000] = power(fac[40000], D-2);
  for(int i = 39999 ; i>0 ; i--)
    arr[i] = (arr[i + 1] * (i+1)) % D;
  if(N == K || K == 0) cout<<1;
  else
  {
    r = (fac[N] * arr[N-K]) % D;
    r = (r*arr[K]) % D;
    cout<<r;
  }
  return 0;
}
