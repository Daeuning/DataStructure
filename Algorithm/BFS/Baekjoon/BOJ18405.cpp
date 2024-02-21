#include <iostream>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int board[202][202];
int dist[202][202];
int N, K, S, X, Y;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> PQ;

void bfs()
{
  for (int i = 1; i <= N; i++)
  {
    fill(dist[i], dist[i] + N, -1);
  }

  queue<pair<int, int>> Q;

  while (!PQ.empty())
  {
    int x = PQ.top().Y.X;
    int y = PQ.top().Y.Y;

    dist[x][y] = 0;
    Q.push({x, y});
    PQ.pop();
  }

  while (!Q.empty())
  {
    pair<int, int> cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (nx < 1 || nx > N || ny < 1 || ny > N)
        continue;
      if (dist[nx][ny] != -1 || board[nx][ny] != 0)
        continue;
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      board[nx][ny] = board[cur.X][cur.Y];
      Q.push({nx, ny});
    }
  }

  return;
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      cin >> board[i][j];

      if (board[i][j] > 0 && board[i][j] <= K)
      {
        PQ.push({board[i][j], {i, j}});
      }
    }
  }

  cin >> S >> X >> Y;

  bfs();

  if (dist[X][Y] <= S)
    cout << board[X][Y];
  else
    cout << 0;

  return 0;
}