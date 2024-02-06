#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

string board[27];
int vis[27][27];
int res[27];
int N, num;

void bfs(int i, int j)
{
  int area = 0;
  queue<pair<int, int>> Q;
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

      if (nx < 0 || nx >= N || ny < 0 || ny >= N)
        continue;
      if (vis[nx][ny] == 1 || board[nx][ny] == '0')
        continue;
      vis[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }

  res[num - 1] = area;
}

int main(void)
{
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> board[i];
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (board[i][j] == '1' && vis[i][j] == 0)
      {
        num++;
        bfs(i, j);
      }
    }
  }

  sort(res, res + num);

  cout << num << '\n';
  for (int i = 0; i < num; i++)
  {
    cout << res[i] << '\n';
  }

  return 0;
}