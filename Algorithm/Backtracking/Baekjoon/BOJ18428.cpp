#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define X first
#define Y second
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char board[8][8];
char board2[8][8];
bool vis[8][8];
bool isused[50];
int N;
pair<int, int> arr[8];
char B;
bool isposs;
vector<pair<int, int>> emp;
vector<pair<int, int>> teach;
vector<pair<int, int>> stu;

bool canWatch()
{
  bool watch = 0;

  for (int i = 0; i < stu.size(); i++)
  {
    if (vis[stu[i].X][stu[i].Y])
      watch = 1;
  }

  return watch;
}

void clear()
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      board2[i][j] = board[i][j];
    }
  }
}

void watchTrack(int sel, int idx)
{
  if (sel == 3)
  {
    for (int i = 0; i < N; i++)
    {
      fill(vis[i], vis[i] + N, 0);
    }
    clear();

    for (int i = 0; i < 3; i++)
    {
      board2[arr[i].X][arr[i].Y] = 'O';
    }

    for (int i = 0; i < teach.size(); i++)
    {
      pair<int, int> cur = teach[i];

      for (int dir = 0; dir < 4; dir++)
      {
        int nx = cur.X;
        int ny = cur.Y;
        vis[cur.X][cur.Y] = 1;

        while (1)
        {
          nx += dx[dir];
          ny += dy[dir];
          if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            break;
          if (board2[nx][ny] == 'O')
            break;
          vis[nx][ny] = 1;
        }
      }
    }

    if (!canWatch())
      isposs = 1;

    return;
  }

  for (int i = idx; i < emp.size(); i++)
  {
    if (!isused[i])
    {
      arr[sel] = emp[i];
      isused[i] = 1;
      watchTrack(sel + 1, i);
      isused[i] = 0;
    }
  }
}

int main(void)
{
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> B;
      board[i][j] = B;
      if (B == 'X')
        emp.push_back({i, j});
      if (B == 'T')
        teach.push_back({i, j});
      if (B == 'S')
        stu.push_back({i, j});
    }
  }

  watchTrack(0, 0);

  if (isposs)
    cout << "YES";
  else
    cout << "NO";

  return 0;
}