#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
int D[1002];
int pre[1002];
int res[1002];
int N, M, u, v, w, st, ed, cnt, idx, dis;
const int INF = 1e9 + 10;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
vector<pair<int, int>> G[1002];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(D, D + 1002, INF);
  cin >> N;
  cin >> M;

  while (M--)
  {
    cin >> u >> v >> w;
    G[u].push_back({w, v});
  }

  cin >> st >> ed;

  D[st] = 0;
  PQ.push({D[st], st});

  while (!PQ.empty())
  {
    auto cur = PQ.top();
    PQ.pop();

    if (D[cur.Y] != cur.X)
      continue;

    for (auto nxt : G[cur.Y])
    {
      if (D[nxt.Y] <= D[cur.Y] + nxt.X)
        continue;
      D[nxt.Y] = D[cur.Y] + nxt.X;
      pre[nxt.Y] = cur.Y;
      PQ.push({D[nxt.Y], nxt.Y});
    }
  }

  idx = ed;

  while (idx != st)
  {
    cnt++;
    res[cnt] = idx;
    idx = pre[idx];
  }

  cout << D[ed] << '\n';
  cout << cnt + 1 << '\n';
  cout << st << ' ';
  for (int i = cnt; i >= 1; i--)
  {
    cout << res[i] << ' ';
  }

  return 0;
}