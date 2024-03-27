#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define X first
#define Y second
long long arr[100002];

class Solution
{
public:
  vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq)
  {
    fill(arr, arr + 100002, 0);
    vector<long long> res;
    long long max_num = 0;
    priority_queue<pair<long long, long long>> PQ;

    for (int i = 0; i < freq.size(); i++)
    {
      if (freq[i] > 0)
      {
        arr[nums[i]] += freq[i];
        PQ.push({arr[nums[i]], nums[i]});
      }
      else
      {
        arr[nums[i]] -= abs(freq[i]);
        PQ.push({arr[nums[i]], nums[i]});
      }

      while (1)
      {
        if (arr[PQ.top().Y] == PQ.top().X)
        {
          res.push_back(PQ.top().X);
          break;
        }
        else
        {
          PQ.pop();
        }
      }
    }

    return res;
  }
};