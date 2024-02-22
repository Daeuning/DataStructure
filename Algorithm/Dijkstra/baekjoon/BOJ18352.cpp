#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define X first
#define Y second
using namespace std;
int N, M, K, x, a, b;
int D[300002];
const int INF = 1e9 + 10;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
vector<pair<int, int>> G[300002];
vector<int> res;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K >> x;

  fill(D, D + N + 1, INF);

  for (int i = 0; i < M; i++)
  {
    cin >> a >> b;
    G[a].push_back({1, b});
  }

  D[x] = 0;
  PQ.push({D[x], x});

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
      PQ.push({D[nxt.Y], nxt.Y});
    }
  }

  for (int i = 1; i <= N; i++)
  {
    if (D[i] == K)
      res.push_back(i);
  }

  if (res.empty())
  {
    cout << -1;
  }
  else
  {
    for (int i = 0; i < res.size(); i++)
    {
      cout << res[i] << ' ';
    }
  }

  return 0;
}
