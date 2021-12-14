#include <stdio.h>
#include <string.h>

int main() {
	int m, n, i;
	char str[24];
	int l, c[30];
	char t[30][24];
	
	for(scanf("%d", &m); m > 0; m--) {
		l = 0;
		for(scanf("%d", &n); n > 0; n--) {
			scanf("%s", str);
			scanf("%s", str);
			for(i = 0; i < l; i++)
				if(strcmp(t[i], str) == 0) {
					c[i]++;
					break;
				}
			if(i == l) {
				strcpy(t[l], str);
				c[l] = 2;
				l++;
			}
		}
		for(i = 1, l--; l >= 0; l--) i *= c[l];
		printf("%d\n", i - 1);
	}
	
	return 0;
}
