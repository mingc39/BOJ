#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m, *w;
	scanf("%d %d", &n, &m);
	w = (int*)malloc(sizeof(int) * n);
	int max = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
		if(max < w[i]) max = w[i];
	}
	
	long long s;
	int st, md, ed;
	st = 0; md = 0; ed = max;
	while(st != md || ed != md) {
		md = (st + ed + 1) / 2;
		
		// 절단기 높이 md에서 얻는 나무 길이 
		s = 0;
		for(int i = 0; i < n; i++) {
			if(w[i] - md > 0) s += w[i] - md;
		}
		
		// 얻을 수 있으면 
		if(s >= m) {
			st = md; 
		} else {
			ed = md - 1;
		}
	}
	
	printf("%d", md);
	
	return 0;
}
