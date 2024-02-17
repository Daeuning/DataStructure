#include <iostream>
#include <vector>
using namespace std;
const int MAX = 987987987;
int N, M, R, A, B, L, T, max_item;
int D[102][102];
int nxt[102][102];
int item[102];
int vis[102];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> R;

  for (int i = 1; i <= N; i++)
  {
    cin >> item[i];
  }

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      if (i == j)
        D[i][j] = 0;
      else
        D[i][j] = MAX;
    }
  }

  while (R--)
  {
    cin >> A >> B >> L;
    D[A][B] = L;
    D[B][A] = L;
    nxt[A][B] = B;
    nxt[B][A] = A;
  }

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      for (int k = 1; k <= N; k++)
      {
        int tmp = D[j][i] + D[i][k];
        if (tmp < D[j][k])
        {
          D[j][k] = tmp;
          nxt[j][k] = nxt[j][i];
        }
      }
    }
  }

  for (int i = 1; i <= N; i++)
  {
    fill(vis, vis + N + 1, 0);
    int total_item = 0;

    for (int j = 1; j <= N; j++)
    {
      if (D[i][j] > M)
        continue;

      int st = i;
      while (st != j)
      {
        vis[st] = 1;
        st = nxt[st][j];
      }
      vis[j] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
      if (vis[i])
        total_item += item[i];
    }
    max_item = max(max_item, total_item);
  }

  cout << max_item;

  return 0;
}