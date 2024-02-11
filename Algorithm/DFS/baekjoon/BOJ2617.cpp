#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int N, M, n_1, n_2, cnt, stone;
int vis[102];
int res[102];
int G[102][102];
stack<int> S;

int dfs(int num, int road)
{
  fill(vis, vis + 102, 0);
  stone = 0;

  vis[num] = 1;
  S.push(num);

  while (!S.empty())
  {
    int cur = S.top();
    S.pop();

    for (int nxt = 1; nxt <= N; nxt++)
    {
      if (vis[nxt] || G[cur][nxt] != road)
        continue;
      stone++;
      S.push(nxt);
      vis[nxt] = 1;
    }
  }

  return stone;
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  while (M--)
  {
    cin >> n_1 >> n_2;
    G[n_1][n_2] = 1;
    G[n_2][n_1] = 2;
  }

  for (int i = 1; i <= N; i++)
  {
    res[i] = max(dfs(i, 1), dfs(i, 2));
    if (res[i] >= ((N + 1) / 2))
      cnt++;
  }

  cout << cnt;

  return 0;
}