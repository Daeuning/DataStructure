#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int N, cnt, one, ten, hun;

int main(void)
{
  cin >> N;

  for (int i = 1; i <= N; i++)
  {
    if (i <= 99)
    {
      cnt++;
    }
    else if (i > 99 && i <= 999)
    {
      int num = i;
      one = num % 10;
      ten = num / 10 % 10;
      hun = num / 10 / 10 % 10;

      if (ten - one == hun - ten)
        cnt++;
    }
  }

  cout << cnt;

  return 0;
}