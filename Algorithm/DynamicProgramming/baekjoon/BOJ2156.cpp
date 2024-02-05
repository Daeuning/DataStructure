#include <iostream>
#include <algorithm>
using namespace std;
int D[10002];
int G[10002];
int N;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 1; i <= N; i++)
  {
    cin >> G[i];
  }

  D[1] = G[1];
  D[2] = G[1] + G[2];

  for (int i = 3; i <= N; i++)
  {
    D[i] = max(D[i - 3] + G[i - 1] + G[i], max(D[i - 1], D[i - 2] + G[i]));
  }

  cout << D[N];

  return 0;
}