#include <iostream>
#include <algorithm>
using namespace std;
int D[1000002];
int rem[1000002];
int N;

int main(void)
{
  cin >> N;

  rem[1] = N;

  for (int i = 2; i <= N; i++)
  {
    D[i] = D[i - 1] + 1;
    rem[i] = i - 1;
    if (i % 2 == 0 && D[i] > D[i / 2] + 1)
    {
      D[i] = D[i / 2] + 1;
      rem[i] = i / 2;
    }
    if (i % 3 == 0 && D[i] > D[i / 3] + 1)
    {
      D[i] = D[i / 3] + 1;
      rem[i] = i / 3;
    }
  }

  cout << D[N] << '\n';

  while (1)
  {
    cout << N << ' ';
    if (N == 1)
      break;
    N = rem[N];
  }

  return 0;
}