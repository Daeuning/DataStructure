#include <iostream>
#include <algorithm>
using namespace std;
int d[1000002];
int N, T;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;

  for (int i = 0; i < T; i++)
  {
    cin >> N;

    fill(d, d + N, 0);

    d[1] = 1;
    d[2] = 2;
    d[3] = 4;

    for (int i = 4; i <= N; i++)
    {
      d[i] = d[i - 1] + d[i - 2] + d[i - 3];
    }

    cout << d[N] << '\n';
  }

  return 0;
}