#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
int board[102][102][102];
int dist[102][102][102];
queue<tuple<int, int, int>> Q;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int M, N, H;
int isRipe = 1;

int main(void)
{
  cin >> M >> N >> H;

  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < N; j++)
    {
      for (int k = 0; k < M; k++)
      {
        int temp;
        cin >> temp;
        board[j][k][i] = temp;
        if (temp == 1)
          Q.push({j, k, i});
        if (temp == 0)
        {
          dist[j][k][i] = -1;
          isRipe = 0;
        }
      }
    }
  }

  // 모두 익어있을 경우 0출력 후 종료
  if (isRipe == 1)
  {
    cout << 0 << '\n';
    return 0;
  }

  while (!Q.empty())
  {
    auto cur = Q.front();
    Q.pop();

    int curX, curY, curZ;
    tie(curX, curY, curZ) = cur;

    for (int dir = 0; dir < 6; dir++)
    {
      int nx = curX + dx[dir];
      int ny = curY + dy[dir];
      int nz = curZ + dz[dir];

      if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H)
        continue;
      if (dist[nx][ny][nz] != -1)
        continue;
      dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
      Q.push({nx, ny, nz});
    }
  }

  int max = 0;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < N; j++)
    {
      for (int k = 0; k < M; k++)
      {
        if (dist[j][k][i] == -1)
        {
          cout << -1 << '\n';
          return 0;
        }
        if (dist[j][k][i] > max)
          max = dist[j][k][i];
      }
    }
  }

  cout << max << '\n';

  return 0;
}