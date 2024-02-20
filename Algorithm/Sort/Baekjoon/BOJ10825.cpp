#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#define X first
#define Y second
using namespace std;
int N, kor, eng, mat;
string name;
vector<pair<string, tuple<int, int, int>>> V;

bool compare(pair<string, tuple<int, int, int>> a, pair<string, tuple<int, int, int>> b)
{
  // 모든 점수가 같으면부터 거꾸로
  if (get<0>(a.Y) == get<0>(b.Y) && get<1>(a.Y) == get<1>(b.Y) && get<2>(a.Y) == get<2>(b.Y))
  {
    if (a.X < b.X)
      return 1;
    else
      return 0;
  }
  else if (get<0>(a.Y) == get<0>(b.Y) && get<1>(a.Y) == get<1>(b.Y))
  {
    if (get<2>(a.Y) > get<2>(b.Y))
      return 1;
    else
      return 0;
  }
  else if (get<0>(a.Y) == get<0>(b.Y))
  {
    if (get<1>(a.Y) < get<1>(b.Y))
      return 1;
    else
      return 0;
  }
  else
  {
    if (get<0>(a.Y) > get<0>(b.Y))
      return 1;
    else
      return 0;
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 1; i <= N; i++)
  {
    cin >> name >> kor >> eng >> mat;

    V.push_back({name, {kor, eng, mat}});
  }

  sort(V.begin(), V.end(), compare);

  for (int i = 0; i < N; i++)
  {
    cout << V[i].X << '\n';
  }

  return 0;
}