#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
int N, cnt, num;
string str;
stack<int> S;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str;

  for (int i = 0; i < str.length() - 1; i++)
  {
    if (str[i] == '(' && str[i + 1] == '(')
      S.push(1);
    else if (str[i] == ')' && str[i + 1] == ')')
      S.push(0);
  }

  while (!S.empty())
  {
    if (S.top() == 0)
    {
      num++;
      S.pop();
    }
    else
    {
      cnt += num;
      S.pop();
    }
  }

  cout << cnt;

  return 0;
}