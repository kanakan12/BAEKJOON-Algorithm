#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int arr[101];
int res[10001];
int N, K;

int main()
{
	scanf("%d %d", &N, &K);

	fill(res + 1, res + K + 1, 10001);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);

		for (int j = arr[i]; j <= K; j++)
			res[j] = min(res[j], res[j - arr[i]] + 1);
	}

	if (res[K] == 10001) res[K] = -1;

	printf("%d", res[K]);
}
