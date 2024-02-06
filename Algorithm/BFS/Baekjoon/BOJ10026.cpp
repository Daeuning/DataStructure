#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second

char board[102][102];
bool vis[102][102];

int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// 색 영역 구분하는 BFS
int Bfs()
{
  queue<pair<int, int>> Q;
  int cnt = 0;
  char color;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (vis[i][j] != 0)
        continue;
      color = board[i][j];
      cnt++;

      vis[i][j] = 1;
      Q.push({i, j});

      while (!Q.empty())
      {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
          int nx = cur.first + dx[dir];
          int ny = cur.second + dy[dir];
          if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
          if (vis[nx][ny] || board[nx][ny] != color)
            continue;
          vis[nx][ny] = 1;
          Q.push({nx, ny});
        }
      }
    }
  }

  return cnt;
}

// 색약 board로 바꾸기
void boardChange()
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (board[i][j] == 'R' || board[i][j] == 'G')
        board[i][j] = 'C';
    }
  }
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
    }
  }

  // 적록색약이 아닌사람
  cout << Bfs() << ' ';

  // vis배열 초기화
  for (int i = 0; i < N; i++)
  {
    fill(vis[i], vis[i] + N, 0);
  }

  // 색약 board로 바꾸기
  boardChange();

  // 적록색약인 사람
  cout << Bfs();

  return 0;
}