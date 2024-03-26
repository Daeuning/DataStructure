#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, num, cnt, max_num;
vector<int> V;

int main(void)
{
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> num;
    max_num = max(num, max_num);
    V.push_back(num);
  }

  for (int i = V.size() - 1; i >= 0; i--)
  {
    if (V[i] == max_num)
    {
      cnt++;
      max_num--;
    }
  }

  cout << N - cnt;

  return 0;
}