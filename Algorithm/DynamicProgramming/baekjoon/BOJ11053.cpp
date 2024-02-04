#include <iostream>
#include <algorithm>
using namespace std;
int D[1002];
int num[1002];
int N;
int max_num = -1;

int main(void)
{
  cin >> N;

  for (int i = 1; i <= N; i++)
  {
    cin >> num[i];
  }

  for (int i = 1; i <= N; i++)
  {
    D[i] = 1;

    for (int j = i - 1; j >= 1; j--)
    {
      if (num[i] > num[j])
      {
        D[i] = max(D[i], D[j] + 1);
      }
    }
  }

  cout << *max_element(D, D + N + 1);

  return 0;
}