#include <stdio.h>

int main() {
	int N, M, t;
	int a[100][100];
	
	scanf("%d %d", &N, &M);
	
	// ù��° ��� �Է� 
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	// �ι�° ��� �Է� �� �ش� ������ �� ���  
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			scanf("%d", &t);
			printf("%d ", t + a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
