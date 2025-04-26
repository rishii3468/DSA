#include <iostream>
#include <stack>
using namespace std;

int priority(char ch)
{
  if (ch == '+' || ch == '-')
    return 1;
  else return 2;
}

int solve(int val1, int val2, char ch)
{
  if(ch=='+') return val1+val2;
  if(ch=='-') return val1-val2;
  if(ch=='*') return val1*val2;
  if(ch=='/') return val1/val2;
  else{
    cout<<"invalid output";
    return -1;
  }
}

int main()
{
  string s = "7+9*4/8-3";
  stack<int> val;
  stack<char> op;

  for (int i = 0; i < s.length(); i++)
  {
    // check if s[i] is a digit (0-9)
    if (s[i] >= 48 && s[i] <= 57)
    {
      val.push(s[i] - 48);
    }
    else
    {
      if (op.size() == 0 || priority(s[i]) > priority(op.top()))
        op.push(s[i]);
      else
      {
        
        while (op.size()>0 && priority(op.top()) >= priority(s[i]))
        {
          int val2 = val.top();
          val.pop();
          int val1 = val.top();
          val.pop();
          char ch = op.top();
          op.pop();
          int ans = solve(val1, val2, ch);

          val.push(ans);
        }
        op.push(s[i]);
      }
    }
  }
  // the stack can still have some values

  while (op.size()>0)
  {
    int val2 = val.top();
    val.pop();
    int val1 = val.top();
    val.pop();
    char ch = op.top();
    op.pop();
    int ans = solve(val1, val2, ch);

    val.push(ans);
  }

  cout<<val.top();
  cout<<endl<<7+9*4/8-3;
  return 0;
}
