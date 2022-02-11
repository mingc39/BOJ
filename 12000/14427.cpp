#include <stdio.h>

int min[262144];
int pow[22];

int main() {
	// �ε��� ���� 2�� ���� �̸� ���ϱ�  
	pow[0] = 1;
	for(int i = 0; i < 21; i++) pow[i + 1] = pow[i] * 2;
	
	int n, m, k;
	int a, b, c;
	
	// ���� ���� �Է� 
	scanf("%d", &n);
	
	// ���׸�Ʈ Ʈ�� ���� ���ϱ�  
	for(a = 0; a <= 20; a++) if(pow[a] >= n) break;
	min[0] = a;
	
	// �־��� ���� �Է¹޾� ���� ���� �ֱ�  
	a = pow[a];
	for(b = 0; b < n; b++) {
		scanf("%d", &c);
		min[a + b] = c;
	}
	for(; b < a; b++) { // ���� ���� ��� 0���� ä���  
		min[a + b] = 2147483647;
	}
	
	// ���׸�Ʈ Ʈ�� ����(���� ��� ���� ����� �ö󰡱�) 
	if(min[0] - 1 >= 0) {
		for(int j = pow[min[0] - 1]; j < pow[min[0]]; j++) {
			min[j] = min[2 * j] <= min[2 * j + 1] ? 2 * j : 2 * j + 1;
		}
	}
	for(int i = min[0] - 2; i >= 0; i--) {
		for(int j = pow[i]; j < pow[i + 1]; j++) {
			min[j] = min[min[2 * j]] <= min[min[2 * j + 1]] ? min[2 * j] : min[2 * j + 1];
		}
	}
	
	// ��� �� �Է�  
	scanf("%d", &m);
	
	// ��� ����  
	for(int i = 0; i < m; i++) {
		// ��� �Է�  
		scanf("%d", &a);
		
			// �� ����
			if(a == 1) {
				scanf("%d %d", &b, &c);
				b--;
				b = b + pow[min[0]];
				min[b] = c;
				if(b / 2 > 0) {
					min[b / 2] = min[2 * (b / 2)] <= min[2 * (b / 2) + 1] ? 2 * (b / 2) : 2 * (b / 2) + 1;
				}
				for(int j = b / 4; j > 0; j /= 2) { // ����� ���� ��带 �ڼ����� ������ ��� �� ����  
					min[j] = min[min[2 * j]] <= min[min[2 * j + 1]] ? min[2 * j] : min[2 * j + 1];
				}
			} 
			
			// �ּ� �ε��� ���ϱ� 
			else if(a == 2) printf("%d\n", min[1] - pow[min[0]] + 1);
	}
	
	return 0;
}

