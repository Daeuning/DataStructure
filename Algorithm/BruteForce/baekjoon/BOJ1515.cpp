#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int idx;
string str;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str;

  for (int i = 1; i < 30000; i++)
  {
    string comp = to_string(i);

    for (int j = 0; j < comp.size(); j++)
    {
      if (comp[j] == str[idx])
      {
        idx++;
      }
    }

    if (idx == str.size())
    {
      cout << i;
      break;
    }
  }
  return 0;
}