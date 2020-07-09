#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
bool c[10] = {0, };
int k;
string a1 = "", a2 = "";
void input()
{
  cin>>k;
  for(int i = 0 ; i<k ; i++)
  {
    char t;
    cin>>t;
    if(t == '<') c[i] = 1;
    else c[i] = 0;
  }
}

bool check(vector<int> v)
{
  bool first = 0;
  for(int i = 0 ; i<v.size() - 1 ; i++)
  {
    bool a = v[i]>v[i+1];
    if(c[i] && a)
    {
      return 1;
    }
    if(!c[i] && !a)
    {
      return 1;
    }
  }
  return 0;
}

void check_next()
{
  bool flag = 0;
  for(int i = 0 ; i<10-k ; i++)
  {
    vector<int> v(k+1);
    for(int j = i ; j<=i+k ; j++)
    {
      v[j-i] = j;
    }
    do{
      if(!check(v))
      {
        for(int i = 0 ; i<v.size() ; i++) a1 += (v[i] + '0');
        flag = 1;
        break;
      }
    }while(next_permutation(v.begin(), v.end()));
    if(flag) break;
  }
}

void check_prev()
{
  bool flag = 0;
  for(int i = 0 ; i<10-k ; i++)
  {
    vector<int> v(k+1);
    for(int j = 9 - i ; j>=9-(i+k) ; j--)
    {
      v[9 - (j-i)] = j;
    }
    do{
      if(!check(v))
      {
        for(int i = 0 ; i<v.size() ; i++) a2 += (v[i] + '0');
        flag = 1;
        break;
      }
    }while(prev_permutation(v.begin(), v.end()));
    if(flag) break;
  }
}
int main(void)
{
  input();
  check_next();
  check_prev();
  cout<<a2<<"\n"<<a1;
  return 0;
}
