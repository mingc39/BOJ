#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// qsort 비교 함수  
int cmp(const void* a, const void* b) {
	return *((double**)a)[0] - *((double**)b)[0];
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
	double **g;
	int a, b, c;
	double x, y;
	double starCord[101][2];
	int v, e; // v: 정점, e: 간선  
	
	// 정점, 간선 개수 입력 및 동적할당  
	scanf("%d", &v);
	e = v * (v - 1) / 2;
	g = (double**)malloc(sizeof(double*) * e);
	g[0] = (double*)malloc(sizeof(double) * e * 3);
	for(int i = 1; i < e; i++) g[i] = g[i - 1] + 3;
	
	for(int i = 0, k = 0; i < v; i++) {
		scanf("%lf %lf", &x, &y);
		starCord[i][0] = x;
		starCord[i][1] = y;
		
		// 입력 내용 저장 
		for(int j = 0; j < i; j++) {
			g[k][0] = sqrt(pow(x - starCord[j][0], 2) + pow(y - starCord[j][1], 2));
			g[k][1] = i;
			g[k][2] = j;
			k++;
		}
	}
	
	// 간선을 가중치 순으로 정렬  
	qsort(g, e, sizeof(double*), cmp);
	
	// 변수 초기화  
	int cnt = 0;
	double weight = 0;
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
	printf("%lf", weight);
	
	return 0;
}
