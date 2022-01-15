#include <stdio.h> 

typedef struct line{
	int x1, y1;
	int x2, y2;
} line;

int main() {
	line l1, l2;
	
	scanf("%d %d %d %d", &l1.x1, &l1.y1, &l1.x2, &l1.y2);
	scanf("%d %d %d %d", &l2.x1, &l2.y1, &l2.x2, &l2.y2);
	
	long long a, b, c, d;
	a = (long long) (l1.x2 - l1.x1) * (l2.y1 - l1.y1) - (long long) (l2.x1 - l1.x1) * (l1.y2 - l1.y1);
	b = (long long) (l1.x2 - l1.x1) * (l2.y2 - l1.y1) - (long long) (l2.x2 - l1.x1) * (l1.y2 - l1.y1);
	c = (long long) (l2.x2 - l2.x1) * (l1.y1 - l2.y1) - (long long) (l1.x1 - l2.x1) * (l2.y2 - l2.y1);
	d = (long long) (l2.x2 - l2.x1) * (l1.y2 - l2.y1) - (long long) (l1.x2 - l2.x1) * (l2.y2 - l2.y1);
	
	if(a > 0 && b > 0 || a < 0 && b < 0) putchar('0'); // 선분2가 직선1의 한쪽에 있는 경우
	else if(c > 0 && d > 0 || c < 0 && d < 0) putchar('0'); // 선분1이 직선2의 한쪽에 있는 경우  
	else putchar('1');
	
	return 0;
}
