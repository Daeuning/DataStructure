#include <iostream>
#include <algorithm>
using namespace std;
int D[10002];
int N;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  D[1] = 1;
  D[2] = 2;

  for (int i = 3; i <= N; i++)
  {
    D[i] = (D[i - 1] + D[i - 2]) % 10007;
  }

  cout << D[N];

  return 0;
}