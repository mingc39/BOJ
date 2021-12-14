#include <stdio.h>

int main() {
	int a, b[1000], m = 0;;
	double avg = 0;
	
	scanf("%d", &a);
	for(int i = 0; i < a; i++) {
		scanf("%d", &b[i]);
		if(b[i] > m) m = b[i];
	}
	
	for(int i = 0; i < a; i++) {
		avg += ((double)b[i]) / m * 100;
	}
	avg /= a;
	
	printf("%lf", avg);
	
	return 0;
}
