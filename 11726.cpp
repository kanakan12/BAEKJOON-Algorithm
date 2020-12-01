#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

int main()
{
	int N;
	scanf("%d", &N);

	if (N == 1 || N == 2) printf("%d", N);
	else
	{
		int a = 1, b = 2, c;
		for (int i = 0; i < N - 2; i++)
		{
			c = (a + b) % 10007;
			a = b;
			b = c;
		}
		printf("%d", c);
	}
}
