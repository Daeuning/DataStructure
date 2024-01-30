#include <iostream>
#include <algorithm>
using namespace std;
int D[100002];
int N, M, I, J, num, sum;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		sum += num;
		D[i] = sum;
		// cin >> a[i];
		// d[i] = d[i - 1] + a[i]
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> I >> J;
		cout << D[J] - D[I - 1] << '\n';
	}

	return 0;
}