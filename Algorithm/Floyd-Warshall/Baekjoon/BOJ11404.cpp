#include <iostream>
#include <algorithm>
using namespace std;
int N, M, A, B, C;
int D[102][102];
const int INF = 0x3f3f3f3f;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  cin >> M;

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      if (i == j)
        D[i][j] = 0;
      else
        D[i][j] = INF;
    }
  }

  while (M--)
  {
    cin >> A >> B >> C;
    D[A][B] = min(D[A][B], C);
  }

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      for (int k = 1; k <= N; k++)
      {
        D[j][k] = min(D[j][k], D[j][i] + D[i][k]);
      }
    }
  }

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      if (D[i][j] == INF)
        cout << '0' << ' ';
      else
        cout << D[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}