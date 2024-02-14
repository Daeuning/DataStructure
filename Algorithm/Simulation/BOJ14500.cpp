#include <iostream>
#include <algorithm>
#define X first
#define Y second
using namespace std;
int board[502][502];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int d_horThree_x[7] = {1, 1, 1, 0, -1, -1, -1};
int d_horThree_y[7] = {0, 1, 2, 3, 2, 1, 0};
int d_verThree_x[7] = {0, 1, 2, 3, 2, 1, 0};
int d_verThree_y[7] = {-1, -1, -1, 0, 1, 1, 1};
pair<int, int> d_horTwo_x[2] = {{-1, 1}, {-1, 1}};
pair<int, int> d_horTwo_y[2] = {{0, 1}, {1, 0}};
pair<int, int> d_verTwo_x[2] = {{0, 1}, {1, 0}};
pair<int, int> d_verTwo_y[2] = {{-1, 1}, {-1, 1}};

int N, M, cnt;
int max_area;

void horThree()
{
  cnt = 0;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (j + 1 >= M || j + 2 >= M)
        continue;

      cnt = board[i][j] + board[i][j + 1] + board[i][j + 2];

      pair<int, int> cur = {i, j};

      for (int dir = 0; dir < 7; dir++)
      {
        int nx = cur.X + d_horThree_x[dir];
        int ny = cur.Y + d_horThree_y[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
        {
          continue;
        }
        else
        {
          cnt += board[nx][ny];
          if (cnt > max_area)
            max_area = cnt;
          cnt -= board[nx][ny];
        }
      }
    }
  }
}

void horTwo()
{
  cnt = 0;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (j + 1 >= M)
        continue;

      cnt = board[i][j] + board[i][j + 1];

      pair<int, int> cur = {i, j};
      for (int dir = 0; dir < 2; dir++)
      {
        int nx_1 = cur.X + d_horTwo_x[dir].X;
        int nx_2 = cur.X + d_horTwo_x[dir].Y;
        int ny_1 = cur.Y + d_horTwo_y[dir].X;
        int ny_2 = cur.Y + d_horTwo_y[dir].Y;

        if (nx_1 < 0 || nx_1 >= N || nx_2 < 0 || nx_2 >= N || ny_1 < 0 || ny_1 >= M || ny_2 < 0 || ny_2 >= M)
        {
          continue;
        }
        else
        {
          cnt += board[nx_1][ny_1];
          cnt += board[nx_2][ny_2];
          if (cnt > max_area)
            max_area = cnt;
          cnt -= board[nx_1][ny_1];
          cnt -= board[nx_2][ny_2];
        }
      }
    }
  }
}

void verThree()
{
  cnt = 0;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (i + 1 >= N || i + 2 >= N)
        continue;

      cnt = board[i][j] + board[i + 1][j] + board[i + 2][j];

      pair<int, int> cur = {i, j};
      for (int dir = 0; dir < 7; dir++)
      {
        int nx = cur.X + d_verThree_x[dir];
        int ny = cur.Y + d_verThree_y[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
        {
          continue;
        }
        else
        {
          cnt += board[nx][ny];
          if (cnt > max_area)
            max_area = cnt;
          cnt -= board[nx][ny];
        }
      }
    }
  }
}

void verTwo()
{
  cnt = 0;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (i + 1 >= N)
        continue;

      cnt = board[i][j] + board[i + 1][j];

      pair<int, int> cur = {i, j};
      for (int dir = 0; dir < 2; dir++)
      {
        int nx_1 = cur.X + d_verTwo_x[dir].X;
        int nx_2 = cur.X + d_verTwo_x[dir].Y;
        int ny_1 = cur.Y + d_verTwo_y[dir].X;
        int ny_2 = cur.Y + d_verTwo_y[dir].Y;

        if (nx_1 < 0 || nx_1 >= N || nx_2 < 0 || nx_2 >= N || ny_1 < 0 || ny_1 >= M || ny_2 < 0 || ny_2 >= M)
        {
          continue;
        }
        else
        {
          cnt += board[nx_1][ny_1];
          cnt += board[nx_2][ny_2];
          if (cnt > max_area)
            max_area = cnt;
          cnt -= board[nx_1][ny_1];
          cnt -= board[nx_2][ny_2];
        }
      }
    }
  }
}

void square()
{
  cnt = 0;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (i + 1 >= N || j + 1 >= M)
        continue;

      cnt = board[i][j] + board[i + 1][j] + board[i][j + 1] + board[i + 1][j + 1];

      if (cnt > max_area)
        max_area = cnt;
    }
  }
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
    }
  }

  horThree();
  horTwo();
  verThree();
  verTwo();
  square();

  cout << max_area;

  return 0;
}
