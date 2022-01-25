#include <stdio.h>

int a[2500][2500] = {0,}, n;
int b[2500];
char s[2501];

// start���� end���� �Ӹ�������� Ȯ��  
int f1(int start, int end) {
	// ���� Ȯ���ߴ� ���  
	if(a[start][end] != 0) return a[start][end];
	
	// ������ ������ �ڿ� �ִ� ��� (���̰� ¦���϶� ���ȣ���� �߻� ����) 
	if(start > end) return 1;
	
	// �Ӹ�������� Ȯ��  
	if(start == end) a[start][end] = 1; // ���̰� 1�̸� �Ӹ����  
	else if(s[start] == s[end]) a[start][end] = f1(start + 1, end - 1); // �� ���� ������ �� ���� ������ ���� ���� 
	else a[start][end] = -1; // �� ���� �ٸ��� �Ӹ���� �ƴ�
	
	// ��� ��ȯ 
	return a[start][end];
}

// 0���� end���� �Ӹ���� ������ �ּҰ� ���ϱ�  
int f2(int end) {
	// ���� Ȯ���ߴ� ���
	if(b[end] != 0) return b[end];
	
	// 0���� end������ �Ӹ������ ���  
	if(f1(0, end) > 0) return b[end] = 1;
	
	// (0,end-1)(end)���� (0)(1,end)���� �����غ��鼭 �ּ� ���� ���ϱ�  
	int min = 3000;
	for(int i = end - 1; i >= 0; i--) {
		if(f1(i + 1, end) < 0) continue;
		int t = f2(i) + 1;
		if(min > t) min = t;
	}
	
	return b[end] = min;
}

int main() {
	scanf("%s", s);
	while(s[++n] != '\0');
	printf("%d", f2(n - 1));
	return 0;
}
