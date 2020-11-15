#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

long long A, B, C;

long find(int a, int b);

int main()
{
	scanf("%d %d %d", &A, &B, &C);
	printf("%d", find(A, B));
}

long find(int a, int b)
{
	if (b == 0)
		return 1;

	long n = find(a, b / 2);
	long tmp = n * n % C;

	if (b % 2 == 0)
		return tmp;
	else
		return a * tmp % C;
}