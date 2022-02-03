#include <stdio.h>
#include <stdlib.h>

#define MEM 30

void tree(int* t, int root, int **a, int *l) {
	for(int i = 0; i < l[root]; i++) {
		if(a[root][i] != t[root]) {
			t[a[root][i]] = root;
			tree(t, a[root][i], a, l);
		}
	}
}

int f(int n, int **a, int *l, int *p, int e, int (*m)[2]) {
	// ���� ��� ����� ������ �װ� ���  
	if(m[n][e] >= 0) return m[n][e];
	
	int c = e;
	
	if(e == 0) { // ���� �� ����� �ƴ�  
		for(int i = 0; i < l[n]; i++) {
			if(a[n][i] == p[n]) continue; // �θ� ���� �ڽ� ��尡 �ƴϿ��� 
			c += f(a[n][i], a, l, p, 1, m);
		}
	} else { // ���� �� ����� 
		for(int i = 0; i < l[n]; i++) {
			if(a[n][i] == p[n]) continue; // �θ� ���� �ڽ� ��尡 �ƴϿ���
			int t1 = f(a[n][i], a, l, p, 1, m);
			int t0 = f(a[n][i], a, l, p, 0, m);
			c += t1 < t0 ? t1 : t0;
		}
	}
	
	return m[n][e] = c;
}

int main() {
	int n, u, v;
	int **a, *l, *s;
	
	// ���� �� �Է� �� �����Ҵ� 
	scanf("%d", &n);
	a = (int**)malloc(sizeof(int*) * n);
	l = (int*)malloc(sizeof(int) * n);
	s = (int*)malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++) {
		a[i] = NULL;
		s[i] = 0;
		l[i] = 0;
	}
	
	// �׷��� �Է�  
	for(int i = 0; i < n - 1; i++) {
		scanf("%d %d", &u, &v);
		u--; v--;
		
		if(l[u] == s[u]) {
			s[u] += MEM;
			a[u] = (int*)realloc(a[u], sizeof(int) * s[u]);
		}
		a[u][l[u]++] = v;
		
		if(l[v] == s[v]) {
			s[v] += MEM;
			a[v] = (int*)realloc(a[v], sizeof(int) * s[v]);
		}
		a[v][l[v]++] = u;
	}
	
	
	// Ʈ�� �����  
	int *p;
	p = (int*)malloc(sizeof(int) * n);
	p[0] = 0;
	tree(p, 0, a, l);
	
	// Ž��  
	int r, t, (*m)[2];
	m = (int(*)[2])malloc(sizeof(int) * 2 * n);
	for(int i = 0; i < n; i++) m[i][0] = m[i][1] = -1;
	r = f(0, a, l, p, 0, m); // ��Ʈ�� �� ����� �ƴ� 
	t = f(0, a, l, p, 1, m); // ��Ʈ�� �� �����  
	if(t < r) r = t; // �� �������� ����  
	
	// ���  
	printf("%d", r);
	
	return 0;
}
