#include <iostream>
using namespace std;
int N, M;
int arr[10];
bool isused[10];

void func(int k)
{
  // base condition : M개를 모두 선택해 수열이 완성되었음
  if (k == M)
  {
    for (int i = 0; i < M; i++)
    {
      cout << arr[i] << ' ';
    }

    cout << '\n';

    return;
  }

  for (int i = 1; i <= N; i++)
  {
    // 만약 이미 선택한 숫자면 continue
    if (isused[i] == true)
      continue;
    // 선택하지 않은 숫자일 경우, 수열에 저장하고 isused 표시한뒤 다음거 찾기
    arr[k] = i;
    isused[i] = true;
    func(k + 1);
    // k번째 수를 i로 정한 모든 경우를 다 확인했으니 i를 사용하지 않았다고 명시
    isused[i] = false;
  }
}

int main(void)
{
  cin >> N >> M;

  func(0);

  return 0;
}