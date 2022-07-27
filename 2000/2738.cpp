#include <stdio.h>

int main() {
	int N, M, t;
	int a[100][100];
	
	scanf("%d %d", &N, &M);
	
	// 첫번째 행렬 입력 
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	// 두번째 행렬 입력 및 해당 원소의 합 출력  
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			scanf("%d", &t);
			printf("%d ", t + a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
