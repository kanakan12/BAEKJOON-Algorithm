#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int L, W, H;
int N;
pair<int, int> p[20];
int ans = 0;
bool check = true;

// Case 1
int main()
{
	scanf("%d %d %d", &L, &W, &H);
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d %d", &p[i].first, &p[i].second);

	long before = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		before <<= 3;

		long possibleCube = (long)(L >> i) * (W >> i) * (H >> i) - before;
		long newCube = min((long)p[i].second, possibleCube);

		before += newCube;
		ans += newCube;
	}

	if (before == (long)L * W * H)
		printf("%d", ans);
	else
		printf("%d", -1);
}

// Caes 2
//void divide(int l, int w, int h, int idx);
//
//int main() 
//{
//	scanf("%d %d %d", &L, &W, &H);
//	scanf("%d", &N);
//
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%d %d", &p[N - 1 - i].first, &p[N - 1 - i].second);
//		p[N - 1 - i].first = pow(2, i);
//	}
//
//	divide(L, W, H, 0);
//
//	if (check) 
//		printf("%d", ans);
//	else 
//		printf("%d", -1);
//}
//
//void divide(int l, int w, int h, int idx)
//{
//	if (l == 0 || w == 0 || h == 0)
//		return;
//
//	for (int i = idx; i < N; i++)
//	{
//		if (p[i].second != 0 && l >= p[i].first && w >= p[i].first && h >= p[i].first)
//		{
//			p[i].second--;
//			ans++;
//			divide(l - p[i].first, w, h, i);
//			divide(p[i].first, w - p[i].first, h, i);
//			divide(p[i].first, p[i].first, h - p[i].first, i);
//			return;
//		}
//	}
//	check = false;
//}