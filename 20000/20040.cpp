#include <stdio.h> 
#include <stdlib.h>

// ==========< find-union >==========
int find(int n, int* parent) {
	if(parent[n] == n) return n;
	else return parent[n] = find(parent[n], parent);
}

int unionn(int a, int b, int* parent) { // union은 예약어라 unionn으로 했어요  
	return parent[find(b, parent)] = find(a, parent);
}
// ==================================

int main() {
	int n, m, *p, a, b;
	
	scanf("%d %d", &n, &m);
	
	p = (int*)malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++) p[i] = i;
	
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if(find(a , p) == find(b , p)) {
			printf("%d", i + 1);
			return 0;
		}
		unionn(a, b, p);
	}
	printf("%d", 0);
	
	return 0;
}
