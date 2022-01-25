#include <stdio.h>
#include <memory.h>

int n, a[100001];
char c[100001];

void f() {
	// �Է�  
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	
	// �ʱ�ȭ  
	int cnt = 0; 
	memset(c + 1, 0, sizeof(char) * n);
	
	// 1������ n������ Ž��  
	for(int i = 1; i <= n; i++) {
		// ������ �湮�� ��� ���  
		if(c[i] != 0) continue;
		
		// i���� ���ϴ� ��� �̾ Ž�� (������ Ž���� ��� ������ ����) 
		int j = i;
		while(c[j] == 0) {
			c[j] = 2;
			j = a[j];
		} 
		int k = j; // Ž���� ����� ��� ��ȣ  
		
		// ��ȯ �� ������ �ִ»� ���� �� ���� �Ұ��� üũ 
		// ex) 1->3->4->7->6->4 ���� 1, 3 
		j = i;
		while(j != k && c[j] == 2) {
			c[j] = -1;
			j = a[j];
		}
		
		// ��ȯ ���� �ִ� ����� �� ���� �Ϸ�� üũ 
		// ex) 1->3->4->7->6->4 ���� 4, 6, 7 
		if(c[j] != 2) continue;
		j = k;
		do {
			c[j] = 1;
			cnt++;
			j = a[j];
		} while(k != j);
	}
	
	// ��� ���  
	printf("%d\n", n - cnt);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) f();
	return 0;
}
