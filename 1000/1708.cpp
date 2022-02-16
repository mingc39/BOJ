#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n, x[100000], y[100000], a[100000];
int p, s[100000];

long long ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	return (long long) (x2 - x1) * (y3 - y1) - (long long) (x3 - x1) * (y2 - y1);
}

long long dist(int x1, int y1, int x2, int y2) {
	return (long long) (x1 - x2) * (x1 - x2) + (long long) (y1 - y2) * (y1 - y2);
}

int cmp(const void *p1, const void *p2) {
	int t1 = *((int*)p1);
	int t2 = *((int*)p2);
	
	long long c = ccw(x[a[0]], y[a[0]], x[t1], y[t1], x[t2], y[t2]);
	if(c > 0) return -1;
	if(c < 0) return 1;
	
	if(dist(x[a[0]], y[a[0]], x[t1], y[t1]) > dist(x[a[0]], y[a[0]], x[t2], y[t2])) return 1;
	return -1;
}


int main() {
	// 입력  
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	
	// 시작점 잡기
	a[0] = 0;
	for(int i = 1; i < n; i++) {
		if(y[i] < y[a[0]] || y[i] == y[a[0]] && x[i] < x[a[0]]) a[0] = i;
	}
	
	for(int i = 0; i < a[0]; i++) a[i + 1] = i;
	for(int i = a[0] + 1; i < n; i++) a[i] = i; 
	
	// 정렬  
	qsort(a + 1, n - 1, sizeof(int), cmp);
	
	// 그레이엄 스캔 
	p = 0;
	s[p++] = a[0];
	s[p++] = a[1];
	int next = 2;
	while(next < n) {
		if(ccw(x[s[p - 2]], y[s[p - 2]], x[s[p - 1]], y[s[p - 1]], x[a[next]], y[a[next]]) > 0) {
			s[p++] = a[next];
			next++;
		} else if(p == 2) {
			s[p - 1] = a[next];
			next++;
		} else {
			p--;
		}
	}
	
	// 출력  
	printf("%d", p);
	
	return 0;
}
