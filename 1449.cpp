#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int N, L;
int arr[1001];
int ans;

int main()
{
	scanf("%d %d", &N, &L);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + N);

	int idx = 0;
	int cur;
	while (idx != N)
	{
		cur = arr[idx] + L;

		while (cur > arr[idx] && idx < N)
			idx++;

		ans++;
	}

	printf("%d", ans);
}