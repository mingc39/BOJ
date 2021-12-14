#include <stdio.h>

int main() {
	
	int n, w[50], h[50], c;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d %d", &w[i], &h[i]);
	
	for(int i = 0; i < n; i++) {
		c = 1;
		for(int j = 0; j < n; j++)
			if(w[i] < w[j] && h[i] < h[j])
				c++;
		printf("%d ", c);
	}	
	
	return 0;
}
