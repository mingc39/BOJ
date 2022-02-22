#include <stdio.h> 
#include <stdlib.h>

int g[100001][3];	// 간선 목록 
int p[10001];		// p로 오는 간선 정보 인덱스  
int l[10001];		// i번째 정점으로 오는 최대 시간  
int c[100000];		// i번째 간선의 도착지점으로 가는 최대 시간 경로 포함 여부  
int n, m;			// 정점, 간선 개수  
int s, e;			// 시작, 도착 정점 

int cmp(const void *a, const void *b) {
	return *((int*)a) - *((int*)b);
}

int d(int cur) {
	// 출발지점인 경우, 이미 탐색한 경우  
	if(cur == s || l[cur] > 0) return l[cur];
	
	// cur로 오는 모든 간선 확인  
	int i = p[cur];
	while(g[i][0] == cur) {
		// g[i]를 타고 오는 경우 중 가장 오래걸리는 시간 저장  
		int t = d(g[i][1]) + g[i][2];
		if(t > l[cur]) l[cur] = t;
		i++;
	}
	
	// cur까지 오는데 걸리는 최대 시간 반환  
	return l[cur];
}

void f(int cur) {
	// cur로 오는 모든 간선 확인  
	int i = p[cur];
	while(g[i][0] == cur) {
		// g[i]를 타고 올때 여유 시간이 없는 경우  
		if(l[g[i][1]] + g[i][2] == l[cur] && c[i] == 0) {
			c[i] = 1;	// 해당 간선에 표시 해두기  
			f(g[i][1]);	// 해당 간선의 시작 정점 탐색  
		}
		i++;
	}
}

int main() {
	// 입력 
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d", &g[i][1], &g[i][0], &g[i][2]);
	}
	qsort(g, m, sizeof(int) * 3, cmp);
	for(int i = 0; i < n; i++) p[i] = -1;
	for(int i = 0, prv = 0; i < m; i++) {
		if(g[i][0] != prv) {
			prv = g[i][0];
			p[prv] = i;
		}
	}
	scanf("%d %d", &s, &e);
	
	// 도착점에 도달하는 가장 오래걸리는 시간 출력  
	printf("%d", d(e));
	
	// 도착점에 도달하는 가장 오래걸리는 경로에 포함된 간선 수 세기  
	f(e);
	int cnt = 0;
	for(int i = 0; i < m; i++) cnt += c[i];
	// 도착점에 도달하는 가장 오래걸리는 경로에 포함된 간선 수 출력  
	printf("\n%d", cnt);
	
	return 0;
}
