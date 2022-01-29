#include <stdio.h> 

// ��� ��  
void mm(long long a[50][50], long long b[50][50], long long c[50][50]) {
	for(long long i = 0; i < 50; i++) {
		for(long long j = 0; j < 50; j++) {
			long long t = 0;
			for(long long k = 0; k < 50; k++) {
				t += a[i][k] * b[k][j];
			}
			c[i][j] = t % 1000000007;
		}
	}
}

// ��� ����  
void mc(long long src[50][50], long long dst[50][50]) {
	for(long long i = 0; i < 50; i++) {
		for(long long j = 0; j < 50; j++) {
			dst[i][j] = src[i][j];
		}
	}
}

void mp(long long a[50][50], long long c[50][50], long long m) {
	long long b[50][50];
	
	// b = k0 * 2^n + k1 * 2^(n - 1) + ... + kn * 2^0 �϶� (ki�� 0 �Ǵ� 1) 
	// a^b = a^(k0 * 2^n + k1 * 2^(n - 1) + ... + kn * 2^0)
	// = a^(k0 * 2^n) * a^(k1 * 2^(n - 1)) * ... * a^(kn * 2^0)
	while(m > 0) { // kn -> k0 ������ ����
		if(m % 2 == 1) { // ki�� 0���� 1���� Ȯ��  
			mm(a, c, b); // ki�� 1�ΰ�� r�� t = a^(2^(n - i)) ���ϱ�  
			mc(b, c); // ���� ��� ����  
		}
		mm(a, a, b); // ���� t�� ���  
		mc(b, a); // ���� ��� ���� 
		m = m / 2;
	}
}

int main() {
	// ������� 
	long long r[50][50] = {0,};
	// ķ�۽� ����  
	long long a[50][50] = {0,};
	
	// ��å �ð� D  
	int d, n, m;
	
	// �ǹ�, �� ���� �Է�  
	scanf("%d %d", &n, &m);
	
	// ������� �ʱ�ȭ  
	for(int i = 0; i < n; i++) r[i][i] = 1;
	
	// ķ�۽� ���� �Է�  
	for(int i = 0; i < m; i++) {
		int t;
		scanf("%d %d", &d, &t);
		d--; t--;
		a[d][t] = 1;
		a[t][d] = 1;
	}
	
	// �̵� �ð� �Է�  
	scanf("%d", &d);
	
	// r = m ^ d ���  
	mp(a, r, d);
	
	// �������а�->...->�������а� ��μ� ���  
	printf("%d", r[0][0] % 1000000007);
	
	return 0;
}
