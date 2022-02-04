#include <stdio.h>
#include <stdlib.h>

#define PQSIZE 100000

int n, p[100000][2];

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
	return ((int*)a)[1] - ((int*)b)[1];
}

int main() {
	int d, r = 0;
	
	// 입력 받기  
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &p[i][0], &p[i][1]);
		if(p[i][0] > p[i][1]) { // 작은 점을 시작지점으로  
			d = p[i][0];
			p[i][0] = p[i][1];
			p[i][1] = d;
		}
	}
	scanf("%d", &d);
	
	// 끝 지점 기준으로 정렬  
	qsort(p, n, sizeof(int) * 2, cmp);
	
	// 순서대로 우선순위 큐에 넣고 개수 확인하기  
	for(int i = 0; i < n; i++) {
		// 우선순위 큐에 이번 사람 넣기  
		push(p[i][0]); 
		// 시작 지점이 선분 d 안에 없는 사람 빼기 
		while(l > 0) {
			if(a[0] < p[i][1] - d) pop();
			else break;
		}
		// 우선순위 큐의 최대값 갱신
		if(r < l) r = l; 
	}
	
	// 출력
	printf("%d", r) ;
	
	return 0;
}
