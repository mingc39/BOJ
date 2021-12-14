#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	
	int T, n;
	int *arr;
	int s, e, c;
	char f[100000];
	char *a;
	
	a = (char*) malloc(sizeof(char) * 10200000);
	
	scanf("%d", &T);
	
	while(T > 0) {
		
		scanf("%s", f);
		scanf("%d", &n);
		arr = (int*) calloc(n, sizeof(int));
		scanf("%s", a);
		c = 0;
		for(int i = 0; i < strlen(a); i++) {
			if(a[i] >= '0' && a[i] <= '9') {
				arr[c] = arr[c] * 10 + a[i] - '0';
				continue;
			}
			if(a[i] == ',') {
				c++;
				continue;
			}
			if(a[i] == ']') {
				break;
			}
		}
		
		
		s = 0; e = n - 1; c = 0;
		int empty = 0, direction = 1, error = 0;
		if(e < 0) empty = 1;
		if(e < s) direction = -1;
		while(c < strlen(f)) {
			if(f[c] != 'R' && f[c] != 'D') {
				c++;
				continue;
			}
			if(f[c] == 'R') {
				int t = s;
				s = e;
				e = t;
				direction *= -1;
				c++;
				continue;
			}
			if(f[c] == 'D') {
				if(empty == 1) {
					error = 1;
					break;
				}
				if(s == e) empty = 1;
				s += direction;
				c++;
				continue;
			}
			c++;
		}
		
		
		if(error == 1) {
			printf("error\n");
			T--;
			continue;
		}
		if(empty == 1) {
			printf("[]\n");
			T--;
			continue;
		}
		printf("[");
		for(int i = s; i * direction < e * direction; i += direction) {
			printf("%d,", arr[i]);
		}
		printf("%d]\n", arr[e]);
		
		free(arr);
		T--;
	}
	
}