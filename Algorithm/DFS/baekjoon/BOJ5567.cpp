#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M, a_i, b_i, cnt;
int dist[502];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> G[502];
  queue<int> Q;

  fill(dist, dist + 502, -1);

  cin >> N >> M;

  for (int i = 0; i < M; i++)
  {
    cin >> a_i >> b_i;
    G[a_i].push_back(b_i);
    G[b_i].push_back(a_i);
  }

  Q.push(1);
  dist[1] = 0;

  while (!Q.empty())
  {
    int cur = Q.front();
    Q.pop();

    for (auto nxt : G[cur])
    {
      if (dist[nxt] != -1)
        continue;
      Q.push(nxt);
      dist[nxt] = dist[cur] + 1;
    }
  }

  for (int i = 1; i <= N; i++)
  {
    if (dist[i] == 1 || dist[i] == 2)
      cnt++;
  }

  cout << cnt;

  return 0;
}