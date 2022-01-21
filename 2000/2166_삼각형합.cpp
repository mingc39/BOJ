#include <stdio.h>

int main() {
	int n;
	double x0, xp, y0, yp, xc, yc, area = 0;
	
	scanf("%d", &n);
	scanf("%lf %lf", &x0, &y0);
	scanf("%lf %lf", &xp, &yp);
	for(int i = 2; i < n; i++) {
		scanf("%lf %lf", &xc, &yc);
		area += ((x0 * yp + xp * yc + xc * y0) - (y0 * xp + yp * xc + yc * x0)) / 2;
		xp = xc; yp = yc;
	}
	
	printf("%.1lf", area < 0 ? -area : area);
	
	return 0;
}
