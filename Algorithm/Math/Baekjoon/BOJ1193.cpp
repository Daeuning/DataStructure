#include <iostream>
using namespace std;
int X, numer, deno;

int main(void)
{
  cin >> X;

  int num = X;
  int line = 1;

  while (1)
  {
    if (num <= line)
      break;
    else
      num -= line;
    line++;
  }

  if (line % 2 == 0)
  {
    numer = num;
    deno = line + 1 - num;
  }
  else
  {
    numer = line + 1 - num;
    deno = num;
  }

  cout << numer << '/' << deno;

  return 0;
}