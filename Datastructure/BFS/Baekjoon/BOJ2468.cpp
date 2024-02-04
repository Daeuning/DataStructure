#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
int board[102][102];
int copyBoard[102][102];
int vis[102][102];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int N;
int max_depth = 0;
int max_area = 0;
queue<pair<int, int>> Q;

int bfs(int rain)
{
  int cnt = 0;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      vis[i][j] = 0;
      if (board[i][j] <= rain)
        copyBoard[i][j] = 1;
      else
        copyBoard[i][j] = 0;
    }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (copyBoard[i][j] == 1 || vis[i][j] == 1)
        continue;
      cnt++;

      Q.push({i, j});
      vis[i][j] = 1;

      while (!Q.empty())
      {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];

          if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
          if (vis[nx][ny] || copyBoard[nx][ny] == 1)
            continue;
          Q.push({nx, ny});
          vis[nx][ny] = 1;
        }
      }
    }
  }

  return cnt;
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> board[i][j];
      if (board[i][j] > max_depth)
        max_depth = board[i][j];
    }
  }

  for (int i = 0; i < max_depth; i++)
  {
    int temp = bfs(i);
    if (temp > max_area)
      max_area = temp;
  }

  cout << max_area;

  return 0;
}