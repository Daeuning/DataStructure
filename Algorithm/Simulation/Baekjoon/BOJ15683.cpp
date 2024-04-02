#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int board[10][10];
int copy_board[10][10];
int arr[100];
int N, M, watch_dir, min_area, cnum, cur_dir, res, cnt, idx;
deque<int> DQ;

void watch(int x, int y, int dir)
{
  watch_dir = dir % 4;

  while (1)
  {
    int nx = x + dx[watch_dir];
    int ny = y + dy[watch_dir];
    if (nx < 0 || nx >= N || ny < 0 || ny >= M)
      break;
    if (copy_board[nx][ny] == 6)
      break;
    if (copy_board[nx][ny] != 0)
    {
      x = nx;
      y = ny;
      continue;
    }
    copy_board[nx][ny] = 7;
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
      copy_board[i][j] = board[i][j];
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
      if (copy_board[i][j] == 0)
        cnt++;
    }
  }

  return cnt;
}

void watchTrack(int sel)
{
  // base condition
  if (sel == cnum)
  {
    clear();
    idx = 0;

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        if (copy_board[i][j] >= 1 && copy_board[i][j] <= 5)
        {
          cur_dir = arr[idx];
          idx++;

          if (copy_board[i][j] == 1)
          {
            watch(i, j, 0 + cur_dir);
          }
          else if (copy_board[i][j] == 2)
          {
            watch(i, j, 0 + cur_dir);
            watch(i, j, 2 + cur_dir);
          }
          else if (copy_board[i][j] == 3)
          {
            watch(i, j, 0 + cur_dir);
            watch(i, j, 1 + cur_dir);
          }
          else if (copy_board[i][j] == 4)
          {
            watch(i, j, 0 + cur_dir);
            watch(i, j, 1 + cur_dir);
            watch(i, j, 2 + cur_dir);
          }
          else if (copy_board[i][j] == 5)
          {
            watch(i, j, 0 + cur_dir);
            watch(i, j, 1 + cur_dir);
            watch(i, j, 2 + cur_dir);
            watch(i, j, 3 + cur_dir);
          }
        }
      }
    }

    res = area();
    if (res < min_area)
      min_area = res;
    return;
  }

  // recursion
  for (int dir = 0; dir <= 3; dir++)
  {
    arr[sel] = dir;
    watchTrack(sel + 1);
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  min_area = N * M;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> board[i][j];
      if (board[i][j] != 6 && board[i][j] != 0)
        cnum++;
    }
  }

  watchTrack(0);

  cout << min_area;

  return 0;
}