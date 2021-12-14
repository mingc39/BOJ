#include<stdio.h>

int main() {
	int n, i, t, num = 665;
	int t1 = 0, t2 = 0;
	scanf("%d", &n);
	
	while(n != 0) {
		num++;
		t1 = 0, t2 = 0;
		for(t = num; t > 0; t /= 10) {
			if(t1 == 6 && t2 == 6 && t % 10 == 6) break;
			t1 = t2;
			t2 = t % 10;
		}
		if(t != 0) n--;
	}
	
	printf("%d\n", num);
	
	return 0;
}
