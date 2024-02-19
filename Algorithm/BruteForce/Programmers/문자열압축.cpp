#include <string>
#include <algorithm>
#include <vector>

using namespace std;
string tmp;
int cnt;

int pressureTrack(int num, string s)
{
  int cpr = s.length() / num;
  int rest = s.length() - (num * cpr);
  cnt = 1;
  string cur = s.substr(0, num);
  string res = "";

  for (int i = num; i < num * cpr; i += num)
  {
    tmp = s.substr(i, num);

    if (tmp == cur)
    {
      cnt++;
    }
    else
    {
      if (cnt > 1)
        res += to_string(cnt);
      res += cur;
      cur = tmp;
      cnt = 1;
    }
  }

  if (cnt > 1)
    res += to_string(cnt);
  res += s.substr(num * (cpr - 1), rest + num);

  return res.length();
}

int solution(string s)
{
  int answer = s.length();

  for (int i = 1; i <= s.length(); i++)
  {
    answer = min(answer, pressureTrack(i, s));
  }

  return answer;
}