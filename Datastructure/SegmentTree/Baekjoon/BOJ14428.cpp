#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define X first
#define Y second
int N, M;
long long a, b, c;
long long T_min[4 * 100002];
long long T_idx[4 * 100002];
long long arr[100002];
const int MAX = 1e9 + 10;

void init_min(int node, int st, int ed)
{
  if (st == ed)
  {
    T_min[node] = arr[st];
    T_idx[node] = st;
  }
  else
  {
    init_min(node * 2, st, (st + ed) / 2);
    init_min(node * 2 + 1, (st + ed) / 2 + 1, ed);

    if (T_min[node * 2] <= T_min[node * 2 + 1])
    {
      T_min[node] = T_min[node * 2];
      T_idx[node] = T_idx[node * 2];
    }
    else
    {
      T_min[node] = T_min[node * 2 + 1];
      T_idx[node] = T_idx[node * 2 + 1];
    }
  }
}

pair<long long, long long> query_min(int node, int st, int ed, int L, int R)
{
  if (L > ed || R < st)
  {
    return {MAX, 0};
  }
  if (L <= st && ed <= R)
  {
    return {T_min[node], T_idx[node]};
  }
  return min(query_min(node * 2, st, (st + ed) / 2, L, R), query_min(node * 2 + 1, (st + ed) / 2 + 1, ed, L, R));
}

void query_update(int node, int st, int ed, int idx, long long val)
{
  if (idx < st || idx > ed)
  {
    return;
  }
  if (st == ed)
  {
    arr[idx] = val;
    T_min[node] = val;
    T_idx[node] = st;
    return;
  }
  query_update(node * 2, st, (st + ed) / 2, idx, val);
  query_update(node * 2 + 1, (st + ed) / 2 + 1, ed, idx, val);

  if (T_min[node * 2] <= T_min[node * 2 + 1])
  {
    T_min[node] = T_min[node * 2];
    T_idx[node] = T_idx[node * 2];
  }
  else
  {
    T_min[node] = T_min[node * 2 + 1];
    T_idx[node] = T_idx[node * 2 + 1];
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 1; i <= N; i++)
  {
    cin >> arr[i];
  }

  cin >> M;

  init_min(1, 1, N);

  for (int i = 1; i <= M; i++)
  {
    cin >> a >> b >> c;

    if (a == 1)
    {
      query_update(1, 1, N, b, c);
    }
    else if (a == 2)
    {
      pair<long long, long long> res;
      res = query_min(1, 1, N, b, c);
      cout << res.Y << '\n';
    }
  }

  return 0;
}