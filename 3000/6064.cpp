#include <stdio.h>

// �ּҰ���� ���ϱ�
int lcm(int a, int b) {
	int l, s, t;
	if(a > b) { l = a; s = b; }
	else if(a < b)  { l = b; s = a; }
	else { l = a; s = 0; }
	while(s != 0) {
		t = s;
		s = l % s;
		l = t;
	}
	return a / l * b;
}

int main() {
	int T, n, m, x, y;
	for(scanf("%d", &T); T > 0; T--) {
		// k % m == x
		// k % n == y
		// �� �����ϴ� k ���� ã�ƾ��Ѵ�
		scanf("%d %d %d %d", &m, &n, &x, &y);
		// ������ ���� ����� ������ 0 ~ (n - 1)�ε� x, y �� 1 ~ n ������ �Էµ� 
		if(x == m) x = 0;
		if(y == n) y = 0;
		
		int i, r = -1;
		int l = lcm(n, m);
		// i % m == x �� �����ϴ� i�� x���� m �������� ����
		// <m, n>(������ �⵵)�� m, n�� �ּҰ�����̹Ƿ� m, n�� �ּ� ����������� Ȯ���ϸ� �� 
		for(i = x; i <= l; i += m) {
			// �ش� i�� i % n == y �����ϴ��� Ȯ�� 
			if(i % n == y) {
				r = i;
				break;
			}
		}
		// ���ǿ� �´� ���� ���� �� ����
		// �׷���� { r = i; break; }�� ������� �ʾ� r�� �ʱⰪ -1�� ��µ� 
		printf("%d\n", r);
	}
	return 0;
}
