#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int isused[13];
int arr[13];  // 숫자
int cal[6];   // 연산자 개수받기
char num[13]; // 경우의수 구하는 배열
int N;
long long res;
int min_res = 1000000000;
int max_res = -10000000000;
vector<char> Oper; // 전체 operator

void calTrack(int sel)
{
  if (sel == N - 1)
  {
    res = arr[0];

    for (int i = 0; i < N - 1; i++)
    {
      if (num[i] == '+')
      {
        res = res + arr[i + 1];
      }
      else if (num[i] == '-')
      {
        res = res - arr[i + 1];
      }
      else if (num[i] == '*')
      {
        res = res * arr[i + 1];
      }
      else
      {
        res = res / arr[i + 1];
      }
    }

    if (res < min_res)
      min_res = res;
    if (res > max_res)
      max_res = res;
  }

  for (int i = 0; i < N - 1; i++)
  {
    if (!isused[i])
    {
      num[sel] = Oper[i];
      isused[i] = 1;
      calTrack(sel + 1);
      isused[i] = 0;
    }
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> arr[i];
  }

  for (int i = 0; i < 4; i++)
  {
    cin >> cal[i];

    if (i == 0)
    {
      while (cal[i]--)
        Oper.push_back('+');
    }
    else if (i == 1)
    {
      while (cal[i]--)
        Oper.push_back('-');
    }
    else if (i == 2)
    {
      while (cal[i]--)
        Oper.push_back('*');
    }
    else if (i == 3)
    {
      while (cal[i]--)
        Oper.push_back('/');
    }
  }

  calTrack(0);

  cout << max_res << '\n';
  cout << min_res;

  return 0;
}