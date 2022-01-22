#include <stdio.h>

int a[2000][2000] = {0,};
int s[2000], n;

int f(int start, int end) {
	// ���� Ȯ���ߴ� ���  
	if(a[start][end] != 0) return a[start][end];
	
	// ������ ������ �ڿ� �ִ� ��� (���̰� ¦���϶� ���ȣ���� �߻� ����) 
	if(start > end) return 1;
	
	// �Ӹ�������� Ȯ��  
	if(start == end) a[start][end] = 1; // ���̰� 1�̸� �Ӹ����  
	else if(s[start] == s[end]) a[start][end] = f(start + 1, end - 1); // �� ���� ������ �� ���� ������ ���� ���� 
	else a[start][end] = -1; // �� ���� �ٸ��� �Ӹ���� �ƴ�
	
	// ��� ��ȯ 
	return a[start][end];
}

int main() {
	// ���� �Է�  
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &s[i]);
	
	int m, s, e;
	scanf("%d", &m); // ���� �� �Է�  
	while(m--) {
		// ���� �Է°� �Ӹ�������� ���  
		scanf("%d %d", &s, &e);
		putchar(f(s - 1, e - 1) == 1 ? '1' : '0');
		putchar('\n');
	}
	
	return 0;
}
