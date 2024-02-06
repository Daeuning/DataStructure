#include <iostream>
#include <algorithm>
using namespace std;
int isused[1000002];
int arr[1000002];
int N, S, cnt;

void numTrack(int sel, int tot)
{
  if (sel == N)
  {
    if (tot == S)
      cnt++;
    return;
  }

  numTrack(sel + 1, tot);
  numTrack(sel + 1, tot + arr[sel]);
}

int main(void)
{
  cin >> N >> S;

  for (int i = 0; i < N; i++)
  {
    cin >> arr[i];
  }

  numTrack(0, 0);

  if (S == 0)
    cnt--;

  cout << cnt;

  return 0;
}