#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m;
	int i, j, k;
	int min, idx;
	int f[5000][5000];
	
	// 배열 할당하다가 뻑나면 위에 f 선언 지우고 바로 밑 주석 살리세요
	/*
	int **f;
	f = (int**)malloc(sizeof(int*) * 5000);
	for(i = 0; i < 5000; i++) f[i] = (int*)malloc(sizeof(int) * 5000);
	*/
	
	for(i = 0; i < 5000; i++)
		for(int j = 0; j < 5000; j++)
			f[i][j] = 10000;
	for(i = 0; i < 5000; i++)
		f[i][i] = 0;
	
	scanf("%d %d", &n, &m);
	
	for(i = 0; i < m; i++) {
		scanf("%d %d", &j, &k);
		f[j - 1][k - 1] = 1;
		f[k - 1][j - 1] = 1;
	}
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++)
			for(k = 0; k < n; k++)
				if(f[j][k] > f[j][i] + f[i][k])
					f[j][k] = f[j][i] + f[i][k];
	}
	
	min = 2147483647;
	for(i = 0; i < n; i++) {
		k = 0;
		for(j = 0; j < n; j++) k += f[i][j];
		if(min > k) {
			min = k;
			idx = i;
		}
	}
	
	printf("%d", idx + 1);
	
	return 0;
}
