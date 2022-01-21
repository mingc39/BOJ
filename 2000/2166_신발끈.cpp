#include <stdio.h>

int main() {
	int n;
	double x[10000];
	double y[10000];
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%lf %lf", &x[i], &y[i]);
	
	double area = 0;
	for(int i = 0; i < n - 1; i++) {
		area += x[i] * y[i + 1] - x[i + 1] * y[i];
	}
	area += x[n - 1] * y[0] - x[0] * y[n - 1];
	area /= 2;
	area = area > 0 ? area : -area;
	
	printf("%.1lf", area);
	
	return 0;
}
