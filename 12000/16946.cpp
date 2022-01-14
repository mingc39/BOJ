#include <stdio.h>

// void s()�� 2667 ������ȣ���� ���� ����  
void s(int a[1000][1000], int x, int y, int m, int n, int v, int *cnt) {
	if(a[x][y] != 0) return;
	a[x][y] = v;
	*cnt = *cnt + 1;
	if(x < m - 1) s(a, x + 1, y, m, n, v, cnt);
	if(y < n - 1) s(a, x, y + 1, m, n, v, cnt);
	if(x > 0)     s(a, x - 1, y, m, n, v, cnt);
	if(y > 0)     s(a, x, y - 1, m, n, v, cnt);
}

int main() {
	int t, m, n, l = 2;
	int near[4];
	int a[1000][1000];
	int c[500002];
	
	// �Է� 
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf(" %c", &t);
			if(t == '0') a[i][j] = 0;
			else if(t == '1') a[i][j] = 1;
		}
	}
	
	// 0 ������(?)�� 0�� ���� �� �� �ִ��� �˾Ƴ���  
	// a[i][j]�� 0�̸� ������ ��ȣ(2���� ����)�� �ο��ǰ�
	// c[i]�� i��° ������(i >= 2)�� 0 ���� ����(c[0], c[1]�� 0) 
	c[0] = c[1] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == 0) {
				t = 0;
				s(a, i, j, n, m, l, &t);
				c[l++] = t;
			}
		}
	}
	
	// ����! 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			// ���� �ִ� ���  
			if(a[i][j] == 1) {
				// �����¿쿡 ������  ������ ��ȣ �˾����  
				near[0] = 1; near[1] = 1; near[2] = 1; near[3] = 1;
				if(i > 0)     near[0] = a[i - 1][j];
				if(j > 0)     near[1] = a[i][j - 1];
				if(i < n - 1) near[2] = a[i + 1][j];
				if(j < m - 1) near[3] = a[i][j + 1];
				// �ߺ��� ������ �ϳ��� ����� ����  
				for(int i = 0; i <= 2; i++) {
					for(int j = i + 1; j <= 3; j++) {
						if(near[i] == near[j]) near[j] = 1;
					}
				}
				// ������ �����̿� ���Ե� 0�� ���� + �� �μ��ڸ� �ڱ� �ڽ� ���  
				t = c[near[0]] + c[near[1]] + c[near[2]] + c[near[3]] + 1;
				printf("%d", t % 10);
			} else putchar('0');
		} putchar('\n');
	}
	
	return 0;
}
