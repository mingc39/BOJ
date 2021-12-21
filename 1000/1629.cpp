#include <stdio.h>

int main() {
	int a, b, c;
	unsigned long long r; // ���⿡ a�� ��� ���س����ſ��� ���� ����� ���⿡ ����ſ�  
	unsigned long long t; // a^(2^n) % c�� ���� �ӽ÷� ����  
	
	scanf("%d %d %d", &a, &b, &c);
	
	// �ʱⰪ ����  
	r = 1;
	t = a;
	// b = k0 * 2^n + k1 * 2^(n - 1) + ... + kn * 2^0 �϶� (ki�� 0 �Ǵ� 1) 
	// a^b = a^(k0 * 2^n + k1 * 2^(n - 1) + ... + kn * 2^0)
	// = a^(k0 * 2^n) * a^(k1 * 2^(n - 1)) * ... * a^(kn * 2^0)
	while(b > 0) { // kn -> k0 ������ ����  
		if(b % 2 == 1) { // ki�� 0���� 1���� Ȯ��  
			r = (r * t) % c; // ki�� 1�ΰ�� r�� t = a^(2^(n - i)) ���ϱ�  
		}
		t = (t * t) % c; // ���� t�� ���  
		b = b / 2; 
	}
	
	printf("%llu", r);
	
	return 0;
}
