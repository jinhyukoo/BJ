#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(void){
  //num은 순서대로 들어오는 숫자를 세어주고 arrptr은 만들어야 할 배열의 순서를 알려준다.
  int n,num=1,arrptr=0,arr[100001] = {0, };
  string r = ""; //정답을 저장할 string 변수
  stack<int> stk;
  cin>>n;
  for(int i = 0 ;i<n;i++) cin>>arr[i];
  //완성해야 할 배열의 끝까지 가야 하므로 조건은 arrptr이 n보다 작을때로 해준다.
  while(arrptr<n){
    //만약 완성해야 할 배열의 숫자보다 작은 수일 경우 stack에 push한다.
    if(arr[arrptr]>num){
      stk.push(num);
      num++;
      r += "+\n";
    }
    //완성해야 할 배열의 숫자와 같을 경우 stack에 바로 넣었다 빼면 된다.
    else if(arr[arrptr] == num){
      num++;
      arrptr++;
      r += "+\n-\n";
    }
    //위의 경우들 외에는 stack의 top이 완성해야 할 배열과 반드시 일치해야 한다. 따라서 다음과 같이 처리한다.
    else if(stk.top() == arr[arrptr]){
      stk.pop();
      r += "-\n";
      arrptr++;
    }
    //위의 경우들을 벗어나는 경우 배열을 완성시킬 수 없게 된다. 따라서 break 해준다.
    else break;
  }
  //배열을 모두 완성할 경우 r의 길이가 n*4와 일치하게 되므로 이 경우엔 정답을 출력하고 그렇지 않으면 NO를 출력한다.
  if(r.length() == n*4) cout<<r;
  else cout<<"NO";
  return 0;
}
