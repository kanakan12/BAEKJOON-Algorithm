#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[100001];

long long find(int start, int end)
{
    if (start == end) return (long long)arr[start] * arr[end];

    int mid = (start + end) / 2;

    long long maxValue = max((long long)find(start, mid), (long long)find(mid + 1, end));

    int left = mid;
    int right = mid + 1;

    long long sum = arr[left] + arr[right];
    long long minValue = min(arr[left], arr[right]);

    maxValue = max(maxValue, sum * minValue);

    while (left > start || right < end)
    {
        if (right < end && (left == start || arr[left - 1] < arr[right + 1]))
        {
            sum += arr[++right];
            minValue = min(minValue, (long long)arr[right]);
        }
        else
        {
            sum += arr[--left];
            minValue = min(minValue, (long long)arr[left]);
        }

        maxValue = max(maxValue, (long long)sum * minValue);
    }

    return maxValue;
}

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);

    printf("%ld", (long long)find(1, N));
}
