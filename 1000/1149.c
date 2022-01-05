#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int n, h[1000][3];

    // 입력
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &h[i][0], &h[i][1], &h[i][2]);

    // 한 줄씩 내려가면서 그 줄의 집을 각각 RGB로 칠하기 위한 최소 비용 계산 
    for (int i = 1; i < n; i++) {
        h[i][0] += h[i - 1][1] < h[i - 1][2] ? h[i - 1][1] : h[i - 1][2];
        h[i][1] += h[i - 1][0] < h[i - 1][2] ? h[i - 1][0] : h[i - 1][2];
        h[i][2] += h[i - 1][0] < h[i - 1][1] ? h[i - 1][0] : h[i - 1][1];
    }

    // 마지막 집을 칠하는 방법 중 전체 비용이 최소인 경우 출력
    if (h[n - 1][0] < h[n - 1][1] && h[n - 1][0] < h[n - 1][2]) printf("%d", h[n - 1][0]);
    else if (h[n - 1][1] < h[n - 1][2]) printf("%d", h[n - 1][1]);
    else printf("%d", h[n - 1][2]);

    return 0;
}
