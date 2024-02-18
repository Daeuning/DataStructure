#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int D[12][12];
int arr[12];
bool isused[12];
int N, M, T;
int min_time = 1e9 + 10;
vector<int> planet;

void planetTrack(int sel)
{
  if (sel == N - 1)
  {
    int dis = 0;
    int st = M;

    for (int i = 0; i < N - 1; i++)
    {
      dis += D[st][arr[i]];
      st = arr[i];
    }

    min_time = min(min_time, dis);

    return;
  }

  for (int i = 0; i < N - 1; i++)
  {
    if (!isused[i])
    {
      arr[sel] = planet[i];
      isused[i] = 1;
      planetTrack(sel + 1);
      isused[i] = 0;
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
    if (i != M)
      planet.push_back(i);
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> T;
      D[i][j] = T;
    }
  }

  for (int k = 0; k < N; k++)
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
      }
    }
  }

  planetTrack(0);

  cout << min_time;

  return 0;
}