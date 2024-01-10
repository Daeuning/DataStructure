#include <iostream>
using namespace std;

int recursion(int n, int r, int c)
{
  // base condition : n==0 즉 1칸짜리는 무조건 0
  if (n == 0)
    return 0;
  // 한변 길이의 절반 계산
  int half = 1 << (n - 1);
  // recursion step : 사분면 구하기
  if (r < half && c < half)
    return recursion(n - 1, r, c);
  if (r < half && c >= half)
    return half * half + recursion(n - 1, r, c - half);
  if (r >= half && c < half)
    return 2 * half * half + recursion(n - 1, r - half, c);
  return 3 * half * half + recursion(n - 1, r - half, c - half);
}

int main(void)
{
  // 몇번째 사분면인지를 찾은 뒤, 지나온 칸들을 더해주면 된다.
  int N, r, c;

  cin >> N >> r >> c;

  cout << recursion(N, r, c);

  return 0;
}