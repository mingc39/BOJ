#include <stdio.h> 

typedef struct line{
	int x1, y1;
	int x2, y2;
} line;

int main() {
	line l1, l2;
	int cross = -1; 
	
	scanf("%d %d %d %d", &l1.x1, &l1.y1, &l1.x2, &l1.y2);
	scanf("%d %d %d %d", &l2.x1, &l2.y1, &l2.x2, &l2.y2);
	
	long long a, b, c, d;
	a = (long long) (l1.x2 - l1.x1) * (l2.y1 - l1.y1) - (long long) (l2.x1 - l1.x1) * (l1.y2 - l1.y1);
	b = (long long) (l1.x2 - l1.x1) * (l2.y2 - l1.y1) - (long long) (l2.x2 - l1.x1) * (l1.y2 - l1.y1);
	c = (long long) (l2.x2 - l2.x1) * (l1.y1 - l2.y1) - (long long) (l1.x1 - l2.x1) * (l2.y2 - l2.y1);
	d = (long long) (l2.x2 - l2.x1) * (l1.y2 - l2.y1) - (long long) (l1.x2 - l2.x1) * (l2.y2 - l2.y1);
	
	if(a > 0 && b > 0 || a < 0 && b < 0) cross = 0; // 선분2가 직선1의 한쪽에 있는 경우
	else if(c > 0 && d > 0 || c < 0 && d < 0) cross = 0; // 선분1이 직선2의 한쪽에 있는 경우  
	else if(a == 0 && b == 0 && c == 0 && d == 0) { // 두 선분이 같은 직선 위인 경우   
		if(l1.x1 == l1.x2 && l1.x2 == l2.x1 && l2.x1 == l2.x2) { // y축 평행 
			// 안만나는 경우  
			if(l1.y1 > l2.y1 && l1.y1 > l2.y2 && l1.y2 > l2.y1 && l1.y2 > l2.y2) cross = 0;
			else if(l2.y1 > l1.y1 && l2.y1 > l1.y2 && l2.y2 > l1.y1 && l2.y2 > l1.y2) cross = 0;
			// 같은 직선위의 두 선분이 한 점에서 만나는 경우 
			else if(l1.y1 == l2.y1 && (l1.y2 < l1.y1 && l2.y1 < l2.y2 || l1.y2 > l1.y1 && l2.y1 > l2.y2)) cross = 2;
			else if(l1.y1 == l2.y2 && (l1.y2 < l1.y1 && l2.y2 < l2.y1 || l1.y2 > l1.y1 && l2.y2 > l2.y1)) cross = 2;
			else if(l1.y2 == l2.y1 && (l1.y1 < l1.y2 && l2.y1 < l2.y2 || l1.y1 > l1.y2 && l2.y1 > l2.y2)) cross = 3;
			else if(l1.y2 == l2.y2 && (l1.y1 < l1.y2 && l2.y2 < l2.y1 || l1.y1 > l1.y2 && l2.y2 > l2.y1)) cross = 3;
			// 한 점을 초과하는 범위로 겹치는 경우  
			else cross = 1;
		} else { // x축 평행, 대각선  
			// 안만나는 경우  
			if(l1.x1 > l2.x1 && l1.x1 > l2.x2 && l1.x2 > l2.x1 && l1.x2 > l2.x2) cross = 0;
			else if(l2.x1 > l1.x1 && l2.x1 > l1.x2 && l2.x2 > l1.x1 && l2.x2 > l1.x2) cross = 0;
			// 같은 직선위의 두 선분이 한 점에서 만나는 경우
			else if(l1.x1 == l2.x1 && (l1.x2 < l1.x1 && l2.x1 < l2.x2 || l1.x2 > l1.x1 && l2.x1 > l2.x2)) cross = 2;
			else if(l1.x1 == l2.x2 && (l1.x2 < l1.x1 && l2.x2 < l2.x1 || l1.x2 > l1.x1 && l2.x2 > l2.x1)) cross = 2;
			else if(l1.x2 == l2.x1 && (l1.x1 < l1.x2 && l2.x1 < l2.x2 || l1.x1 > l1.x2 && l2.x1 > l2.x2)) cross = 3;
			else if(l1.x2 == l2.x2 && (l1.x1 < l1.x2 && l2.x2 < l2.x1 || l1.x1 > l1.x2 && l2.x2 > l2.x1)) cross = 3;
			// 한 점을 초과하는 범위로 겹치는 경우 
			else cross = 1;
		}
	} else cross = 4;
	
	if(cross == 0) putchar('0'); // 안 만나는 경우  
	else if(cross == 1) putchar('1'); // 한 점을 초과하는 범위에서 겹치는 경우  
	else if(cross == 2) printf("1\n%d %d", l1.x1, l1.y1); // (x1, y1)에서 만나는 경우  
	else if(cross == 3) printf("1\n%d %d", l1.x2, l1.y2); // (x2, y2)에서 만나는 경우  
	else { // 그 외 한 점에서 만나는 경우  
		double x, y;
		x = (((double) l1.x1 * l1.y2 - (double) l1.y1 * l1.x2) * (l2.x1 - l2.x2) - ((double) l2.x1 * l2.y2 - (double) l2.y1 * l2.x2) * (l1.x1 - l1.x2)) / 
			((double) (l1.x1 - l1.x2) * (l2.y1 - l2.y2) - (double) (l2.x1 - l2.x2) * (l1.y1 - l1.y2));
		y = (((double) l1.x1 * l1.y2 - (double) l1.y1 * l1.x2) * (l2.y1 - l2.y2) - ((double) l2.x1 * l2.y2 - (double) l2.y1 * l2.x2) * (l1.y1 - l1.y2)) / 
			((double) (l1.x1 - l1.x2) * (l2.y1 - l2.y2) - (double) (l2.x1 - l2.x2) * (l1.y1 - l1.y2));
		printf("1\n%.10lf %.10lf", x, y);
	}
	return 0;
}
