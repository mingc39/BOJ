#include <stdio.h>
#include <stdlib.h>

#define INF 10000

int main() {
	int n, m, r;
	int i, j, k;
	int max, sum;
	int a, b, l;
	int f[100][100];
	int t[100];
	
	// �ʱ�ȭ  
	for(i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			f[i][j] = INF;
	for(i = 0; i < 100; i++)
		f[i][i] = 0;
	
	// �Է� �ޱ�  
	scanf("%d %d %d", &n, &m, &r);
	for(i = 0; i < n; i++) scanf("%d", &t[i]);
	for(i = 0; i < r; i++) {
		scanf("%d %d %d", &a, &b, &l);
		a--; b--;
		f[a][b] = l;
		f[b][a] = l;
	}
	
	// �÷��̵�-�ͼ�(1389������ ����) 
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++)
			for(k = 0; k < n; k++)
				if(f[j][k] > f[j][i] + f[i][k])
					f[j][k] = f[j][i] + f[i][k];
	}
	
	// �� ���� �� ���� �� �ִ� ������ ��� �� �ִ밪 ���ϱ�  
	max = 0;
	for(int i = 0; i < n; i++) {
		sum = 0;
		for(int j = 0; j < n; j++) {
			if(f[i][j] <= m) sum += t[j];
		}
		if(sum > max) max = sum;
	}
	
	// ��� 
	printf("%d", max);
	
	return 0;
}
