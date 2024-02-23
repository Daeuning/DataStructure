#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define X first
#define Y second
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int board[52][52];
int vis[52][52];
int N, L, R, date, sum, area;
bool isMove;

void endDay()
{
  for (int i = 0; i < N; i++)
  {
    fill(vis[i], vis[i] + N, 0);
  }
}

void countPopul()
{
  int population = sum / area;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (vis[i][j] == 1)
      {
        board[i][j] = population;
        vis[i][j] = 2;
      }
    }
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> L >> R;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> board[i][j];
    }
  }

  while (1)
  {
    isMove = 0;
    // 시작점찾아 하루 국경열기
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        // 시작점 찾았을 경우
        if (vis[i][j] > 0)
          continue;
        queue<pair<int, int>> Q;
        int moveCount = 0;
        sum = 0;
        area = 0;

        Q.push({i, j});
        vis[i][j] = 1;
        sum += board[i][j];

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
            if (vis[nx][ny] > 0)
              continue;

            int diff = abs(board[cur.X][cur.Y] - board[nx][ny]);
            if (diff >= L && diff <= R)
            {
              isMove = 1;
              moveCount++;
              sum += board[nx][ny];
              vis[nx][ny] = 1;
              Q.push({nx, ny});
            }
          }
        }

        if (moveCount)
          countPopul();
        else
          vis[i][j] = 2;
      }
    }

    if (isMove)
    {
      date++;
      endDay();
    }
    else
    {
      cout << date;
      return 0;
    }
  }
}