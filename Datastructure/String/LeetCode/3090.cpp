#include <iostream>
#include <algorithm>
using namespace std;
int arr[28];
int max_num;

class Solution
{
public:
  int maximumLengthSubstring(string s)
  {
    memset(arr, 0, sizeof(arr));
    max_num = 0;
    int st = 0;
    int ed = 0;

    for (int i = 0; i < s.length(); i++)
    {
      arr[s[i] - 'a']++;
      ed = i;

      if (arr[s[i] - 'a'] <= 2)
      {
        max_num = max(max_num, ed - st + 1);
      }
      else
      {
        while (arr[s[i] - 'a'] > 2)
        {
          arr[s[st] - 'a']--;
          st++;
        }
      }
    }

    return max_num;
  }
};