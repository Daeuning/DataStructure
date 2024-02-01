#include <iostream>
#include <algorithm>
using namespace std;
long long D[102];
long long N, T;

int main(void)
{
  cin >> T;

  D[1] = 1;
  D[2] = 1;
  D[3] = 1;

  while (T--)
  {
    cin >> N;

    for (int i = 4; i <= N; i++)
    {
      D[i] = D[i - 3] + D[i - 2];
    }

    cout << D[N] << '\n';
  }

  return 0;
}