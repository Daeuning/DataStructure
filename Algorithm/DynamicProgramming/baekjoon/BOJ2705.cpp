#include <iostream>
#include <algorithm>
using namespace std;
int T, N;
int D[1002];

int main(void)
{
  cin >> T;

  D[1] = 1;

  for (int i = 2; i <= 1002; i++)
  {
    if (N % 2 == 0)
    {
      for (int j = 0; j < i; j += 2)
      {
        D[i] += D[(i - j) / 2];
      }
      D[i]++;
    }
    else
    {
      for (int j = 1; j < i; j += 2)
      {
        D[i] += D[(i - j) / 2];
      }
      D[i]++;
    }
  }

  while (T--)
  {
    cin >> N;
    cout << D[N] << '\n';
  }

  return 0;
}