#include <stdio.h>

int main() {
	int n;
	double x0, xp, y0, yp, xc, yc, area = 0;
	
	scanf("%d", &n);
	scanf("%lf %lf", &x0, &y0);
	xp = x0; yp = y0;
	for(int i = 1; i < n; i++) {
		scanf("%lf %lf", &xc, &yc);
		area += xp * yc - yp * xc;
		xp = xc; yp = yc;
	}
	area += xp * y0 - yp * x0;
	
	printf("%.1lf", area < 0 ? -area / 2 : area / 2);
	
	return 0;
}
