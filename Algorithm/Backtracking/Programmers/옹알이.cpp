#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
string babble[4] = {"aya", "ye", "woo", "ma"};
bool isused[5];
int cnt;

bool babbleTrack(int sel, string arr)
{
  if (sel == arr.size())
  {
    return 1;
  }

  for (int i = 0; i < 4; i++)
  {
    if (!isused[i])
    {
      if (arr.substr(sel, babble[i].size()) == babble[i])
      {
        isused[i] = 1;
        if (babbleTrack(sel + babble[i].size(), arr))
          return 1;
        isused[i] = 0;
      }
    }
  }

  return 0;
}

int solution(vector<string> babbling)
{
  int answer = 0;

  for (int i = 0; i < babbling.size(); i++)
  {
    fill(isused, isused + 5, 0);
    if (babbleTrack(0, babbling[i]))
      answer++;
  }

  return answer;
}