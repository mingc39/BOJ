#include <stdio.h>

int a[1000001];

int func(int n) {
	if(n < 1) return 5000000;
	if(n == 1) return 0;
	if(a[n] != 0) return a[n];
	
	int min = 0;
	if(func(n - 1) < a[min]) min = n - 1;
	if(n % 3 == 0) if(func(n / 3) < a[min]) min = n / 3;
	if(n % 2 == 0) if(func(n / 2) < a[min]) min = n / 2;
	
	return a[n] = a[min] + 1;
}

int main() {
	int n;
	scanf("%d", &n);
	a[0] = 5000000;
	a[1] = 0;
	a[2] = 1;
	a[3] = 1;
	
	func(n);
	printf("%d", a[n]);
	
	return 0;
}
