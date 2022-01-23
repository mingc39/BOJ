#include <stdio.h>

int main() {
	int n, a[1000];
	int l[1001] = {0,};
	int t, m = 0;
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	l[1001] = 0;
	for(int i = n - 1; i >= 0; i--) {
		l[i] = a[i];
		t = 1000;
		for(int j = n - 1; j > i; j--) {
			if(l[j] > l[t] && a[j] > a[i]) t = j;
		}
		l[i] += l[t];
		if(m < l[i]) m = l[i];
	}
	
	printf("%d", m);
	
	return 0;
}
