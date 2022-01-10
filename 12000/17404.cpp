#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int n, m = 99999999, h[3][1000][3];

    // 입력
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	scanf("%d %d %d", &h[0][i][0], &h[0][i][1], &h[0][i][2]);
    	h[1][i][0] = h[0][i][0]; h[2][i][0] = h[0][i][0];
    	h[1][i][1] = h[0][i][1]; h[2][i][1] = h[0][i][1];
    	h[1][i][2] = h[0][i][2]; h[2][i][2] = h[0][i][2];
	}
    
    // 첫번째 집이 j인 경우  
	for(int j = 0; j < 3; j++) {
		// 두번째 집 최소 비용   
		for(int k = 0; k < 3; k++) {
			h[j][1][k] += k == j ? 99999999 : h[j][0][j];
		}
		
		// 한 줄씩 내려가면서 그 줄의 집을 각각 RGB로 칠하기 위한 최소 비용 계산 
    	for (int i = 2; i < n; i++) {
        	h[j][i][0] += h[j][i - 1][1] < h[j][i - 1][2] ? h[j][i - 1][1] : h[j][i - 1][2];
        	h[j][i][1] += h[j][i - 1][0] < h[j][i - 1][2] ? h[j][i - 1][0] : h[j][i - 1][2];
        	h[j][i][2] += h[j][i - 1][0] < h[j][i - 1][1] ? h[j][i - 1][0] : h[j][i - 1][1];
		}
	}

    // 마지막 집을 칠하는 방법 중 전체 비용이 최소인 경우 출력
    for(int i = 0; i < 3; i++) {
    	for(int j = 0; j < 3; j++) {
    		if(i != j && m > h[i][n - 1][j]) m = h[i][n - 1][j];
		}
	}
    printf("%d", m);

    return 0;
}
