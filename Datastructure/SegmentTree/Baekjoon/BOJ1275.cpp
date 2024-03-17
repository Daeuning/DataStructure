#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, Q;
long long a, b, c, d;
long long T[4 * 100002];
long long arr[100002];

void init(int node, int st, int ed)
{
  if (st == ed)
  {
    T[node] = arr[st];
  }
  else
  {
    init(node * 2, st, (st + ed) / 2);
    init(node * 2 + 1, (st + ed) / 2 + 1, ed);
    T[node] = T[node * 2] + T[node * 2 + 1];
  }
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

  cin >> N >> Q;

  for (int i = 1; i <= N; i++)
  {
    cin >> arr[i];
  }

  init(1, 1, N);

  for (int i = 1; i <= Q; i++)
  {
    cin >> a >> b >> c >> d;

    int left = min(a, b);
    int right = max(a, b);
    cout << query_add(1, 1, N, left, right) << '\n';

    query_update(1, 1, N, c, d);
  }

  return 0;
}