#include <iostream>
using namespace std;

long long recursion(long long A, long long B, long long C)
{
  // base condition
  if (B == 1)
    return A % C;

  // recursive step
  long long val = recursion(A, B / 2, C);

  // 자기 자신을 호출했을 때, 각 함수마다 해야하는 일들을 밑에 적어주면 된다.
  val = val * val % C;
  if (B % 2 == 0)
    return val;
  return val * A % C;
}

int main(void)
{
  long long A, B, C;
  long long result;

  cin >> A >> B >> C;
  result = recursion(A, B, C);

  cout << result;

  return 0;
}