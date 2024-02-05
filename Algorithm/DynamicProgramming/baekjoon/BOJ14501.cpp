#include <iostream>
#include <algorithm>
using namespace std;
int D[1500002];
int T[1500002];
int P[1500002];
int N, curPay, res;

int main(void)
{
  cin >> N;

  for (int i = 1; i <= N; i++)
  {
    cin >> T[i] >> P[i];
  }

  for (int i = 1; i <= N + 1; i++)
  {
    curPay = max(curPay, D[i]);
    if (i + T[i] > N + 1)
      continue;
    D[i + T[i]] = max(D[i + T[i]], P[i] + curPay);
    res = max(res, D[i + T[i]]);
  }

  cout << res;

  return 0;
}