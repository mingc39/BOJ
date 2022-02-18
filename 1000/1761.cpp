#include <stdio.h>
#include <stdlib.h>

// 정점 수, 간선 입력용, 간선 정보 시작 위치, 부모, 부모까지 비용, 깊이 
int n, a[80000][3], v[40001], p[40001][17], w[40001][17], d[40001];

// qsort용 크기비교  
int cmp(const void *x, const void *y) {
	return *((int*)x) - *((int*)y);
}

// 트리 만들기  
void tree(int root) {
	int i = v[root]; // root에 연결된 간선 정보 시작 위치  
	while(a[i][0] == root) { // root에 연결된 모든 정점 확인  
		if(p[a[i][1]][0] == 0 && a[i][1] != 1) { // 이미 트리에 포함된 정점(1이거나 부모가 있음)은 통과
			p[a[i][1]][0] = root;	  // 부모 노드를 root로 설정 
			w[a[i][1]][0] = a[i][2];  // 부모로 가는 비용 설정 
			d[a[i][1]] = d[root] + 1; // 해당 노드의 깊이 설정  
			tree(a[i][1]);			  // 해당 노드를 루트로 하는 하위 트리 생성  
		}
		i++;
	}
}

int main() {
	// 입력
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
	
	// 정렬
	qsort(a, 2 * (n - 1), sizeof(int) * 3, cmp);
	
	// 해당 정점 연결 시작 지점 저장  
	for(int i = 0, j = 0; i < 2 * (n - 1); i++) {
		if(a[i][0] != j) {
			j = a[i][0];
			v[j] = i;
		}
	}
	
	// 부모 찾기(노드 1이 루트)
	p[1][0] = 0;
	w[1][0] = 0;
	d[1]    = 1;
	tree(1);
	
	// 부모 노드 배열 채우기
	for(int i = 1; i <= 16; i++) {
		for(int j = 1; j <= n; j++) {
			p[j][i] = p[p[j][i - 1]][i - 1];
			w[j][i] = w[p[j][i - 1]][i - 1] + w[j][i - 1];
		}
	}
	
	// 질문 받기  
	int m;
	scanf("%d", &m);
	while(m--) {
		// 입력  
		int x, y, s = 0;
		scanf("%d %d", &x, &y);
		
		// 높이가 높은걸 앞으로 
		if(d[x] < d[y]) {
			int t;
			t = x;
			x = y;
			y = t;
		}
		
		// 높이 맞추기
		for(int i = 0, j = d[x] - d[y]; j > 0; i++, j /= 2) {
			if(j % 2) {
				s += w[x][i];
				x  = p[x][i];
			}
		}
		
		// 서로 같으면 그대로 출력
		if(x == y) {
			printf("%d\n", s);
			continue;
		}
		
		// 공통 조상 찾기 
		for(int i = 16; i >= 0; i--) {
			if(p[x][i] != p[y][i]) {
				s += w[x][i] + w[y][i];
				x  = p[x][i];
				y  = p[y][i];
			}
		}
		
		// 출력
		printf("%d\n", s + w[x][0] + w[y][0]);
	}
	
	return 0;
}
