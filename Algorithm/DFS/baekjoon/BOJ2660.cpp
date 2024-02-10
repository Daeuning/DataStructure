#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, p1, p2, point, cnt;
int cand[52];
int dist[52];
queue<int> Q;
vector<int> G[52];

int bfs(int num)
{
  fill(dist, dist + 52, -1);
  point = 0;

  Q.push(num);
  dist[num] = 0;

  while (!Q.empty())
  {
    int cur = Q.front();
    Q.pop();

    for (auto nxt : G[cur])
    {
      if (dist[nxt] != -1)
        continue;
      dist[nxt] = dist[cur] + 1;
      if (dist[nxt] > point)
        point = dist[nxt];
      Q.push(nxt);
    }
  }

  return point;
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  while (1)
  {
    cin >> p1 >> p2;

    if (p1 == -1 && p2 == -1)
      break;
    G[p1].push_back(p2);
    G[p2].push_back(p1);
  }

  for (int i = 1; i <= N; i++)
  {
    cand[i] = bfs(i);
  }

  int min_point = *min_element(cand + 1, cand + N + 1);

  for (int i = 1; i <= N; i++)
  {
    if (cand[i] == min_point)
    {
      cnt++;
      Q.push(i);
    }
  }

  cout << min_point << ' ' << cnt << '\n';

  while (!Q.empty())
  {
    cout << Q.front() << ' ';
    Q.pop();
  }

  return 0;
}