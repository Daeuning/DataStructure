#include <iostream>
#include <algorithm>
using namespace std;
int V, E, u, v, w;
const int INF = 0x3f3f3f3f;
int D[402][402];
bool ispossible = 0;
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> V >> E;

  for (int i = 1; i <= V; i++)
  {
    for (int j = 1; j <= V; j++)
    {
      if (i == j)
        D[i][j] == 0;
      else
        D[i][j] = INF;
    }
  }

  while (E--)
  {
    cin >> u >> v >> w;
    D[u][v] = w;
  }

  for (int k = 1; k <= V; k++)
  {
    for (int i = 1; i <= V; i++)
    {
      for (int j = 1; j <= V; j++)
      {
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
      }
    }
  }

  int min_dis = INF;

  for (int i = 1; i <= V; i++)
  {
    for (int j = 1; j <= V; j++)
    {
      if (i == j)
        continue;
      if (D[j][i] == INF || D[i][j] == INF)
      {
        continue;
      }
      else
      {
        min_dis = min(min_dis, D[j][i] + D[i][j]);
        ispossible = 1;
      }
    }
  }

  if (ispossible)
    cout << min_dis;
  else
    cout << -1;
}