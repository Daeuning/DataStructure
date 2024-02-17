#include <iostream>
#include <vector>
using namespace std;
int N, M, A, B, C;
int D[102][102];
int nxt[102][102];
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
    nxt[A][B] = B;
  }

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      for (int k = 1; k <= N; k++)
      {
        if (D[j][k] > D[j][i] + D[i][k])
        {
          D[j][k] = D[j][i] + D[i][k];
          nxt[j][k] = nxt[j][i];
        }
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

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      if (nxt[i][j] == 0)
      {
        cout << '0' << '\n';
        continue;
      }
      vector<int> path;
      int st = i;
      while (st != j)
      {
        path.push_back(st);
        st = nxt[st][j];
      }
      path.push_back(j);
      cout << path.size() << ' ';
      for (int i = 0; i < path.size(); i++)
      {
        cout << path[i] << ' ';
      }
      cout << '\n';
    }
  }

  return 0;
}