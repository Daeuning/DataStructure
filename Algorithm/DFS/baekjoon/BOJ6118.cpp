#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M, A_i, B_i, cnt;
int max_dist = 0;
int res = 20002;
int dist[20002];

int main(void)
{
  vector<int> G[20002];
  queue<int> Q;
  priority_queue<int, vector<int>, greater<int>> PQ;
  fill(dist, dist + 20002, -1);

  cin >> N >> M;

  for (int i = 0; i < M; i++)
  {
    cin >> A_i >> B_i;
    G[A_i].push_back(B_i);
    G[B_i].push_back(A_i);
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

  res = *max_element(dist, dist + N + 1);

  for (int i = 1; i < N + 1; i++)
  {
    if (dist[i] == res)
    {
      PQ.push(i);
    }
  }

  cout << PQ.top() << ' ';
  cout << res << ' ' << PQ.size();

  return 0;
}