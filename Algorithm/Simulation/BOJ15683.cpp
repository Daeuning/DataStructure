#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int N, M, num, cnt, watch_dir, area_res;
int res[10][10];
int board[10][10];
int board_res[10][10];
int min_dir[10][10];

void watch(int x, int y, int dir)
{
  watch_dir = dir % 4;

  while (1)
  {
    int nx = x + dx[watch_dir];
    int ny = y + dy[watch_dir];
    if (nx < 0 || nx >= N || ny < 0 || ny >= M)
      break;
    if (board_res[nx][ny] == 6)
      break;
    if (board_res[nx][ny] != 0)
    {
      x = nx;
      y = ny;
      continue;
    }
    board_res[nx][ny] = 7;
    x = nx;
    y = ny;
  }
}

void insert(int x, int y, int dir)
{
  watch_dir = dir % 4;

  while (1)
  {
    int nx = x + dx[watch_dir];
    int ny = y + dy[watch_dir];
    if (nx < 0 || nx >= N || ny < 0 || ny >= M)
      break;
    if (board[nx][ny] == 6)
      break;
    if (board[nx][ny] != 0)
    {
      x = nx;
      y = ny;
      continue;
    }
    board[nx][ny] = 7;
    x = nx;
    y = ny;
  }
}

void clear(void)
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      board_res[i][j] = board[i][j];
    }
  }
}

int area()
{
  cnt = 0;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (board_res[i][j] == 0)
        cnt++;
    }
  }

  return cnt;
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> board[i][j];
      board_res[i][j] = board[i][j];
      res[i][j] = N * M;
    }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      num = board[i][j];

      for (int dir = 0; dir < 4; dir++)
      {
        clear();

        if (num == 1)
        {
          watch(i, j, 0 + dir);
          area_res = area();
          if (res[i][j] > area_res)
          {
            res[i][j] = area_res;
            min_dir[i][j] = dir;
          }
        }
        else if (num == 2)
        {
          watch(i, j, 0 + dir);
          watch(i, j, 2 + dir);
          area_res = area();
          if (res[i][j] > area_res)
          {
            res[i][j] = area_res;
            min_dir[i][j] = dir;
          }
        }
        else if (num == 3)
        {
          watch(i, j, 0 + dir);
          watch(i, j, 1 + dir);
          area_res = area();
          if (res[i][j] > area_res)
          {
            res[i][j] = area_res;
            min_dir[i][j] = dir;
          }
        }
        else if (num == 4)
        {
          watch(i, j, 0 + dir);
          watch(i, j, 1 + dir);
          watch(i, j, 2 + dir);
          area_res = area();
          if (res[i][j] > area_res)
          {
            res[i][j] = area_res;
            min_dir[i][j] = dir;
          }
        }
        else if (num == 5)
        {
          watch(i, j, 0 + dir);
          watch(i, j, 1 + dir);
          watch(i, j, 2 + dir);
          watch(i, j, 3 + dir);
          area_res = area();
          if (res[i][j] > area_res)
          {
            res[i][j] = area_res;
            min_dir[i][j] = dir;
          }
        }
      }

      if (num == 1)
      {
        insert(i, j, 0 + min_dir[i][j]);
      }
      else if (num == 2)
      {
        insert(i, j, 0 + min_dir[i][j]);
        insert(i, j, 2 + min_dir[i][j]);
      }
      else if (num == 3)
      {
        insert(i, j, 0 + min_dir[i][j]);
        insert(i, j, 1 + min_dir[i][j]);
      }
      else if (num == 4)
      {
        insert(i, j, 0 + min_dir[i][j]);
        insert(i, j, 1 + min_dir[i][j]);
        insert(i, j, 2 + min_dir[i][j]);
      }
      else if (num == 5)
      {
        insert(i, j, 0 + min_dir[i][j]);
        insert(i, j, 1 + min_dir[i][j]);
        insert(i, j, 2 + min_dir[i][j]);
        insert(i, j, 3 + min_dir[i][j]);
      }
    }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cout << min_dir[i][j] << ' ';
    }
    cout << '\n';
  }

  cout << '\n';

  int solve = 0;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (board[i][j] == 0)
        solve++;
    }
  }

  cout << solve;

  return 0;
}
