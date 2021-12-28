#include <stdio.h>
#include <stdlib.h>

// x�� �� ĭ�� �� ��� (ex. 12345 -> 1 2 3 4 5) 
void print(int x) {
	int l = 1, n = x;
	while(n > 0) {
		l *= 10;
		n /= 10;
	}
	l /= 10;
	while(l > 0) {
		putchar(x / l + '0');
		putchar(' ');
		x %= l;
		l /= 10;
	}
}

int main() {
	// ���� 
	int *s, *l, p = 0;
	s = (int*)malloc(sizeof(int) * 1000000);
	l = (int*)malloc(sizeof(int) * 1000000);
	
	int n, m;
	int a, b;
	
	// �Է�  
	scanf("%d %d", &n, &m);
	
	// ���� ���� ���� ���ÿ� ����  
	for(int i = n; i > 0; i--) {
		s[p] = i;
		l[p] = 1;
		p++;
	}
	
	// ������ �������� Ž��  
	while(p > 0) {
		// ���ÿ��� �ϳ� �̱�  
		p--;
		a = s[p];
		b = l[p];
		
		// ���̰� m�̸� ���  
		if(b == m) {
			print(a);
			putchar('\n');
			continue;
		}
		
		// ������ ���� �� �߰�  
		for(int i = n; i > 0; i--) {
			if(i > a % 10) {
				s[p] = a * 10 + i;
				l[p] = b + 1;
				p++;
			}
		}
	}
	
	return 0;
}
