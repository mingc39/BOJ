#include <stdio.h>

int main() {
	int i, n, s;
	char c;
	
	for(scanf("%d ", &i); i > 0; i--) {
		s = 0; n = 1;
		while((c = getchar()) != '\n') {
			if(c == 'O') s += n++;
			if(c == 'X') n = 1;
		}
		printf("%d\n", s);
	}
	
	return 0;
}
