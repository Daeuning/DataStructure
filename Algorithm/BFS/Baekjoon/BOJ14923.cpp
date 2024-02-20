#include <iostream>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
const int MAX = 1e9 + 10;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int board[1002][1002];
int dist[1002][1002];
int N, M, Hx, Hy, Ex, Ey;
int min_dis = MAX;
vector<pair<int, int>> magic;

int bfs(int x, int y)
{
  queue<pair<int, int>> Q;

  for (int i = 1; i <= N; i++)
  {
    fill(dist[i], dist[i] + M + 1, -1);
  }

  board[x][y] = 0;

  dist[Hx][Hy] = 0;
  Q.push({Hx, Hy});

  while (!Q.empty())
  {
    pair<int, int> cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (nx < 1 || nx > N || ny < 1 || ny > M)
        continue;
      if (dist[nx][ny] != -1 || board[nx][ny] == 1)
        continue;
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      if (nx == Ex && ny == Ey)
      {
        board[x][y] = 1;
        return dist[nx][ny];
      }
      Q.push({nx, ny});
    }
  }

  return MAX;
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  cin >> Hx >> Hy;
  cin >> Ex >> Ey;

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= M; j++)
    {
      cin >> board[i][j];
      if (board[i][j] == 1)
        magic.push_back({i, j});
    }
  }

  for (int i = 0; i < magic.size(); i++)
  {
    min_dis = min(min_dis, bfs(magic[i].X, magic[i].Y));
  }

  if (min_dis == MAX)
    cout << -1;
  else
    cout << min_dis;

  return 0;
}