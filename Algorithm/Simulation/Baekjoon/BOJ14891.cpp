#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
string wheelarr[6];
int K, wheelnum, dir;
int status[6];
int idx[6];
int vis[6];
int dy[2] = {1, -1};
queue<int> Q;

void setIndex()
{
  for (int i = 1; i <= 4; i++)
  {
    idx[i] += ((-1) * status[i]);

    if (idx[i] < 0)
    {
      idx[i] = 8 - (abs(idx[i]) % 8);
    }
    else if (idx[i] > 0)
    {
      idx[i] = idx[i] % 8;
    }
  }
}

int score(int wheel_num, int idx)
{
  if (wheel_num == 1)
  {
    if (wheelarr[1][idx] == '1')
      return 1;
    else
      return 0;
  }
  else if (wheel_num == 2)
  {
    if (wheelarr[2][idx] == '1')
      return 2;
    else
      return 0;
  }
  else if (wheel_num == 3)
  {
    if (wheelarr[3][idx] == '1')
      return 4;
    else
      return 0;
  }
  else if (wheel_num == 4)
  {
    if (wheelarr[4][idx] == '1')
      return 8;
    else
      return 0;
  }
}

void wheelCompare(int cur_wheel, int nxt_wheel)
{
  int left_cur = (idx[cur_wheel] + 6) % 8;
  int right_cur = (idx[cur_wheel] + 2) % 8;
  int left_nxt = (idx[nxt_wheel] + 6) % 8;
  int right_nxt = (idx[nxt_wheel] + 2) % 8;

  if (cur_wheel < nxt_wheel)
  {
    if (wheelarr[cur_wheel][right_cur] != wheelarr[nxt_wheel][left_nxt])
    {
      status[nxt_wheel] = ((-1) * status[cur_wheel]);
    }
    else
    {
      status[nxt_wheel] = 0;
    }
  }
  else
  {
    if (wheelarr[cur_wheel][left_cur] != wheelarr[nxt_wheel][right_nxt])
    {
      status[nxt_wheel] = ((-1) * status[cur_wheel]);
    }
    else
    {
      status[nxt_wheel] = 0;
    }
  }
}

int main(void)
{
  for (int i = 1; i <= 4; i++)
  {
    cin >> wheelarr[i];
  }

  cin >> K;

  while (K--)
  {
    cin >> wheelnum >> dir;

    status[wheelnum] = dir;
    vis[wheelnum] = 1;
    Q.push(wheelnum);

    while (!Q.empty())
    {
      int cur = Q.front();
      Q.pop();

      for (int i = 0; i < 2; i++)
      {
        int nxt = cur + dy[i];
        if (nxt <= 0 || nxt > 4)
          continue;
        if (vis[nxt])
          continue;

        wheelCompare(cur, nxt);

        vis[nxt] = 1;
        Q.push(nxt);
      }
    }

    setIndex();
    fill(status, status + 6, 0);
    fill(vis, vis + 6, 0);
  }

  int res = 0;

  for (int i = 1; i <= 4; i++)
  {
    res += score(i, idx[i]);
  }

  cout << res;
}