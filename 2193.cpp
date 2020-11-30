//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//long long arr[91];
//
//int main()
//{
//	int N;
//	cin >> N;
//	
//	arr[1] = 1;
//	arr[2] = 1;
//	arr[3] = 2;
//
//	for (int i = 4; i <= N; i++)
//		arr[i] = arr[i - 1] + arr[i - 2];
//
//	cout << arr[N];
//}

#include<iostream>

using namespace std;

long long arr[91][2];

int main() 
{
    int N; 
    cin >> N;

    arr[1][0] = 0; 
    arr[1][1] = 1;

    for (int i = 2; i <= N; i++) 
    {
        arr[i][0] = arr[i - 1][0] + arr[i - 1][1];
        arr[i][1] = arr[i - 1][0];
    }

    cout << arr[N][0] + arr[N][1];
}