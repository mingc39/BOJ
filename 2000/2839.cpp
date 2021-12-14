#include <stdio.h>

int main() {
	// ¼³ÅÁ ºÀÁö Á¾·ù: 3kg, 5kg;
	int n, r;
	scanf("%d", &n);
	r = n / 5;
	switch(n % 5) {
		case 0:
			break;
		case 1:
			if(r < 1) r = -1;
			else r += 1;
			break;
		case 2:
			if(r < 2) r = -1;
			else r += 2;
			break;
		case 3:
			r += 1;
			break;
		case 4:
			if(r < 1) r = -1;
			else r += 2;
			break;
	}
	printf("%d", r);
	return 0;
}
