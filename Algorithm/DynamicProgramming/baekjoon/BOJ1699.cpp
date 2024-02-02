#include <iostream>
#include <algorithm>
using namespace std;
int D[100002];
int N;

int main(void)
{
  cin >> N;

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      if (j * j > i)
        break;
      if (D[i] == 0)
        D[i] = D[i - (j * j)] + 1;
      else
        D[i] = min(D[i], D[i - (j * j)] + 1);
    }
  }

  cout << D[N];

  return 0;
}