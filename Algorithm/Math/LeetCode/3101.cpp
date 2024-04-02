class Solution
{
public:
  long long countAlternatingSubarrays(vector<int> &nums)
  {
    long long accu = 0;
    long long res = 0;
    long long cur = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
      if (cur != nums[i])
        accu++;
      else
        accu = 0;

      res += accu;
      cur = nums[i];
    }

    return res + nums.size();
  }
};