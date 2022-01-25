#include <stdio.h>

int a[1000000];
int b[1000000];
int c[1000000];

int main() {
	int n, l = 0; 
	 
	scanf("%d", &n);
	scanf("%d", &a[0]);
	b[0] = a[0];
	c[0] = 0;
	for(int i = 1; i < n; i++) {
		scanf("%d", &a[i]);
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
	
	printf("%d", n - l - 1);
	
	return 0;
}
