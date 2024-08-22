#include <iostream>
#include <algorithm>
using namespace std;
int D[1002];
int arr[1002];
int N;

int main(void)
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	D[1] = arr[1];

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			D[i] = max(D[i], D[i - j] + arr[j]);
		}
	}

	cout << D[N];

	return 0;
}