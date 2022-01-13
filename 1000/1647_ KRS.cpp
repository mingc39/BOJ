#include <stdio.h>
#include <stdlib.h>

// qsort 비교 함수  
int cmp(const void* a, const void* b) {
	return *((int**)a)[0] - *((int**)b)[0];
}

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
	int **g;
	int a, b, c;
	int v, e; // v: 정점, e: 간선  
	
	// 정점, 간선 개수 입력 및 동적할당  
	scanf("%d %d", &v, &e);
	g = (int**)malloc(sizeof(int*) * e);
	g[0] = (int*)malloc(sizeof(int) * e * 3);
	for(int i = 1; i < e; i++) g[i] = g[i - 1] + 3;
	
	// 간선 입력  
	for(int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		g[i][0] = c;
		g[i][1] = a - 1;
		g[i][2] = b - 1;
	}
	
	// 간선을 가중치 순으로 정렬  
	qsort(g, e, sizeof(int*), cmp);
	
	// 변수 초기화  
	int cnt = 0, weight = 0;
	int *parent = (int*)malloc(sizeof(int) * v);
	for(int i = 0; i < v; i++) parent[i] = i;
	
	// 크루스칼  
	for(int i = 0; i < e; i++) {
		if(cnt == v - 2) break; // 원래는 cnt == v - 1 이지만 가장 큰 간선은 제외해야 하므로 v - 2 
		if(find(g[i][1], parent) != find(g[i][2], parent)) {
			unionn(g[i][1], g[i][2], parent);
			weight += g[i][0];
			cnt++;
		}
	}
	
	// 결과 출력  
	printf("%d", weight);
	
	return 0;
}
