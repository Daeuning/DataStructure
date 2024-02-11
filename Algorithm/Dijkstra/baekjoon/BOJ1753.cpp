#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define X first
#define Y second
using namespace std;
int V, E, st, u, v, w;
const int INF = 1e9 + 10;
int d[20005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
vector<pair<int, int>> G[20005];

int main(void)
{
  fill(d, d + 20005, INF);
  cin >> V >> E;
  cin >> st;

  while (E--)
  {
    cin >> u >> v >> w;
    G[u].push_back({w, v});
  }

  d[st] = 0;
  PQ.push({d[st], st});

  while (!PQ.empty())
  {
    auto cur = PQ.top();
    PQ.pop();

    if (d[cur.Y] != cur.X)
      continue;
    for (auto nxt : G[cur.Y])
    {
      if (d[nxt.Y] <= d[cur.Y] + nxt.X)
        continue;
      d[nxt.Y] = d[cur.Y] + nxt.X;
      PQ.push({d[nxt.Y], nxt.Y});
    }
  }

  for (int i = 1; i <= V; i++)
  {
    if (d[i] == INF)
      cout << "INF\n";
    else
      cout << d[i] << '\n';
  }

  return 0;
}