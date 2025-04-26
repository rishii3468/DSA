#include <iostream>
#include <stack>
#include<string>
using namespace std;

int priority(char ch)
{
  if (ch == '+' || ch == '-')
    return 1;
  else
    return 2;
}

int main()
{
  string s = "(7+9)*4/8-3";
  stack<string> val;
  stack<char> op;
  cout<<s<<endl;
  for (int i = 0; i < s.length(); i++)
  {
    
    // check if s[i] is a digit (0-9)
    if (s[i] >= 48 && s[i] <= 57)
    {
      val.push(to_string(s[i]-48));
    }
    else
    {
      if (op.size() == 0)
        op.push(s[i]);
      else if (s[i] == '(')
        op.push(s[i]);
      else if (op.top() == '(')
        op.push(s[i]);

      else if (s[i] == ')')
      {
        while (op.top() != '(')
        {
          string val2 = val.top();
          val.pop();
          string val1 = val.top();
          val.pop();
          char ch = op.top();
          op.pop();
          string ans = val1 + val2+ ch;
          val.push(ans);
        }
        op.pop();
      }
      else if (priority(s[i]) > priority(op.top()))
        op.push(s[i]);
      else
      {

        while (op.size() > 0 && priority(op.top()) >= priority(s[i]))
        {
          string val2 = val.top();
          val.pop();
          string val1 = val.top();
          val.pop();
          char ch = op.top();
          op.pop();
          string ans = val1 + val2+ ch;

          val.push(ans);
        }
        op.push(s[i]);
      }
    }
  }
  // the stack can still have some values

  while (op.size() > 0)
  {
    string val2 = val.top();
    val.pop();
    string val1 = val.top();
    val.pop();
    char ch = op.top();
    op.pop();
    string ans = val1 + val2+ ch;

    val.push(ans);
  }
  cout<<val.top();
  return 0;
}
