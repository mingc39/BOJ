#include <stdio.h>

int main() {
	int n, m, c[100];
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	
	int t, max = 0;
	for(int i = 0; i < n - 2; i++) {
		for(int j = i + 1; j < n - 1; j++) {
			for(int k = j + 1; k < n; k++) {
				t = c[i] + c[j] + c[k];
				if(t <= m && t > max) max = t;
			}
		}
	}
	
	printf("%d", max);
	
	return 0;
}
