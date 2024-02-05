#include <iostream>
#include <algorithm>
#define mod 1000000000
using namespace std;
long long D[10002][12];
int N;
long long res;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 1; i <= 9; i++)
  {
    D[1][i] = 1;
  }

  for (int i = 2; i <= N; i++)
  {
    for (int j = 0; j <= 9; j++)
    {
      if (j == 0)
        D[i][j] = D[i - 1][1] % mod;
      if (j > 0 && j < 9)
        D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) % mod;
      if (j == 9)
        D[i][j] = D[i - 1][8] % mod;
    }
  }

  for (int i = 0; i <= 9; i++)
  {
    res += D[N][i];
  }

  cout << res % mod;

  return 0;
}