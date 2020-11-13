#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, r, c;
int ans = 0;

void find(int x, int y, int n)
{
	if (x == r && y == c)
	{
		printf("%d", ans);
		return;
	}

	if (x <= r && r < x + n && y <= c && c < y + n)
	{
		for (int i = x; i < x + n; i += n / 2)
		{
			for (int j = y; j < y + n; j += n / 2)
			{
				find(i, j, n / 2);
			}
		}
	}
	else
	{
		ans += n * n;
	}
}

int main()
{
	scanf("%d %d %d", &N, &r, &c);
	N = pow(2, N);
	
	find(0, 0, N);
}
