#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

/*
최소힙을 사용한 우선순위 큐
define PQSIZE로 크기 설정
*/
#define PQSIZE 1048576

// ========< 우선순위 큐 >======== 
long long a[PQSIZE];
int l = 0;

long long pop() {
	long long tmp = a[0];
	a[0] = a[--l];
	// 힙 갱신
	long long t;
	int t1, t2, i = 0;
	while(i < l) {
		// 자식 노드 인덱스 계산 
		t1 = 2 * i + 1;
		t2 = 2 * i + 2;
		if(t1 >= l) break;
		if(t2 >= l) { // 왼쪽 노드만 있는 경우 
			if(a[t1] < a[i]) {
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			} 
		} else { // 둘 다 있는 경우 
			if(a[t1] < a[i] && a[t1] <= a[t2]) {
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			}
			if(a[t2] < a[i] && a[t2] < a[t1]) {
				t = a[t2];
				a[t2] = a[i];
				a[i] = t;
				i = t2;
				continue;
			}
		}
		// 더 작은 자식 노드 없으면 갱신 완료
		break; 
	}
	return tmp;
}

long long push(long long x) {
	a[l++] = x;
	// 힙 갱신 
	long long t;
	int t1, i = l - 1;
	while(i > 0) {
		// 부모 노드 인덱스 계산
		t1 = (i - 1) / 2;
		// 부모 노드 비교
		if(t1 >= 0) {
			if(a[t1] > a[i]) {
				t = a[t1];
				a[t1] = a[i];
				a[i] = t;
				i = t1;
				continue;
			}
		}
		// 부모 노드가 더 작으면 갱신 완료
		break; 
	}
	return x;
}
// =============================== 

int cmp(const void *a, const void *b) {
	return *((int*)a) - *((int*)b);
}

int m, n;
int src, dst;
int g[10000][4];
int v[10000];
int d[10000];
int p[500][500];
int c[500];
int q[10000];
int ql, qr;

// 다익스트라  
int dij() {
	// 초기화  
	for(int i = 0; i < n; i++) d[i] = INF;	// 최소 경로 길이 배열 초기화  
	d[src] = 0;								// 출발지의 최소 경로 길이 0으로 초기화  
	l = 0;									// 큐 초기화  
	push(0 * 1000 + src);					// 시작지점 큐 삽입  
	p[src][0] = 0;							// 출발지 부모 초기화
	
	// 큐가 빌 때까지 반복  
	while(l > 0) {
		// 최소값 pop 
		int curLoc = a[0] % 1000;
		int curCst = a[0] / 1000;
		pop();
		
		// 현위치에서 갈 수 있는 정점 업데이트  
		int i = v[curLoc];
		while(g[i][0] == curLoc) {
			// 사용할 수 없는 간선이면 건너뛰기  
			if(g[i][3] != 0) {
				i++;
				continue;
			}
			
			// 다음 정점, 거리 구하기  
			int nxtLoc = g[i][1];			// 다음 정점 구하기  
			int nxtCst = curCst + g[i][2];	// 다음 정점 거리 구하기  
			if(nxtCst > INF) nxtCst = INF;	// 거리가 INF 넘어가면 INF로 변경(int 범위 초과 방지) 
			
			// 다음 정점 업데이트  
			// 기존 거리보다 더 짧으면 업데이트  
			if(nxtCst < d[nxtLoc]) {
				d[nxtLoc] = nxtCst;				// 업데이트 된 거리 저장 
				p[nxtLoc][0] = 1;				// 최단 거리로 올 수 있는 간선 개수 초기화  
				p[nxtLoc][1] = i;				// 최단 거리로 올 수 있는 간선 저장  
				push(nxtCst * 1000 + nxtLoc);	// 큐에 다음 정점 삽입 
			}
			// 기존 거리와 같으면 최단 거리로 올 수 있는 간선만 업데이트 
			if(nxtCst == d[nxtLoc])  {
				p[nxtLoc][0]++;					// 최단 거리로 올 수 있는 간선 개수 증가   
				p[nxtLoc][p[nxtLoc][0]] = i;	// 최단 거리로 올 수 있는 간선 저장  
			}
			
			i++;
		}
	}
	
	return d[dst];
}


void rsp_BFS(void);
void rsp_DFS(int);
// 최단경로에 포함된 모든 간선 제거 
void rsp() {
	int BFS = 0; // DFS로 탐색시 0, BFS로 탐색시 1 
	
	int DFS = !BFS;
	if(BFS == 1) rsp_BFS();
	if(DFS == 1) {
		for(int i = 0; i < n; i++) c[i] = 0;
		c[src] = 1;
		rsp_DFS(dst);
	}
}
 
void rsp_BFS() {
	// 정점 방문 배열 초기화  
	for(int i = 0; i < n; i++) c[i] = 0;	// 들어오는 간선 비활성화 완료 여부 초기화  
	c[src] = 1;								// 시작지점 간선 비활성화 완료로 처리  
	
	// 큐 초기화  
	ql = qr = 0;							// 큐 초기화  
	q[qr++] = dst;							// 도착지 삽입  
	if(qr == 10000) qr = 0;					// 큐 오른쪽 끝 위치 범위 초과시 0으로 되돌리기  
	
	// 최단거리에 포함된 간선 탐색 및 비활성화  
	while(ql != qr) {
		// 큐에서 꺼내기  
		int cur = q[ql++];
		if(ql == 10000) ql = 0;
		
		// 이미 방문한 경우 통과  
		if(c[cur] != 0) continue;
		
		// 해당 정점으로 들어오는 간선은 비활성화, 정점은 탐색  
		c[cur] = 1; // 방문 체크  
		for(int i = 1; i <= p[cur][0]; i++) {
			g[p[cur][i]][3] = 1;		// 간선 비활성화  
			q[qr++] = g[p[cur][i]][0];	// 정점 큐에 삽입  
			if(qr == 10000) qr = 0;
		}
	}
}

void rsp_DFS(int cur) {
	// 시작점이거나 이미 방문한 정점이면 통과  
	if(cur == src || c[cur] != 0) return;
	
	// 해당 정점으로 들어오는 간선은 비활성화, 정점은 탐색  
	c[cur] = 1;
	for(int i = 1; i <= p[cur][0]; i++) {
		g[p[cur][i]][3] = 1;		// 간선 비활성화  
		rsp_DFS(g[p[cur][i]][0]);	// 정점 큐에 삽입
	}
}

int main() {
	// 처음 n, m 입력  
	scanf("%d %d", &n, &m);
	while(n != 0 || m != 0) {
		// 출발점, 도착점 입력 
		scanf("%d %d", &src, &dst);
		// 간선 정보 입력  
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &g[i][0], &g[i][1], &g[i][2]);
			g[i][3] = 0;
		}
		qsort(g, m, sizeof(int) * 4, cmp);
		for(int i = 0, prv = -1; i < m; i++) {
			if(g[i][0] != prv) {
				prv = g[i][0];
				v[g[i][0]] = i;
			}
		}
		
		// 거의 최단 거리 구하기
		dij();				// 진짜 최단 거리 구하기  
		rsp();				// 진짜 최단 거리에 포함된 간선 비활성화  
		int npl = dij(); 	// 거의 최단 거리 구하기  
		
		// 결과 출력  
		if(npl >= INF) printf("-1\n");	// 거의 최단 경로가 없는 경우 -1 출력 
		else printf("%d\n", npl);		// 거의 최단 경로가 있는 경우 거의 최단 경로 출력  
		
		// 다음 n, m 입력  
		scanf("%d %d", &n, &m);
	}
	
	return 0;
}
