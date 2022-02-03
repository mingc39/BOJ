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
	// 이전 계산 결과가 있으면 그거 사용  
	if(m[n][e] >= 0) return m[n][e];
	
	int c = e;
	
	if(e == 0) { // 내가 얼리 어댑터 아님  
		for(int i = 0; i < l[n]; i++) {
			if(a[n][i] == p[n]) continue; // 부모 노드는 자식 노드가 아니에여 
			c += f(a[n][i], a, l, p, 1, m);
		}
	} else { // 내가 얼리 어댑터 
		for(int i = 0; i < l[n]; i++) {
			if(a[n][i] == p[n]) continue; // 부모 노드는 자식 노드가 아니에여
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
	
	// 정점 수 입력 및 동적할당 
	scanf("%d", &n);
	a = (int**)malloc(sizeof(int*) * n);
	l = (int*)malloc(sizeof(int) * n);
	s = (int*)malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++) {
		a[i] = NULL;
		s[i] = 0;
		l[i] = 0;
	}
	
	// 그래프 입력  
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
	
	
	// 트리 만들기  
	int *p;
	p = (int*)malloc(sizeof(int) * n);
	p[0] = 0;
	tree(p, 0, a, l);
	
	// 탐색  
	int r, t, (*m)[2];
	m = (int(*)[2])malloc(sizeof(int) * 2 * n);
	for(int i = 0; i < n; i++) m[i][0] = m[i][1] = -1;
	r = f(0, a, l, p, 0, m); // 루트가 얼리 어댑터 아님 
	t = f(0, a, l, p, 1, m); // 루트가 얼리 어댑터  
	if(t < r) r = t; // 더 작은값이 정답  
	
	// 출력  
	printf("%d", r);
	
	return 0;
}
