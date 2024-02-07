#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string num;
int part1, part2;

int main(void)
{
  cin >> num;

  for (int i = 0; i < num.length(); i++)
  {
    if (i < num.length() / 2)
    {
      part1 += (num[i] - '0');
    }
    else
    {
      part2 += (num[i] - '0');
    }
  }

  if (part1 == part2)
  {
    cout << "LUCKY";
  }
  else
  {
    cout << "READY";
  }

  return 0;
}