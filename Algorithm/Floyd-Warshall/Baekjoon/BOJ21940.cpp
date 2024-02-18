#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, A, B, T, K;
const int MAX = 0x3f3f3f3f;
int min_dis = MAX;
int our_city[202];
int D[202][202];
int city_dis[202];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      if (i == j)
        D[i][j] = 0;
      D[i][j] = MAX;
    }
  }

  while (M--)
  {
    cin >> A >> B >> T;
    D[A][B] = min(D[A][B], T);
  }

  cin >> K;

  for (int i = 1; i <= K; i++)
  {
    cin >> our_city[i];
  }

  for (int k = 1; k <= N; k++)
  {
    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= N; j++)
      {
        if (i == j)
        {
          D[i][j] = 0;
        }
        else
        {
          D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
        }
      }
    }
  }

  for (int i = 1; i <= N; i++)
  {
    int max_dis = 0;

    for (int j = 1; j <= K; j++)
    {
      int total_dis = 0;
      int st = our_city[j];

      if (D[st][i] == MAX || D[i][st] == MAX)
        break;

      total_dis += D[st][i];
      total_dis += D[i][st];

      max_dis = max(max_dis, total_dis);
    }

    city_dis[i] = max_dis;
    min_dis = min(min_dis, max_dis);
  }

  for (int i = 1; i <= N; i++)
  {
    if (city_dis[i] == min_dis)
      cout << i << ' ';
  }

  return 0;
}