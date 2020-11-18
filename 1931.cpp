#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> vp;
int ans = 0;

bool compare(const pair<int, int>& a, const pair<int, int>& b);

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int fst, snd;
		scanf("%d %d", &fst, &snd);
		vp.push_back(make_pair(fst, snd));
	}

	sort(vp.begin(), vp.end(), compare);

	int val = 0;
	for (int i = 0; i < N; i++)
	{
		if (val <= vp[i].first)
		{
			val = vp[i].second;
			ans++;
		}
	}

	printf("%d", ans);
}

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}