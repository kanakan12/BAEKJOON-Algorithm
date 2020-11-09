# define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int N, S;
int arr[20];
int ans = 0;

int find(int idx, int length, int sum, int cnt);

int main()
{
	scanf("%d %d", &N, &S);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i <= N; i++)
		find(0, i, 0, 0);

	printf("%d", ans);
}

int find(int idx, int length, int sum, int cnt)
{
	if (cnt == length)
	{
		if (sum == S)
			ans++;
		return 0;
	}

	for (int i = idx; i < N; i++)
	{
		sum += arr[i];
		find(i + 1, length, sum, cnt + 1);
		sum -= arr[i];
	}

	return 0;
}