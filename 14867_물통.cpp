#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

int A,B,C,D;

pair<int, int> fill_A(pair<int, int> now){
  pair<int, int> newBottle = {A, now.second};
  return newBottle;
}

pair<int, int> fill_B(pair<int, int> now){
  pair<int, int> newBottle = {now.first, B};
  return newBottle;
}

pair<int, int> empty_A(pair<int, int> now){
  pair<int, int> newBottle = {0, now.second};
  return newBottle;
}

pair<int, int> empty_B(pair<int, int> now){
  pair<int, int> newBottle = {now.first, 0};
  return newBottle;
}

pair<int, int> moveFromAtoB(pair<int, int> now){
  pair<int, int> newBottle = {max(0, now.first - (B-now.second)), min(B, now.first + now.second)};
  return newBottle;
}

pair<int, int> moveFromBtoA(pair<int, int> now){
  pair<int, int> newBottle = {min(A, now.first + now.second), max(0, now.second - (A-now.first))};
  return newBottle;
}

struct info{
  int a;
  int b;
  int count;
};

int main(void){
  cin>>A>>B>>C>>D;
  int visited[100001][4] = {0, };
  queue<struct info> q;
  q.push({0, 0, 0});
  visited[0][0] = visited[0][1] = 1;
  while(!q.empty()){
    struct info now = q.front();
    q.pop();
    if(now.a == C && now.b == D){
      cout<<now.count;
      return 0;
    }
    pair<int, int> fA = fill_A({now.a, now.b});
    pair<int, int> eA = empty_A({now.a, now.b});
    pair<int, int> mAB = moveFromAtoB({now.a, now.b});
    pair<int, int> fB = fill_B({now.a, now.b});
    pair<int, int> eB = empty_B({now.a, now.b});
    pair<int, int> mBA = moveFromBtoA({now.a, now.b});
    if(!visited[fA.second][2]){
      q.push({fA.first, fA.second, now.count + 1});
      visited[fA.second][2] = 1;
    }
    if(!visited[eA.second][0]){
      q.push({eA.first, eA.second, now.count + 1});
      visited[eA.second][0] = 1;
    }
    if(!visited[fB.first][3]){
      q.push({fB.first, fB.second, now.count + 1});
      visited[fB.first][3] = 1;
    }
    if(!visited[eB.first][1]){
      q.push({eB.first, eB.second, now.count + 1});
      visited[eB.first][1] = 1;
    }
    if(mAB.first == 0){
      if(!visited[mAB.second][0]){
        q.push({mAB.first, mAB.second, now.count + 1});
        visited[mAB.second][0] = 1;
      }
    }
    if(mAB.second == B){
      if(!visited[mAB.first][3]){
        q.push({mAB.first, mAB.second, now.count + 1});
        visited[mAB.first][3] = 1;
      }
    }
    if(mBA.first == A){
      if(!visited[mBA.second][2]){
        q.push({mBA.first, mBA.second, now.count + 1});
        visited[mBA.second][2] = 1;
      }
    }
    if(mBA.second == 0){
      if(!visited[mBA.first][1]){
        q.push({mBA.first, mBA.second, now.count + 1});
        visited[mBA.first][1] = 1;
      }
    }
  }
  cout<<-1;
  return 0;
}
