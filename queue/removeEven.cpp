#include <iostream>
#include <queue>
using namespace std;

void display(queue<int> q)
{
  for (int i = 0; i < q.size(); i++)
  {
    int x = q.front();
    q.pop();
    cout << x << " ";
    q.push(x);
  }
  cout<<endl;
}

int main()
{
  queue<int> q;
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);
  display(q);
  int x = q.size();
  for (int i = 0; i <x; i++)
  {
    int x = q.front();
    q.pop();
    if (i % 2 != 0)
    {
      q.push(x);
    }
  }
  display(q);
}