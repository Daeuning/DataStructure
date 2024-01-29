#include <iostream>
#include <algorithm>
using namespace std;
int d[302];
int arr[302];
int N;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 1; i <= N; i++)
  {
    cin >> arr[i];
  }

  d[1] = arr[1];
  d[2] = arr[1] + arr[2];

  for (int i = 3; i <= N; i++)
  {
    d[i] = max(d[i - 3] + arr[i - 1] + arr[i], d[i - 2] + arr[i]);
  }

  cout << d[N];

  return 0;
}