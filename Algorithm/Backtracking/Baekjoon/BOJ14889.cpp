#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int power[22][22];
bool isused[22];
int N, start_team, link_team;
int min_power = 200;

void teamTracing(int sel, int idx)
{
  if (sel == N / 2)
  {
    link_team = 0;
    start_team = 0;
    vector<int> start;
    vector<int> link;
    for (int i = 1; i <= N; i++)
    {
      if (isused[i])
        start.push_back(i);
      if (!isused[i])
        link.push_back(i);
    }

    for (int i = 0; i < N / 2; i++)
    {
      for (int j = i + 1; j < N / 2; j++)
      {
        start_team += power[start[i]][start[j]] + power[start[j]][start[i]];
        link_team += power[link[i]][link[j]] + power[link[j]][link[i]];
      }
    }

    min_power = min(min_power, abs(start_team - link_team));
  }

  for (int i = idx; i <= N; i++)
  {
    if (!isused[i])
    {
      isused[i] = 1;
      teamTracing(sel + 1, i);
      isused[i] = 0;
    }
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      cin >> power[i][j];
    }
  }

  teamTracing(0, 1);

  cout << min_power;

  return 0;
}