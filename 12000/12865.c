#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k; // 물건 개수, 최대 무게 
    int *w, *v; // 물건별 무게, 물건별 가치 
    int** a;

    // 물건 개수, 최대 무게 입력 
    scanf("%d %d", &n, &k);

    // 동적 할당 
    w = (int*)malloc(sizeof(int) * (n + 1));
    v = (int*)malloc(sizeof(int) * (n + 1));
    a = (int**)malloc(sizeof(int*) * (n + 1));
    a[0] = (int*)calloc(k + 1, sizeof(int) * (n + 1));
    for (int i = 1; i <= n; i++) a[i] = a[i - 1] + (k + 1);

    // 물건별 무게, 가치 입력 
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &w[i], &v[i]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (w[i] > j) a[i][j] = a[i - 1][j];
            else a[i][j] = a[i - 1][j] > v[i] + a[i - 1][j - w[i]] ? a[i - 1][j] : v[i] + a[i - 1][j - w[i]];
        }
    }

    // 결과 출력 
    printf("%d", a[n][k]);

    return 0;
}