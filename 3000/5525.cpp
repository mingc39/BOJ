#include <stdio.h>

int main() {
	int n, m, c, t;
	char c1, c2, c3;
	scanf("%d %d", &n, &m);

	c1 = c2 = c3 = 0;
	for(t = c = 0; m > 0; m--) {
		scanf(" %c", &c1);
		if(c1 == 'I' && c2 == 'O' && c3 == 'I') {
			t++;
		} else if(c1 == 'O' && c2 == 'I' && c3 == 'O');
		else {
			if(t < n) t = 0;
			else t = t - n + 1;
			c += t;
			t = 0;
		}
		
		c3 = c2;
		c2 = c1;
	}
	if(t < n) t = 0;
	else t = t - n + 1;
	c += t;
	
	printf("%d", c);
	
	return 0;
}
