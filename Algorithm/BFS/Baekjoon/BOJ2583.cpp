#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
int board[102][102];
bool vis[102][102];
int res[102];
int N, M, K, fir_x, fir_y, sec_x, sec_y, num, area;
queue<pair<int, int>> Q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void square(int f_x, int f_y, int s_x, int s_y)
{
  for (int i = f_x; i <= s_x; i++)
  {
    for (int j = f_y; j <= s_y; j++)
    {
      board[i][j] = 1;
      vis[i][j] = 1;
    }
  }
}

void bfs(int i, int j)
{
  area = 0;
  Q.push({i, j});
  vis[i][j] = 1;

  while (!Q.empty())
  {
    pair<int, int> cur = Q.front();
    Q.pop();
    area++;

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (nx < 0 || nx >= M || ny < 0 || ny >= N)
        continue;
      if (vis[nx][ny] || board[nx][ny])
        continue;
      vis[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }

  res[num - 1] = area;
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> M >> N >> K;

  for (int i = 0; i < K; i++)
  {
    cin >> fir_x >> fir_y >> sec_x >> sec_y;
    square(fir_y, fir_x, sec_y - 1, sec_x - 1);
  }

  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (board[i][j] == 0 && vis[i][j] == 0)
      {
        num++;
        bfs(i, j);
      }
    }
  }

  cout << num << '\n';
  sort(res, res + num);
  for (int i = 0; i < num; i++)
  {
    cout << res[i] << ' ';
  }

  return 0;
}