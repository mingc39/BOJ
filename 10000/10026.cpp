#include <stdio.h>

// 1012�� ����� ���� �ڵ� ����  
// �����¿� ����Լ��� Ž��
// ���� v�� ��� Ž�� �ƴϸ� ���� 
// �̹� Ž���� ���� ��湮 �ʿ� �����Ƿ� 0���� ����  
void s(int a[100][100], int x, int y, int m, int n, int v) {
	if(a[x][y] != v) return;
	a[x][y] = 0;
	if(x < m - 1) s(a, x + 1, y, m, n, v);
	if(y < n - 1) s(a, x, y + 1, m, n, v);
	if(x > 0)     s(a, x - 1, y, m, n, v);
	if(y > 0)     s(a, x, y - 1, m, n, v);
}

int main() {
	int t, m, n, k;
	int a[100][100]; // �����ο�  
	int b[100][100]; // �����ڿ�  
	
	// �Է� �ޱ�  
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf(" %c", &t);
			switch(t) {
			case 'R':
				a[i][j] = 1;
				b[i][j] = 1;
				break;
			case 'G':
				a[i][j] = 2;
				b[i][j] = 1;
				break;
			case 'B':
				a[i][j] = 3;
				b[i][j] = 3;
				break;
			}
		}
	}
	
	m = 0; k = 0; // ������ ������; ������ ������; 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] != 0) {
				s(a, i, j, n, n, a[i][j]);
				m++;
			}
			if(b[i][j] != 0) {
				s(b, i, j, n, n, b[i][j]);
				k++;
			}
		}
	}
	
	// ��� 
	printf("%d %d", m, k);
	
	return 0;
}

