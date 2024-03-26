#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
const int MOD = 1000000007;
long long D[1004][1004];

int main(void)
{
  cin >> N >> M;

  D[0][0] = 1;

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= M; j++)
    {
      D[i][j] = (D[i][j - 1] + D[i - 1][j] + D[i - 1][j - 1]) % MOD;
    }
  }

  cout << D[N][M];

  return 0;
}