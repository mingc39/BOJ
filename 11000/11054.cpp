#include <stdio.h>

int main() {
	int n, a[1000];
	int l[1001] = {0,};
	int k[1001] = {0,};
	int t, m = 0;
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	// �� ���ʺ��� a[i] ���ʿ��� �����ϰ� ������ a[i]���� �۰� ���̰� ���� �� ���� �κ� ���� ã��
	l[1001] = 0;
	for(int i = 0; i < n; i++) {
		l[i] = 1;
		t = 1000;
		for(int j = 0; j < i; j++) {
			if(l[j] > l[t] && a[j] < a[i]) t = j;
		}
		l[i] += l[t];
		//if(m < l[i]) m = l[i]; // ������ �ִ밪�� ���� ���ϱ� 
	}
	
	// �� �����ʺ��� a[i] �����ʿ��� �����ϰ� ������ a[i]���� �۰� ���̰� ���� �� ���� �κ� ���� ã��
	k[1001] = 0;
	for(int i = n - 1; i >= 0; i--) {
		k[i] = 1;
		t = 1000;
		for(int j = n - 1; j > i; j--) {
			if(k[j] > k[t] && a[j] < a[i]) t = j;
		}
		k[i] += k[t];
		//if(m < k[i]) m = k[i]; // ������ �ִ밪�� ���� ���ϱ� 
	}
	
	// ������ �ִ밪 ���ϱ� 
	for(int i = 0; i < n; i++) {
		if(m < l[i] + k[i] - 1) m = l[i] + k[i] - 1;
	}
	
	printf("%d", m);
	
	return 0;
}
