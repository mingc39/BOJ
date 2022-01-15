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
	
	if(a > 0 && b > 0 || a < 0 && b < 0) cross = 0; // ����2�� ����1�� ���ʿ� �ִ� ���
	else if(c > 0 && d > 0 || c < 0 && d < 0) cross = 0; // ����1�� ����2�� ���ʿ� �ִ� ���  
	else if(a == 0 && b == 0 && c == 0 && d == 0) { // �� ������ ���� ���� ���� ���   
		if(l1.x1 == l1.x2 && l1.x2 == l2.x1 && l2.x1 == l2.x2) { // y�� ���� 
			// �ȸ����� ���  
			if(l1.y1 > l2.y1 && l1.y1 > l2.y2 && l1.y2 > l2.y1 && l1.y2 > l2.y2) cross = 0;
			else if(l2.y1 > l1.y1 && l2.y1 > l1.y2 && l2.y2 > l1.y1 && l2.y2 > l1.y2) cross = 0;
			// ���� �������� �� ������ �� ������ ������ ��� 
			else if(l1.y1 == l2.y1 && (l1.y2 < l1.y1 && l2.y1 < l2.y2 || l1.y2 > l1.y1 && l2.y1 > l2.y2)) cross = 2;
			else if(l1.y1 == l2.y2 && (l1.y2 < l1.y1 && l2.y2 < l2.y1 || l1.y2 > l1.y1 && l2.y2 > l2.y1)) cross = 2;
			else if(l1.y2 == l2.y1 && (l1.y1 < l1.y2 && l2.y1 < l2.y2 || l1.y1 > l1.y2 && l2.y1 > l2.y2)) cross = 3;
			else if(l1.y2 == l2.y2 && (l1.y1 < l1.y2 && l2.y2 < l2.y1 || l1.y1 > l1.y2 && l2.y2 > l2.y1)) cross = 3;
			// �� ���� �ʰ��ϴ� ������ ��ġ�� ���  
			else cross = 1;
		} else { // x�� ����, �밢��  
			// �ȸ����� ���  
			if(l1.x1 > l2.x1 && l1.x1 > l2.x2 && l1.x2 > l2.x1 && l1.x2 > l2.x2) cross = 0;
			else if(l2.x1 > l1.x1 && l2.x1 > l1.x2 && l2.x2 > l1.x1 && l2.x2 > l1.x2) cross = 0;
			// ���� �������� �� ������ �� ������ ������ ���
			else if(l1.x1 == l2.x1 && (l1.x2 < l1.x1 && l2.x1 < l2.x2 || l1.x2 > l1.x1 && l2.x1 > l2.x2)) cross = 2;
			else if(l1.x1 == l2.x2 && (l1.x2 < l1.x1 && l2.x2 < l2.x1 || l1.x2 > l1.x1 && l2.x2 > l2.x1)) cross = 2;
			else if(l1.x2 == l2.x1 && (l1.x1 < l1.x2 && l2.x1 < l2.x2 || l1.x1 > l1.x2 && l2.x1 > l2.x2)) cross = 3;
			else if(l1.x2 == l2.x2 && (l1.x1 < l1.x2 && l2.x2 < l2.x1 || l1.x1 > l1.x2 && l2.x2 > l2.x1)) cross = 3;
			// �� ���� �ʰ��ϴ� ������ ��ġ�� ��� 
			else cross = 1;
		}
	} else cross = 4;
	
	if(cross == 0) putchar('0'); // �� ������ ���  
	else if(cross == 1) putchar('1'); // �� ���� �ʰ��ϴ� �������� ��ġ�� ���  
	else if(cross == 2) printf("1\n%d %d", l1.x1, l1.y1); // (x1, y1)���� ������ ���  
	else if(cross == 3) printf("1\n%d %d", l1.x2, l1.y2); // (x2, y2)���� ������ ���  
	else { // �� �� �� ������ ������ ���  
		double x, y;
		x = (((double) l1.x1 * l1.y2 - (double) l1.y1 * l1.x2) * (l2.x1 - l2.x2) - ((double) l2.x1 * l2.y2 - (double) l2.y1 * l2.x2) * (l1.x1 - l1.x2)) / 
			((double) (l1.x1 - l1.x2) * (l2.y1 - l2.y2) - (double) (l2.x1 - l2.x2) * (l1.y1 - l1.y2));
		y = (((double) l1.x1 * l1.y2 - (double) l1.y1 * l1.x2) * (l2.y1 - l2.y2) - ((double) l2.x1 * l2.y2 - (double) l2.y1 * l2.x2) * (l1.y1 - l1.y2)) / 
			((double) (l1.x1 - l1.x2) * (l2.y1 - l2.y2) - (double) (l2.x1 - l2.x2) * (l1.y1 - l1.y2));
		printf("1\n%.10lf %.10lf", x, y);
	}
	return 0;
}
