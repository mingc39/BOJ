#include <stdio.h>

int main() {
	int t;
	int n, m;
	int k, a[50];
	
	scanf("%d %d", &n, &m);
	scanf("%d", &k);
	for(int i = 0; i < k; i++) {
		scanf("%d", &t);
		a[i] = t - 1;
	}
	
	if(k == 0) {
		printf("%d", m);
		return 0;
	}
	
	int p[50][50] = {0,}, pn[50];
	for(int i = 0; i < m; i++) {
		scanf("%d", &pn[i]);
		for(int j = 0; j < pn[i]; j++) {
			scanf("%d", &t);
			p[i][t - 1] = 1;
		}
	}
	
	int v[50] = {0,}, pt[50] = {0,};
	int posIn = k, posOut = 0;
	for(int i = 0; i < k; i++) v[a[i]] = 1;
	while(posIn != posOut) {
		t = a[posOut++];
		for(int i = 0; i < m; i++) {
			if(pt[i] != 0) continue;
			if(p[i][t] != 0) {
				pt[i] = 1;
				for(int j = 0; j < n; j++) {
					if(p[i][j] != 0 && v[j] == 0) {
						a[posIn++] = j;
						v[j] = 1;
					} 
				}
			}
		}
	}
	
	//for(int i = 0; i < m; i++) printf("%2d: %d\n", i + 1, !pt[i]);
	t = 0;
	for(int i = 0; i < m; i++) t += !pt[i];
	printf("%d", t);
	
	return 0;
}
