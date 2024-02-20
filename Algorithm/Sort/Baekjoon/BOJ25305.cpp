#include <iostream>
#include <algorithm>
using namespace std;
int N, k;
int arr[1002];

bool compare(int i, int j)
{
  return j < i;
}

int main(void)
{
  cin >> N >> k;

  for (int i = 1; i <= N; i++)
  {
    cin >> arr[i];
  }

  sort(arr + 1, arr + N + 1, compare);

  cout << arr[k];

  return 0;
}