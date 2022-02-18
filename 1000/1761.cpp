#include <stdio.h>
#include <stdlib.h>

// ���� ��, ���� �Է¿�, ���� ���� ���� ��ġ, �θ�, �θ���� ���, ���� 
int n, a[80000][3], v[40001], p[40001][17], w[40001][17], d[40001];

// qsort�� ũ���  
int cmp(const void *x, const void *y) {
	return *((int*)x) - *((int*)y);
}

// Ʈ�� �����  
void tree(int root) {
	int i = v[root]; // root�� ����� ���� ���� ���� ��ġ  
	while(a[i][0] == root) { // root�� ����� ��� ���� Ȯ��  
		if(p[a[i][1]][0] == 0 && a[i][1] != 1) { // �̹� Ʈ���� ���Ե� ����(1�̰ų� �θ� ����)�� ���
			p[a[i][1]][0] = root;	  // �θ� ��带 root�� ���� 
			w[a[i][1]][0] = a[i][2];  // �θ�� ���� ��� ���� 
			d[a[i][1]] = d[root] + 1; // �ش� ����� ���� ����  
			tree(a[i][1]);			  // �ش� ��带 ��Ʈ�� �ϴ� ���� Ʈ�� ����  
		}
		i++;
	}
}

int main() {
	// �Է�
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++) {
		int t0, t1, t2;
		scanf("%d %d %d", &t0, &t1, &t2);
		a[2 * i    ][0] = t0;
		a[2 * i    ][1] = t1;
		a[2 * i    ][2] = t2;
		a[2 * i + 1][0] = t1;
		a[2 * i + 1][1] = t0;
		a[2 * i + 1][2] = t2;
	}
	
	// ����
	qsort(a, 2 * (n - 1), sizeof(int) * 3, cmp);
	
	// �ش� ���� ���� ���� ���� ����  
	for(int i = 0, j = 0; i < 2 * (n - 1); i++) {
		if(a[i][0] != j) {
			j = a[i][0];
			v[j] = i;
		}
	}
	
	// �θ� ã��(��� 1�� ��Ʈ)
	p[1][0] = 0;
	w[1][0] = 0;
	d[1]    = 1;
	tree(1);
	
	// �θ� ��� �迭 ä���
	for(int i = 1; i <= 16; i++) {
		for(int j = 1; j <= n; j++) {
			p[j][i] = p[p[j][i - 1]][i - 1];
			w[j][i] = w[p[j][i - 1]][i - 1] + w[j][i - 1];
		}
	}
	
	// ���� �ޱ�  
	int m;
	scanf("%d", &m);
	while(m--) {
		// �Է�  
		int x, y, s = 0;
		scanf("%d %d", &x, &y);
		
		// ���̰� ������ ������ 
		if(d[x] < d[y]) {
			int t;
			t = x;
			x = y;
			y = t;
		}
		
		// ���� ���߱�
		for(int i = 0, j = d[x] - d[y]; j > 0; i++, j /= 2) {
			if(j % 2) {
				s += w[x][i];
				x  = p[x][i];
			}
		}
		
		// ���� ������ �״�� ���
		if(x == y) {
			printf("%d\n", s);
			continue;
		}
		
		// ���� ���� ã�� 
		for(int i = 16; i >= 0; i--) {
			if(p[x][i] != p[y][i]) {
				s += w[x][i] + w[y][i];
				x  = p[x][i];
				y  = p[y][i];
			}
		}
		
		// ���
		printf("%d\n", s + w[x][0] + w[y][0]);
	}
	
	return 0;
}
