#include<iostream>
#include<string>
using namespace std;
struct NODE{
  NODE* next;
  NODE* prev;
  char value;
};
struct NODE* head = new NODE;
struct NODE* cursor = head;
void move_left()
{
  if(cursor == head) return;
  cursor = cursor->prev;
}

void move_right()
{
  if(cursor->next == NULL) return;
  cursor = cursor->next;
}

void delete_NODE()
{
  struct NODE* temp = cursor;
  if(cursor == head) return;
  temp->prev->next = temp->next;
  if(temp->next != NULL)
    temp->next->prev = temp->prev;
  cursor = cursor->prev;
  delete(temp);
}

void insert_NODE(char input)
{
  struct NODE* temp = new NODE();
  temp->value = input;
  if(cursor == head)
  {
    temp->next = head->next;
    temp->prev = head;
    if(head->next != NULL)
    {
      head->next->prev = temp;
    }
    head->next = temp;
    cursor = temp;
  }
  else
  {
    temp->next = cursor->next;
    temp->prev = cursor;
    if(cursor->next != NULL)
    {
      cursor->next->prev = temp;
    }
    cursor->next = temp;
    cursor = temp;
  }
}
int main(void)
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  head->next = NULL;
  string s;
  int M;
  cin>>s>>M;
  for(int i = 0 ; i<s.size() ; i++) insert_NODE(s[i]);
  for(int i = 0 ; i<M ; i++)
  {
    char order;
    cin>>order;
    if(order == 'L') move_left();
    else if(order == 'D') move_right();
    else if(order == 'B') delete_NODE();
    else
    {
      char input;
      cin>>input;
      insert_NODE(input);
    }
  }
  struct NODE* temp = head->next;
  while(temp != NULL)
  {
    cout<<temp->value;
    temp = temp->next;
  }
  return 0;
}
