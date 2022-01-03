#include <stdio.h>

// ��� ��  
void mm(int a[5][5], int b[5][5], int c[5][5], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int t = 0;
			for(int k = 0; k < n; k++) {
				t += a[i][k] * b[k][j];
			}
			c[i][j] = t % 1000;
		}
	}
}

// ��� ����  
void mc(int src[5][5], int dst[5][5], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			dst[i][j] = src[i][j];
		}
	}
}

// ��� ���  
void print(int src[5][5], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("%d ", src[i][j]);
		}
		putchar('\n');
	}
}

int main() {
	int size;
	long long m;
	int a[5][5]; // (���� a)^(2^n) % 1000�� ���� ����
	int b[5][5]; // �ӽ� ����� 
	int c[5][5] = {	{1, 0, 0, 0, 0}, // ���⿡ a^n�� ��� ���س����ſ��� ���� ����� ���⿡ ����ſ� 
					{0, 1, 0, 0, 0}, // ����̴ϱ� 1 ��� �������  
					{0, 0, 1, 0, 0},
					{0, 0, 0, 1, 0},
					{0, 0, 0, 0, 1}};
	
	// �Է�  
	scanf("%d %lld", &size, &m);
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	// b = k0 * 2^n + k1 * 2^(n - 1) + ... + kn * 2^0 �϶� (ki�� 0 �Ǵ� 1) 
	// a^b = a^(k0 * 2^n + k1 * 2^(n - 1) + ... + kn * 2^0)
	// = a^(k0 * 2^n) * a^(k1 * 2^(n - 1)) * ... * a^(kn * 2^0)
	while(m > 0) { // kn -> k0 ������ ����
		if(m % 2 == 1) { // ki�� 0���� 1���� Ȯ��  
			mm(a, c, b, size); // ki�� 1�ΰ�� r�� t = a^(2^(n - i)) ���ϱ�  
			mc(b, c, size); // ���� ��� ����  
		}
		mm(a, a, b, size); // ���� t�� ���  
		mc(b, a, size); // ���� ��� ���� 
		m = m / 2;
	}
	
	// ���  
	print(c, size);
	
	return 0;
}
