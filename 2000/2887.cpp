#include <stdio.h>
#include <stdlib.h>

// qsort 비교 함수  
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

int unionn(int a, int b, int* parent) { // union은 예약어라 unionn으로 했어요  
	return parent[find(b, parent)] = find(a, parent);
}
// ==================================

int main() {
	int **g, **p;
	int a, b, c;
	int v, e; // v: 정점, e: 간선  
	
	// 정점 개수 입력  
	scanf("%d", &v);
	
	// 행성 정보 배열 동적 할당  
	p = (int**)malloc(sizeof(int*) * v);
	p[0] = (int*)malloc(sizeof(int) * v * 4);
	for(int i = 1; i < v; i++) p[i] = p[i - 1] + 4;
	
	// 행성 입력 
	for(int i = 0; i < v; i++) {
		p[i][0] = i;
		scanf("%d %d %d", &p[i][1], &p[i][2], &p[i][3]);
	} 
	
	// 간선 정보 배열 동적 할당  
	e = v * 3 - 3;
	g = (int**)malloc(sizeof(int*) * e);
	g[0] = (int*)malloc(sizeof(int) * e * 3);
	for(int i = 1; i < e; i++) g[i] = g[i - 1] + 3;
	
	// 간선 입력  
	// x 축 상에 a, b, c 행성이 있는 경우 a-c는 이을 필요 없음 
	// x 축  
	qsort(p, v, sizeof(int*), cmp1);
	for(int i = 0; i < v - 1; i++) {
		g[i][0] = p[i + 1][1] - p[i][1];
		g[i][1] = p[i][0];
		g[i][2] = p[i + 1][0];
	} 
	// y 축  
	qsort(p, v, sizeof(int*), cmp2);
	for(int i = v - 1, j = 0; i < 2 * v - 2; i++, j++) {
		g[i][0] = p[j + 1][2] - p[j][2];
		g[i][1] = p[j][0];
		g[i][2] = p[j + 1][0];
	}
	// z 축  
	qsort(p, v, sizeof(int*), cmp3);
	for(int i = 2 * v - 2, j = 0; i < e; i++, j++) {
		g[i][0] = p[j + 1][3] - p[j][3];
		g[i][1] = p[j][0];
		g[i][2] = p[j + 1][0];
	}
	
	//for(int i = 0; i < e; i++) printf("%d: %d %d %d\n", i, g[i][0], g[i][1], g[i][2]);
	
	// 간선을 가중치 순으로 정렬  
	qsort(g, e, sizeof(int*), cmp);
	
	// 변수 초기화  
	int cnt = 0, weight = 0;
	int *parent = (int*)malloc(sizeof(int) * v);
	for(int i = 0; i < v; i++) parent[i] = i;
	
	// 크루스칼  
	for(int i = 0; i < e; i++) {
		if(cnt == v - 1) break; // 원래는 cnt == v - 1 이지만 가장 큰 간선은 제외해야 하므로 v - 2 
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
