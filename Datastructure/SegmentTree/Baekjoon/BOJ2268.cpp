#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
long long a, b, c;
long long T[4 * 1000002];
long long arr[1000002];

void query_update(int node, int st, int ed, int idx, long long val)
{
  if (idx < st || idx > ed)
  {
    return;
  }
  if (st == ed)
  {
    arr[idx] = val;
    T[node] = val;
    return;
  }
  query_update(node * 2, st, (st + ed) / 2, idx, val);
  query_update(node * 2 + 1, (st + ed) / 2 + 1, ed, idx, val);
  T[node] = T[node * 2] + T[node * 2 + 1];
}

long long query_add(int node, int st, int ed, int L, int R)
{
  if (L > ed || R < st)
  {
    return 0;
  }
  if (L <= st && ed <= R)
  {
    return T[node];
  }
  return query_add(node * 2, st, (st + ed) / 2, L, R) + query_add(node * 2 + 1, (st + ed) / 2 + 1, ed, L, R);
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 1; i <= M; i++)
  {
    cin >> a >> b >> c;

    if (a == 0)
    {
      int left = min(b, c);
      int right = max(b, c);
      cout << query_add(1, 1, N, left, right) << '\n';
    }
    else if (a == 1)
    {
      query_update(1, 1, N, b, c);
    }
  }

  return 0;
}