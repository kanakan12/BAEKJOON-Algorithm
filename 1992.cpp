#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int N;
char arr[65][65];

void find(int x, int y, int n)
{
	char val = arr[x][y];
	bool check = false;
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (arr[i][j] != val)
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
		cout << "(";
		for (int i = x; i < x + n; i += n / 2)
		{
			for (int j = y; j < y + n; j += n / 2)
				find(i, j, n / 2);
		}
		cout << ")";
	}
	else
	{
		if (val == '0')
			cout << "0";
		else
			cout << "1";
	}
}

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	find(0, 0, N);
}
