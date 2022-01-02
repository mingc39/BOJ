#include <stdio.h>

int main() {
	int t, p;
	int asc = 1, dsc = 1;
	
	scanf("%d", &p);
	for(int i = 1; i < 8; i++) {
		scanf("%d", &t);
		if(p <= t) dsc = 0;
		if(p >= t) asc = 0;
		p = t;
	}
	
	if(asc != 0) printf("ascending");
	else if(dsc != 0) printf("descending");
	else printf("mixed");
	
	return 0;
}
