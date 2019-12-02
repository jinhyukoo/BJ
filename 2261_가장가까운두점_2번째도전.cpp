#include<iostream>
#include<algorithm>
#include<set>
#include<cmath>
using namespace std;
struct xy{
  int x, y;
  xy() {
  }
  xy(int x, int y) : x(x), y(y) {
  }
  bool operator < (const xy &v) const {
    if (y == v.y) {
        return x < v.x;
    } else {
        return y < v.y;
    }
  }
};
bool cmp(const xy &p1, const xy &p2){
    return p1.x < p2.x;
}

int dist(xy p1, xy p2){
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n, d, cnt = 0;
  set<struct xy> s;
  struct xy arr[100001];
  cin>>n;
  for(int i = 0 ;i<n;i++){
    cin>>arr[i].x>>arr[i].y;
  }

  sort(arr,arr+n,cmp);
  d = dist(arr[0], arr[1]);
  s.insert(arr[0]);
  s.insert(arr[1]);
  for(int i = 2 ;i<n;i++){
    while(cnt<i){
      int nx = arr[i].x - arr[cnt].x;
      if(nx*nx > d){
        s.erase(arr[cnt]);
        cnt++;
      }
      else{
        break;
      }
    }
    int nd = (int)sqrt((double)d)+1;
    auto lp = xy(-100001, arr[i].y - nd);
    auto up = xy(100001, arr[i].y + nd);
    auto lower = s.lower_bound(lp);
    auto upper = s.upper_bound(up);
    for(auto j = lower; j != upper;j++){
      int td = dist(arr[i],*j);
      if(td < d) d = td;
    }
    s.insert(arr[i]);
  }
  cout<<d;
  return 0;
}
