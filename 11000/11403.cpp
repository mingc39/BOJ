#include <stdio.h>
#include <stdlib.h>

#define INF 10000

int main() {
	int n, m;
	int i, j, k;
	int min, idx;
	int f[100][100];
	
	// �ʱ�ȭ  
	for(i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			f[i][j] = INF;
	
	// �Է� �ޱ�  
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			scanf("%d", &k);
			if(k > 0) f[i][j] = k; // ���� �ִ� �׷����̹Ƿ� (j,i)�� �� �ʿ� ����!  
		}
	
	// �÷��̵�-�ͼ�(1389������ ����) 
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++)
			for(k = 0; k < n; k++)
				if(f[j][k] > f[j][i] + f[i][k])
					f[j][k] = f[j][i] + f[i][k];
	}
	
	// ��� 
	for(i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			printf("%d ", f[i][j] < INF ? 1 : 0); // ��� ���̰� �ƴ� ��� ���� ���θ� ����ؾ���  
		putchar('\n');
	}
	
	return 0;
}
