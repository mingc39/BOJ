#include <stdio.h>

char T[1048576];
char P[1048576];

int  a[1048576];
int  b[1048576];

int main() {
	int n = 0;
	int l, m;
	int i, j; 
	
	// �Է�
	gets(T);
	gets(P);
	
	// ���ڿ� ���� ���ϱ�  
	while(T[l] != '\0') l++;
	while(P[m] != '\0') m++;
	
	// �� �ڰ� ������ ������ ã��  
	i = 1; j = 0;
	a[0] = 0;
	while(i < m) {
		if(P[i] == P[j]) a[i++] = ++j;
		else if(j != 0) j = a[j - 1];
		else a[i++] = 0;
	}
	
	// ã�� 
	i = 0; j = 0;
	while(i < l) {
		// ��ġ�ϸ� ����  
		if(T[i] == P[j]) {
			i++;
			j++;
		}
		// ��ġ���� �ʴ� ���  
		else if(j == 0) { 
			i++;
		} else {
			j = a[j - 1];
		}
		
		// ã�� ���ڿ��� ������ �߰ߵ� ���  
		if(j == m) {
			b[n++] = i - j + 1; // �迭�� ���� ��ġ ����  
			j = a[j - 1]; // ã�� ��� ����  
		}
	}
	
	printf("%d\n", n);
	for(int i = 0; i < n; i++) printf("%d ", b[i]);
	
	return 0;
}
