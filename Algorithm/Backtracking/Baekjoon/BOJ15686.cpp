#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>
#define X first
#define Y second
using namespace std;
int N, M, idx, tot;
int min_dis = 1e9 + 10;
int res = 1e9 + 10;
int board[52][52];
bool isused[20];
int store[20];
vector<pair<int, int>> chic;
vector<pair<int, int>> home;

void chicTrack(int sel, int idx)
{
  if (sel == M)
  {
    tot = 0;

    for (int i = 0; i < home.size(); i++)
    {
      min_dis = 1e9 + 10;
      for (int j = 0; j < M; j++)
      {
        int dis = abs(home[i].X - chic[store[j]].X) + abs(home[i].Y - chic[store[j]].Y);
        min_dis = min(min_dis, dis);
      }
      tot += min_dis;
    }
    res = min(res, tot);
    return;
  }

  for (int i = idx; i < chic.size(); i++)
  {
    isused[i] = 1;
    store[sel] = i;
    chicTrack(sel + 1, i + 1);
    isused[i] = 0;
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      cin >> board[i][j];
      if (board[i][j] == 2)
        chic.push_back({i, j});
      if (board[i][j] == 1)
        home.push_back({i, j});
    }
  }

  chicTrack(0, 0);

  cout << res;

  return 0;
}