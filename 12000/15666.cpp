#include <stdio.h>
#include <stdlib.h>

int arr[8];

int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

// x�� �� ĭ�� �� ��� (ex. 12345 -> 1 2 3 4 5) 
void print(int x) {
	int l = 1, n = x;
	while(n > 0) {
		l *= 10;
		n /= 10;
	}
	l /= 10;
	while(l > 0) {
		printf("%d", arr[x / l - 1]);
		putchar(' ');
		x %= l;
		l /= 10;
	}
}

int main() {
	// ���� 
	int *s, *l, p = 0;
	s = (int*)malloc(sizeof(int) * 1000000);
	l = (int*)malloc(sizeof(int) * 1000000);
	
	int n, m;
	int a, b;
	
	// �Է�  
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for(int i = n; i < 8; i++) arr[i] = 99999;
	
	qsort(arr, n, sizeof(int), cmp);
	for(a = 0; a < n - 1; a++)
		if(arr[a] == arr[a + 1]) arr[a] = 99999;
	qsort(arr, n, sizeof(int), cmp);
	for(n = 0; arr[n] != 99999 && n < 8; n++);
	
	// ���� ���� ���� ���ÿ� ����  
	for(int i = n; i > 0; i--) {
		s[p] = i;
		l[p] = 1;
		p++;
	}
	
	// ������ �������� Ž��  
	while(p > 0) {
		// ���ÿ��� �ϳ� �̱�  
		p--;
		a = s[p];
		b = l[p];
		
		// ���̰� m�̸� ���  
		if(b == m) {
			print(a);
			putchar('\n');
			continue;
		}
		
		// ������ ���� �� �߰�  
		for(int i = n; i > 0; i--) {
			if(i >= a % 10) {
				s[p] = a * 10 + i;
				l[p] = b + 1;
				p++;
			}
		}
	}
	
	return 0;
}
