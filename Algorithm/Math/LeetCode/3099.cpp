#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int num, res, digit;

class Solution
{
public:
  int sumOfTheDigitsOfHarshadNumber(int x)
  {
    vector<int> V;
    digit = 0;
    num = x;

    while (num != 0)
    {
      res = num % 10;
      V.push_back(res);
      num = num / 10;
    }

    for (int i = 0; i < V.size(); i++)
    {
      digit += V[i];
    }

    if (x % digit == 0)
      return digit;
    else
      return -1;
  }
};