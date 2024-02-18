#include <iostream>
#include <algorithm>
using namespace std;
int D[302][302];
int nxt[302][302];
int N, M, T, u, v, h, s, e;
const int INF = 0x3f3f3f3f;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> T;

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
    cin >> u >> v >> h;
    D[u][v] = h;
  }

  for (int k = 1; k <= N; k++)
  {
    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= N; j++)
      {
        D[i][j] = min(D[i][j], max(D[i][k], D[k][j]));
      }
    }
  }

  while (T--)
  {
    cin >> s >> e;

    if (D[s][e] == INF)
      cout << -1 << '\n';
    else
      cout << D[s][e] << '\n';
  }

  return 0;
}