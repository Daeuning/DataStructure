#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int T, N, cnt;
bool isBreak = 0;
int arr[1002];
int vis[1002];

int main(void)
{
  cin >> T;

  while (T--)
  {
    cnt = 0;
    fill(vis, vis + 1002, 0);
    vector<int> G[1002];
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
      cin >> arr[i];
      G[i].push_back(arr[i]);
    }

    for (int i = 1; i <= N; i++)
    {
      if (vis[i])
        continue;

      stack<int> S;
      S.push(i);
      vis[i] = 1;

      while (!S.empty())
      {
        int cur = S.top();
        S.pop();

        int nxt = G[cur][0];

        if (nxt == i)
        {
          cnt++;
          break;
        }

        S.push(nxt);
        vis[nxt] = 1;
      }
    }

    cout << cnt << '\n';
  }

  return 0;
}