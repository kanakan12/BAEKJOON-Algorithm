#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[100000];

int find(int start, int end)
{
	if (start == end)
		return 0;

	if (start + 1 == end)
		return arr[start];

	int mid = (start + end) / 2;
	int maxvalue = max(find(start, mid), find(mid, end));

	int length = 1, height = arr[mid], left = mid, right = mid;
	
	while (left > start || right < end - 1)
	{
		int p = left > start ? min(height, arr[left - 1]) : -1;
		int q = right < end - 1 ? min(height, arr[right + 1]) : -1;

		if (p >= q) {
			height = p;
			left--;
		}
		else {
			height = q;
			right++;
		}

		length++;
		maxvalue = max(maxvalue, height * length);
	}

	return maxvalue;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	printf("%d", find(0, N));
}
