#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

char arr[50][50];

int find(int x, int y);

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%s", &arr[i]);

	int ans = 0;
	int Min = 8 * 8;
	for (int i = 0; i + 8 <= N; i++)
	{
		for (int j = 0; j + 8 <= M; j++)
		{
			ans = find(i, j);
			Min = min(ans, Min);
		}
	}

	printf("%d", Min);
}

int find(int x, int y)
{
	char tmp = arr[x][y];
	int n = (x + y) % 2;
	int ans = 0;

	for (int i = x; i < x + 8; i++)
	{
		for (int j = y; j < y + 8; j++)
		{
			if ((i + j) % 2 == n)
			{
				if (arr[i][j] != tmp)
					ans++;
			}
			else
			{
				if (arr[i][j] == tmp)
					ans++;
			}
		}
	}
	
	return min(ans, 8 * 8 - ans);
}