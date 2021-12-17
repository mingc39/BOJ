#include <stdio.h>
#include <stdlib.h>

// qsort ���Լ�(������) 
int cmp(const void *a, const void *b) {
	return *((int*)a) - *((int*)b);
}

// 10026 ���ϻ��� �ڵ� ���� 
// 1012�� ����� ���� �ڵ� ����  
// �����¿� ����Լ��� Ž��
// ���� v�� ��� Ž�� �ƴϸ� ���� 
// �̹� Ž���� ���� ��湮 �ʿ� �����Ƿ� 0���� ����  
// �湮�� �� ���� cnt�� �����  
void s(int a[100][100], int x, int y, int m, int n, int v, int *cnt) {
	if(a[x][y] != v) return;
	a[x][y] = 0;
	*cnt = *cnt + 1;
	if(x < m - 1) s(a, x + 1, y, m, n, v, cnt);
	if(y < n - 1) s(a, x, y + 1, m, n, v, cnt);
	if(x > 0)     s(a, x - 1, y, m, n, v, cnt);
	if(y > 0)     s(a, x, y - 1, m, n, v, cnt);
}

int main() {
	int t, m, n;
	int a[100][100];
	int c[400];
	
	// �Է� �ޱ�  
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf(" %c", &t);
			if(t == '0') a[i][j] = 0;
			else if(t == '1') a[i][j] = 1;
		}
	}
	
	m = 0; // ������  
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] != 0) {
				t = 0; // ������ �� �� 
				s(a, i, j, n, n, a[i][j], &t);
				c[m] = t; // ������ �� ���� �迭�� ����  
				m++;
			}
		}
	}
	
	printf("%d", m); // ���� �� ��� 
	
	qsort(c, m, sizeof(int), cmp); // ������ �� �� ���� 
	
	for(int i = 0; i < m; i++) printf("\n%d", c[i]); // ������ �� �� ���  
	
	return 0;
}

