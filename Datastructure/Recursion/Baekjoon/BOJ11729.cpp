#include <iostream>
using namespace std;

void Hanoi(int from, int to, int N)
{
  // base condition : 원판이 하나 남았을 때, 1번에서 3번으로 한번 옮기기만 하면 된다.
  if (N == 1)
  {
    cout << from << ' ' << to << '\n';
    return;
  }

  // N-1개의 원판을 1 -> 2로
  Hanoi(from, 6 - from - to, N - 1);
  // N번째 원판(1개)를 1 -> 3로
  cout << from << ' ' << to << '\n';
  // N-1개의 원판을 2 ->3 으로
  Hanoi(6 - from - to, to, N - 1);
}

int main(void)
{
  // N-1개의 원판을 1 -> 2 로
  // N번째 원판(1개)를 1 -> 3 으로
  // N-1개의 원판을 2 -> 3 으로 옮기는 과정을 반복
  int N, K, result;

  cin >> N;

  cout << (1 << N) - 1 << '\n';

  Hanoi(1, 3, N);

  return 0;
}