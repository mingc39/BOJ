#include <stdio.h>
#include <stdlib.h>

// qsort �� �Լ�  
int cmp(const void* a, const void* b) {
	return *((int**)a)[0] - *((int**)b)[0];
}

// ==========< find-union >==========
int find(int n, int* parent) {
	if(parent[n] == n) return n;
	else return parent[n] = find(parent[n], parent);
}

int unionn(int a, int b, int* parent) { // union�� ������ unionn���� �߾��  
	return parent[find(b, parent)] = find(a, parent);
}
// ==================================

int main() {
	int **g;
	int a, b, c;
	int v, e; // v: ����, e: ����  
	
	// ����, ���� ���� �Է� �� �����Ҵ�  
	scanf("%d %d", &v, &e);
	g = (int**)malloc(sizeof(int*) * e);
	g[0] = (int*)malloc(sizeof(int) * e * 3);
	for(int i = 1; i < e; i++) g[i] = g[i - 1] + 3;
	
	// ���� �Է�  
	for(int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		g[i][0] = c;
		g[i][1] = a - 1;
		g[i][2] = b - 1;
	}
	
	// ������ ����ġ ������ ����  
	qsort(g, e, sizeof(int*), cmp);
	
	// ���� �ʱ�ȭ  
	int cnt = 0, weight = 0;
	int *parent = (int*)malloc(sizeof(int) * v);
	for(int i = 0; i < v; i++) parent[i] = i;
	
	// ũ�罺Į  
	for(int i = 0; i < e; i++) {
		if(cnt == v - 2) break; // ������ cnt == v - 1 ������ ���� ū ������ �����ؾ� �ϹǷ� v - 2 
		if(find(g[i][1], parent) != find(g[i][2], parent)) {
			unionn(g[i][1], g[i][2], parent);
			weight += g[i][0];
			cnt++;
		}
	}
	
	// ��� ���  
	printf("%d", weight);
	
	return 0;
}
