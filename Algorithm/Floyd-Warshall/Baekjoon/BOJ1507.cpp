#include <iostream>
#include <algorithm>
using namespace std;
int N, M, res;
int D[22][22];
int road[22][22];

int main(void)
{
  cin >> N;

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      cin >> D[i][j];
    }
  }

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      bool isroad = 1;

      for (int k = 1; k <= N; k++)
      {
        if (k == i || k == j)
          continue;
        int tmp = D[i][k] + D[k][j];
        if (tmp < D[i][j])
        {
          cout << -1;
          return 0;
        }
        if (D[i][j] == tmp)
          isroad = 0;
      }

      if (isroad)
      {
        road[i][j] = 1;
        road[j][i] = 1;
      }
    }
  }

  for (int i = 1; i <= N; i++)
  {
    for (int j = i + 1; j <= N; j++)
    {
      if (road[i][j])
        res += D[i][j];
    }
  }

  cout << res;

  return 0;
}