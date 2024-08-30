#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[1002];
int D[1002];

int main(void)
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		D[i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = i - 1; j >= 1; j--)
		{
			if (arr[j] < arr[i]) D[i] = max(D[i], D[j] + 1);
		}
	}

	cout << *max_element(D, D + N + 1);

	return 0;
}