#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int tab[100] = { 0 };
bool use[101] = { false };

int main() 
{
    int N, K;
    int arr[100];
    int cnt = 0;
    int full_check_cnt = 0;

    scanf("%d %d", &N, &K);

    for (int i = 0; i < K; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < K; i++) 
    {
        if (full_check_cnt < N) 
        {
            if (!use[arr[i]])
            {
                tab[full_check_cnt++] = arr[i];
                use[arr[i]] = true;
            }
        }
        else 
        {
            if (!use[arr[i]]) 
            {
                int last_idx = 0;
                int change_idx = 0;
                for (int j = 0; j < N; j++) 
                {
                    int tmp_idx = -1;
                    for (int z = i + 1; z < K; z++) 
                    {
                        if (tab[j] == arr[z]) 
                        {
                            tmp_idx = z;
                            break;
                        }
                    }

                    if (tmp_idx < 0) 
                    {
                        change_idx = j;
                        break;
                    }
                    else 
                    {
                        if (last_idx < tmp_idx) 
                        {
                            last_idx = tmp_idx;
                            change_idx = j;
                        }
                    }
                }

                use[tab[change_idx]] = false;
                cnt++;
                tab[change_idx] = arr[i];
                use[tab[change_idx]] = true;
            }
        }
    }

    printf("%d", cnt);
}