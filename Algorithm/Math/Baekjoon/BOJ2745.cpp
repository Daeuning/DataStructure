#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int B, res, cnt, num;
string N;

int main(void)
{
  cin >> N >> B;

  for (int i = N.length() - 1; i >= 0; i--)
  {
    if (N[i] >= 48 && N[i] <= 57)
      num = N[i] - '0';
    if (N[i] >= 65 && N[i] <= 90)
      num = N[i] - 55;

    res += pow(B, cnt) * num;
    cnt++;
  }

  cout << res;

  return 0;
}