class Solution
{
public:
  int maxBottlesDrunk(int numBottles, int numExchange)
  {
    int emptyBottle = 0;
    int drunkBottle = 0;

    while (1)
    {
      if (numBottles == 0 && (emptyBottle < numExchange))
        break;

      if (emptyBottle == 0 || (emptyBottle < numExchange))
      {
        drunkBottle += numBottles;
        emptyBottle += numBottles;
        numBottles = 0;
      }
      else if (emptyBottle >= numExchange)
      {
        numBottles++;
        emptyBottle -= numExchange;
        numExchange++;
      }
    }

    return drunkBottle;
  }
};