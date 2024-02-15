#include <iostream>
#include <algorithm>
using namespace std;
int L, C, cnt_vow, cnt_con;
int isused[20];
char alpha[20];
char arr[20];

void alphaTrack(int sel, int idx)
{
  if (sel == L)
  {
    cnt_vow = 0;
    cnt_con = 0;

    for (int i = 0; i < L; i++)
    {
      if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
        cnt_vow++;
      else
        cnt_con++;
    }

    if (cnt_vow < 1 || cnt_con < 2)
    {
      return;
    }
    else
    {
      for (int i = 0; i < L; i++)
      {
        cout << arr[i];
      }
      cout << '\n';
      return;
    }
  }

  for (int i = idx; i < C; i++)
  {
    if (!isused[i])
    {
      isused[i] = 1;
      arr[sel] = alpha[i];
      alphaTrack(sel + 1, i + 1);
      isused[i] = 0;
      ;
    }
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> L >> C;

  for (int i = 0; i < C; i++)
  {
    cin >> alpha[i];
  }

  sort(alpha, alpha + C);

  alphaTrack(0, 0);

  return 0;
}