#include<stdio.h> 

int main() {
	int n, r[501];
	int a[500][500]; // a[i][j] -> i���� j���� ���Ҷ��� �ּ� ���� Ƚ��  
	
	// �Է�  
	scanf("%d %d", &n, &r[0]);
	for(int i = 1; i < n; i++) scanf("%d %d", &r[i], &r[i]); // ��¥�� ��� ���� ���ƿ�  
	scanf("%d", &r[n]);
	//for(int i = 0; i <= n; i++) printf("%d ", r[i]); putchar('\n');
	
	for(int i = 0; i < n; i++) a[i][i] = 0;
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < n - i; j++) {
			a[j][i + j] = 2147483647;
			for(int k = j; k < i + j; k++) // ex) 1~4������ �ּ� ���� Ƚ���� 1(234), (12)(34) , (123)4 �߿� �ּ�  
				a[j][i + j] = a[j][i + j] < a[j][k] + r[j] * r[k + 1] * r[i + j + 1] + a[k + 1][i + j] ? a[j][i + j] : a[j][k] + r[j] * r[k + 1] * r[i + j + 1] + a[k + 1][i + j];
		}
	}
	/*
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i <= j) printf("%3d ", a[i][j]);
			else printf("%3d ", 0);
		}
		putchar('\n');
	}*/
	
	// ���  
	printf("%d", a[0][n - 1]);
	
	return 0;
}
