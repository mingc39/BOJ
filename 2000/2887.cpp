#include <stdio.h>
#include <stdlib.h>

// qsort �� �Լ�  
int cmp(const void* a, const void* b) {
	return (*((int**)a))[0] - (*((int**)b))[0];
}

int cmp1(const void* a, const void* b) {
	return (*((int**)a))[1] - (*((int**)b))[1];
}

int cmp2(const void* a, const void* b) {
	return (*((int**)a))[2] - (*((int**)b))[2];
}

int cmp3(const void* a, const void* b) {
	return (*((int**)a))[3] - (*((int**)b))[3];
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
	int **g, **p;
	int a, b, c;
	int v, e; // v: ����, e: ����  
	
	// ���� ���� �Է�  
	scanf("%d", &v);
	
	// �༺ ���� �迭 ���� �Ҵ�  
	p = (int**)malloc(sizeof(int*) * v);
	p[0] = (int*)malloc(sizeof(int) * v * 4);
	for(int i = 1; i < v; i++) p[i] = p[i - 1] + 4;
	
	// �༺ �Է� 
	for(int i = 0; i < v; i++) {
		p[i][0] = i;
		scanf("%d %d %d", &p[i][1], &p[i][2], &p[i][3]);
	} 
	
	// ���� ���� �迭 ���� �Ҵ�  
	e = v * 3 - 3;
	g = (int**)malloc(sizeof(int*) * e);
	g[0] = (int*)malloc(sizeof(int) * e * 3);
	for(int i = 1; i < e; i++) g[i] = g[i - 1] + 3;
	
	// ���� �Է�  
	// x �� �� a, b, c �༺�� �ִ� ��� a-c�� ���� �ʿ� ���� 
	// x ��  
	qsort(p, v, sizeof(int*), cmp1);
	for(int i = 0; i < v - 1; i++) {
		g[i][0] = p[i + 1][1] - p[i][1];
		g[i][1] = p[i][0];
		g[i][2] = p[i + 1][0];
	} 
	// y ��  
	qsort(p, v, sizeof(int*), cmp2);
	for(int i = v - 1, j = 0; i < 2 * v - 2; i++, j++) {
		g[i][0] = p[j + 1][2] - p[j][2];
		g[i][1] = p[j][0];
		g[i][2] = p[j + 1][0];
	}
	// z ��  
	qsort(p, v, sizeof(int*), cmp3);
	for(int i = 2 * v - 2, j = 0; i < e; i++, j++) {
		g[i][0] = p[j + 1][3] - p[j][3];
		g[i][1] = p[j][0];
		g[i][2] = p[j + 1][0];
	}
	
	//for(int i = 0; i < e; i++) printf("%d: %d %d %d\n", i, g[i][0], g[i][1], g[i][2]);
	
	// ������ ����ġ ������ ����  
	qsort(g, e, sizeof(int*), cmp);
	
	// ���� �ʱ�ȭ  
	int cnt = 0, weight = 0;
	int *parent = (int*)malloc(sizeof(int) * v);
	for(int i = 0; i < v; i++) parent[i] = i;
	
	// ũ�罺Į  
	for(int i = 0; i < e; i++) {
		if(cnt == v - 1) break; // ������ cnt == v - 1 ������ ���� ū ������ �����ؾ� �ϹǷ� v - 2 
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
