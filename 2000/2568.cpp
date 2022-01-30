#include <stdio.h>
#include <stdlib.h>

int a[1000000];
int b[1000000];
int c[1000000];

int cmpi(const void* a, const void* b) {
	return *((int*)a) - *((int*)b);
}

int cmp0(const void* a, const void* b) {
	return ((int*)a)[0] - ((int*)b)[0];
}

int cmp1(const void* a, const void* b) {
	return ((int*)a)[1] - ((int*)b)[1];
}

int main() {
	int n, l = 0; 
	int d[100000][2];
	 
	// �Է� �� A ������ ��ȣ������ ����  
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &d[i][0], &d[i][1]);
	}
	qsort(d, n, sizeof(int) * 2, cmp0);
	
	// �츱 ���� ���ϱ�  
	//scanf("%d", &a[0]);
	a[0] = d[0][1];
	b[0] = a[0];
	c[0] = 0;
	for(int i = 1; i < n; i++) {
		//scanf("%d", &a[i]);
		a[i] = d[i][1];
		if(a[i] > b[l]) { // �̹��� �Է¹��� ���� ���� ū ��� b�� �� �ڿ� �߰��ϱ�  
			b[++l] = a[i];
			c[i] = l;
		} else { // �̹��� �Է¹��� ���� ���� ũ�� ���� ��� 
			// b���� a[i]���� ū ù ��� ã��  
			int left = 0, right = l;
			while(left < right) {
				int mid = (left + right) / 2;
				if(b[mid] < a[i]) left = mid + 1;
				else right = mid;
			}
			// ã�� ��ġ�� a[i]�� �ٲٱ�  
			b[right] = a[i];
			c[i] = right;
		}
	}
	
	// ���� ��� 
	printf("%d\n", n - l - 1);
	
	// �츱 ���� ��� ��������  
	for(int i = n - 1, t = l; i >= 0 && t >= 0; i--) {
		if(c[i] == t) {
			b[t] = a[i];
			t--;
		}
	}
	
	// �� �츱 ���� ������� ��ȯ  
	qsort(d, n, sizeof(int) * 2, cmp1);
	for(int i = 0, j = 0, k = 0; i < n; i++) {
		if(d[i][1] == b[j]) j++;
		else a[k++] = d[i][0];
	}
	
	// ���� �� ���  
	qsort(a, n - l - 1, sizeof(int), cmpi);
	for(int i = 0; i < n - l - 1; i++) printf("%d\n", a[i]);
	
	return 0;
}
