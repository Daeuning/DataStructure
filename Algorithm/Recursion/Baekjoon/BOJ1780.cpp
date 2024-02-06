#include <iostream>
using namespace std;
int board[2500][2500];
int paper[4];

bool isPaper(int S, int firstx, int firsty, int num)
{
  for (int i = firstx; i <= firstx + S - 1; i++)
  {
    for (int j = firsty; j <= firsty + S - 1; j++)
    {
      if (board[i][j] != num)
        return 0;
    }
  }
  return 1;
}

void recursion(int S, int firstx, int firsty)
{
  int num = board[firstx][firsty];

  // base condition : 한변의 길이가 1일 경우
  if (S == 1)
  {
    paper[num + 1]++;
    return;
  }

  // recursion step
  if (isPaper(S, firstx, firsty, num))
  {
    paper[num + 1]++;
    return;
  }
  else
  {
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        // 한변길이 주고, 각 첫번째 점 주기
        recursion(S / 3, firstx + (S / 3 * i), firsty + (S / 3 * j));
      }
    }
  }
}

int main(void)
{
  int N;
  cin >> N;

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      cin >> board[i][j];
    }
  }

  // 변의 길이, 왼쪽 모서리 시작점
  recursion(N, 1, 1);

  for (int i = 0; i < 3; i++)
  {
    cout << paper[i] << '\n';
  }

  return 0;
}