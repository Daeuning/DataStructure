#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int N, B, quo, rest;
char res;
vector<char> num;
stack<char> S;

int main(void)
{
  cin >> N >> B;

  quo = N;

  while (quo)
  {
    rest = quo % B;

    if (rest >= 0 && rest <= 9)
      res = rest + '0';
    if (rest >= 10 && rest <= 35)
      res = rest - 10 + 'A';

    S.push(res);

    quo /= B;
  }

  while (!S.empty())
  {
    num.push_back(S.top());
    S.pop();
  }

  for (int i = 0; i < num.size(); i++)
  {
    cout << num[i];
  }

  return 0;
}