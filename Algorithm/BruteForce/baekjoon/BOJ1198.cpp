#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define X first
#define Y second
using namespace std;
int N;
double max_num, numx, numy, a, b, c, d, res;
vector<pair<int, int>> V;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> numx >> numy;
    V.push_back({numx, numy});
  }

  for (int i = 0; i < N - 2; i++)
  {
    for (int j = i + 1; j < N - 1; j++)
    {
      for (int k = j + 1; k < N; k++)
      {
        a = V[k].Y - V[j].Y;
        b = V[j].X - V[k].X;
        c = (V[j].X * (V[j].Y - V[k].Y)) + (V[j].Y * (V[k].X - V[j].X));
        d = (abs(a * V[i].X + b * V[i].Y + c) / sqrt(a * a + b * b));

        res = sqrt(pow(V[j].X - V[k].X, 2) + pow(V[j].Y - V[k].Y, 2)) * d;
        max_num = max(max_num, res);
      }
    }
  }

  cout << fixed;
  cout.precision(1);

  cout << max_num / 2;

  return 0;
}