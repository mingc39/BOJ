#include <stdio.h>

int main() {
	int n, t;
	int a, b, c;
	
	scanf("%d", &n);
	
	// �ֻ����� 1���� ��� 
	if(n == 1) {
		// �� ���ϰ� ���� ū�� ���� 
		a = 0; b = 0;
		for(int i = 0; i < 6; i++) {
			scanf("%d", &c);
			a += c;
			if(b < c) b = c;
		}
		a -= b;
		printf("%d", a);
		
		return 0;
	}
	
	// �ֻ����� ���� ���
	// �Է¹޾Ƽ� �ݴ��� �ִ� �鳢�� �ּҰ� ���ϱ�  
	scanf("%d %d %d", &a, &b, &c);
	scanf("%d", &t);	if(c > t) c = t; // C <-> D
	scanf("%d", &t);	if(b > t) b = t; // B <-> E
	scanf("%d", &t);	if(a > t) a = t; // A <-> F
	
	// ������������ ���� 
	if(a > b) {
		t = a;
		a = b;
		b = t;
	} 
	if(b > c) {
		t = b;
		b = c;
		c = t;
	} 
	if(a > b) {
		t = a;
		a = b;
		b = t;
	} 
	
	// �� ��� �� ���
	printf("%lld", a * ((long long) n * (5 * n - 8) + 4) + (b * 8 * (n - 1)) + (c * 4));
	
	return 0;
}
