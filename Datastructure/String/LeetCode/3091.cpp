#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1e9 + 10;

class Solution
{
public:
  int minOperations(int k)
  {
    int min_num = MAX;
    bool isupdate = 1;
    int div = 2;
    int res = 0;

    if (k == 1)
      return 0;

    while (isupdate)
    {
      if (k % div == 0)
      {
        int quo = k / div;
        res = (div - 1) + (quo - 1);
      }
      else
      {
        int quo = k / div;
        res = (div - 1) + quo;
      }

      if (res <= min_num)
      {
        min_num = res;
      }
      else
      {
        isupdate = 0;
      }

      div++;
    }

    return min_num;
  }
};