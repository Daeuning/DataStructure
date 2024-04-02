#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int R, C;
bool res;
int vis[12][12];
string board[12];
queue<pair<int, int>> Q;

int main(void)
{
  cin >> R >> C;

  for (int i = 0; i < R; i++)
  {
    cin >> board[i];
  }

  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      if (board[i][j] == '.')
      {
        Q.push({i, j});
        vis[i][j] = 1;

        while (!Q.empty())
        {
          int ispossible = 0;

          pair<int, int> cur = Q.front();
          Q.pop();

          for (int dir = 0; dir < 4; dir++)
          {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
              continue;
            if (board[nx][ny] == 'X')
              continue;
            ispossible++;
            if (vis[nx][ny])
              continue;
            Q.push({nx, ny});
            vis[nx][ny] = 1;
          }

          if (ispossible == 1)
          {
            cout << 1;
            return 0;
          }
        }

        cout << 0;
        return 0;
      }
    }
  }
}