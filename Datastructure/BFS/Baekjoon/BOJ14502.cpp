#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int board[12][12];
int copyBoard[12][12];
int vis[12][12];

queue<pair<int, int>> Q;
int N, M, max_cnt;

int wallBfs(int num1, int num2, int num3)
{
  int cnt = 0;

  for (int i = 0; i <= 11; i++)
  {
    fill(vis[i], vis[i] + 11, 0);
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      copyBoard[i][j] = board[i][j];
      if (copyBoard[i][j] == 2)
      {
        Q.push({i, j});
        vis[i][j] = 1;
      }
    }
  }

  copyBoard[num1 / M][num1 % M] = 1;
  copyBoard[num2 / M][num2 % M] = 1;
  copyBoard[num3 / M][num3 % M] = 1;

  while (!Q.empty())
  {
    pair<int, int> cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (nx < 0 || nx >= N || ny < 0 || ny >= M)
        continue;
      if (vis[nx][ny] || copyBoard[nx][ny] != 0)
        continue;
      Q.push({nx, ny});
      copyBoard[nx][ny] = 2;
      vis[nx][ny] = 1;
    }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (copyBoard[i][j] == 0)
        cnt++;
    }
  }

  return cnt;
}

int main(void)
{
  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < N * M; i++)
  {
    for (int j = i + 1; j < N * M; j++)
    {
      for (int k = j + 1; k < N * M; k++)
      {
        if (board[i / M][i % M] == 0 && board[j / M][j % M] == 0 && board[k / M][k % M] == 0)
        {
          int res = wallBfs(i, j, k);
          if (res > max_cnt)
            max_cnt = res;
        }
      }
    }
  }

  cout << max_cnt;

  return 0;
}