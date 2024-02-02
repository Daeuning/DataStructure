#include <iostream>
#include <algorithm>
using namespace std;
int self[10002];
int check[10002];
int res;

int main(void)
{
  for (int i = 1; i <= 10000; i++)
  {
    self[i] = i;
    int num = i;
    while (num)
    {
      res = num % 10;
      self[i] += res;
      num = (num - res) / 10;
    }
    check[self[i]] = 1;
  }

  for (int i = 1; i <= 10000; i++)
  {
    if (check[i] == 0)
      cout << i << '\n';
  }

  return 0;
}