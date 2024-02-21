#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, num;
vector<int> V;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> num;
    V.push_back(num);
  }

  sort(V.begin(), V.end());

  cout << V[(N - 1) / 2];
}