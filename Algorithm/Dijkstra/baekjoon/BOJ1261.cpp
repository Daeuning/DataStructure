#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int D[102][102];
int board[102][102];
int N, M;
string num;
const int INF = 1e9 + 10;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> PQ;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> M >> N;

  for (int i = 1; i <= N; i++)
  {
    cin >> num;
    for (int j = 1; j <= M; j++)
    {
      board[i][j] = num[j - 1] - '0';
      D[i][j] = INF;
    }
  }

  D[1][1] = 0;
  PQ.push({0, {1, 1}});

  while (!PQ.empty())
  {
    auto cur = PQ.top();
    PQ.pop();

    if (D[cur.Y.X][cur.Y.Y] != cur.X)
      continue;

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cur.Y.X + dx[dir];
      int ny = cur.Y.Y + dy[dir];
      if (nx > N || nx < 1 || ny > M || ny < 1)
        continue;
      if (D[nx][ny] <= D[cur.Y.X][cur.Y.Y] + board[nx][ny])
        continue;

      D[nx][ny] = D[cur.Y.X][cur.Y.Y] + board[nx][ny];
      PQ.push({D[nx][ny], {nx, ny}});
    }
  }

  cout << D[N][M];

  return 0;
}