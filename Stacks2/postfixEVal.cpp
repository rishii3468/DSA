#include <iostream>
#include <stack>
using namespace std;




int main()
{
  string s = "79+4*8/3-";
  stack<int> val;

  for (int i = 0; i < s.length(); i++)
  {
    // check if s[i] is a digit (0-9)
    if (s[i] >= 48 && s[i] <= 57)
    {
      val.push(s[i] - 48);
    }
    else{
      int val2 = val.top();
      val.pop();
      int val1 = val.top();
      val.pop();
      if(s[i]=='+'){
        val.push(val1+val2);
      }
      else if(s[i]=='-'){
        val.push(val1-val2);
      }
      else if(s[i]=='/'){
        val.push(val1/val2);
      }
      else if(s[i]=='*'){
        val.push(val1*val2);
      }
    }
   
  }
  cout<<val.top();
  // the stack can still have some values
  return 0;
}
