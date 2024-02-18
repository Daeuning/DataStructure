#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#define X first
#define Y second
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
string puyo[15];
bool vis[15][8];
bool isChain = 1;
bool res;
int chain;

void dfs(int x, int y, char color)
{
  queue<pair<int, int>> Q;
  vector<pair<int, int>> pop;

  for (int i = 0; i < 12; i++)
  {
    fill(vis[i], vis[i] + 6, 0);
  }

  vis[x][y] = 1;
  Q.push({x, y});
  pop.push_back({x, y});

  while (!Q.empty())
  {
    pair<int, int> cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (nx < 0 || nx > 11 || ny < 0 || ny > 5)
        continue;
      if (vis[nx][ny] || puyo[nx][ny] != color)
        continue;
      vis[nx][ny] = 1;
      Q.push({nx, ny});
      pop.push_back({nx, ny});
    }
  }

  if (pop.size() >= 4)
  {
    for (int i = 0; i < pop.size(); i++)
    {
      puyo[pop[i].X][pop[i].Y] = '.';
    }

    isChain = 1;
  }
}

void renewPuyo()
{
  for (int j = 0; j < 6; j++)
  {
    for (int i = 11; i >= 0; i--)
    {
      if (puyo[i][j] != '.')
      {
        int curx = i;
        int cury = j;

        while (1)
        {
          if (curx == 11 || puyo[curx + 1][cury] != '.')
            break;
          puyo[curx + 1][cury] = puyo[curx][cury];
          puyo[curx][cury] = '.';

          curx++;
        }
      }
    }
  }
}

int main(void)
{
  for (int i = 0; i < 12; i++)
  {
    cin >> puyo[i];
  }

  while (isChain)
  {
    isChain = 0;

    for (int i = 0; i < 12; i++)
    {
      for (int j = 0; j < 6; j++)
      {
        if (puyo[i][j] != '.')
        {
          dfs(i, j, puyo[i][j]);
        }
      }
    }

    if (isChain)
      chain++;

    renewPuyo();
  }

  cout << chain;

  return 0;
}