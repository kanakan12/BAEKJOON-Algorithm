#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[2188][2188];
int a = 0, b = 0, c = 0;

void find(int x, int y, int n)
{
	int val = arr[x][y];
	bool check = false;
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (val != arr[i][j])
			{
				check = true;
				break;
			}
		}

		if (check)
			break;
	}

	if (check)
	{
		for (int i = x; i < x + n; i += n / 3)
		{
			for (int j = y; j < y + n; j += n / 3)
				find(i, j, n / 3);
		}
	}
	else
	{
		if (val == -1)
			a++;
		else if (val == 0)
			b++;
		else
			c++;
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	find(0, 0, N);

	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
}
