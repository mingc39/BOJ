#include <stdio.h>

int main() {
	
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	
	if(x < w - x && x < h - y && x < y) printf("%d", x);
	else if(y < w - x && y < h - y) printf("%d", y);
	else if(w - x < h - y) printf("%d", w - x);
	else printf("%d", h - y);
	
	return 0;
}
