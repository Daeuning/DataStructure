#include <iostream>
#include <queue>
using namespace std;
int dist[100002];

int N, K;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  fill(dist, dist + 100001, -1);

  queue<int> Q;
  Q.push(N);
  dist[N] = 0;

  while (!Q.empty())
  {
    int cur = Q.front();
    // 순회하는 좌표 조건 설정
    int place[3] = {-1, 1, cur};
    Q.pop();

    for (int i = 0; i < 3; i++)
    {
      int location = cur + place[i];

      if (location < 0 || location > 100000)
        continue;
      if (dist[location] != -1)
        continue;
      dist[location] = dist[cur] + 1;
      Q.push(location);
    }
  }

  cout << dist[K];

  return 0;
}