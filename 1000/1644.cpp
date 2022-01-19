#include <stdio.h>
#include <math.h>

int p[300000] = {1, 2, 3, 0, } , n = 283150, l = 3;

int prime(int k) {
	// �̹� ã�� �Ҽ��� ���  
	if(k < l) return p[k];
	// ���� ��ã�� �Ҽ��� ã�� 
	int i = p[l - 1] + 2;
	int c = 1;
	while(k >= l) {
		c = 1;
		for(int j = 1; p[j] <= sqrt(i); j++) {
			if(i % p[j] == 0) {
				c = 0;
				break;
			}
		}
		if(c != 0) {
			p[l++] = i;
		}
		i += 2;
	}
	return p[k];
}

int main() {
	int i = 0, j = 0, cnt = 0, sum = 0, s;
	
	// �Է�  
	scanf("%d", &s);
	
	// i, j ������ ������ �κ��� Ȯ��  
	while(i <= n && j <= n) {
		// i ��° �Ҽ��� s���� ũ�� �� �̻� Ž���� �ʿ� ���� 
		if(prime(i) > s) break; 
		// �κ����� s���� ũ�ų� ���� ������ ���κ� �ڷ� �ø���  
		while(sum <= s) {
			sum += prime(j);
			j++;
		}
		// �κ����� s���� �۾����� �������� �պκ� �ڷ� ����  
		while(sum - prime(i) >= s) {
			sum -= prime(i);
			i++;
		}
		// ���� ������ ���� ���ϴ� ���� ������ ī��Ʈ  
		if(sum == s) cnt++;
		// ���� �κ��� Ž���� ���� ���κ� �ڷ� �� ĭ �б�  
		sum += prime(j);
		j++;
	}
	
	// ���  
	printf("%d", cnt);
		
	return 0;
}
