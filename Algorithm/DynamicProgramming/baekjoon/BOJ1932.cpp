#include <iostream>
#include <algorithm>
using namespace std;
int D[502][502];
int arr[502][502];
int N;
int main(void)
{
  cin >> N;

  cin >> arr[1][1];

  D[1][1] = arr[1][1];

  for (int i = 2; i <= N; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cin >> arr[i][j];
      D[i][j] = max(D[i - 1][j - 1], D[i - 1][j]) + arr[i][j];
    }
  }

  cout << *max_element(D[N], D[N] + N + 1);

  return 0;
}