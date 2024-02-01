#include <iostream>
#include <algorithm>
using namespace std;

int T, N, M;
int D[10002];
int coin[10002];

int main(void) {
	cin >> T;

	while (T--)
	{
		fill(D, D + 10002, 0);

		cin >> N;

		for (int i = 1; i <= N; i++)
		{
			cin >> coin[i];
		}

		cin >> M;

		D[0] = 1;

		for (int i = 1; i <= N; i++)
		{
			for (int j = coin[i]; j <= M; j++)
			{
				D[j] += D[j - coin[i]];
			}
		}

		cout << D[M] << '\n';
	}

	return 0;
}