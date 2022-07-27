#include <stdio.h>

int main() {
	int num[100], n, v, c = 0;
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	scanf("%d", &v);
	
	for(int i = 0; i < n; i++)
		if(num[i] == v) c++;
	
	printf("%d", c);
	
	return 0;
}
