#include <stdio.h>

int check(int b[10], int n) {
	if(n < 0) return 0;
	if(n == 0 && b[n] == 0) return 0;
	for(; n > 0; n /= 10) if(b[n % 10] == 0) return 0;
	return 1;
}

int main() {
	int n, m;
	int b[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int l = 0, c[6];
	int t;
	
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d", &t);
		b[t] = 0;
	}
	
	// ä�� 100���� +, -�� �̵��ϴ� ��� 
	m = n - 100;
	if(m < 0) m = - m;
	for(t = n; t > 0; t /= 10) c[l++] = t % 10;
	if(n == 0) c[l++] = 0;
	
	// ����Ű�� �ش� ä�η� �ٷ� �̵��ϴ°� �������� Ȯ�� 
	for(t = 0; t < l; t++) {
		if(b[c[t]] == 0) break;
	}
	if(t == l) {
		if(m > l) m = l;
	}
	
	for(t = 0; t < 10; t++)
		if(b[t] != 0) break;
	if(t == 10) {
		printf("%d", m);
		return 0;
	}
	
	for(t = n + 1; t <= 1000000; t++) {
		if(check(b, t)) break;
	}
	int tl = 0; // t�� ���� �ʰ��ϸ� t - n + tl < m ���� ���ϹǷ� for ���ᰡ ���� �ʰ����� break���� üũ ���ص��� 
	for(int i = t; i > 0; i /= 10) tl++;
	if(t - n + tl < m) m = t - n + tl;
	
	for(t = n - 1; t >= -1; t--) {
		if(check(b, t)) break;
	}
	tl = 0;
	for(int i = t; i > 0; i /= 10) tl++;
	if(t == 0) tl = 1; 
	if(n - t + tl < m && t >= 0) m = n - t + tl;
	
	printf("%d", m);
	
	return 0;
}