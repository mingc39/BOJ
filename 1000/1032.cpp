#include <stdio.h>

int main() {
	
	int N;
	char fn[50][55], r[55];
	
	// 입력 
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%s", fn[i]);
	}
	
	char c;
	for(int i = 0; fn[0][i] != '\0'; i++) {
		c = fn[0][i];
		for(int j = 1; j < N; j++) {
			if(fn[j][i] != fn[0][i]) {
				c = '?';
				break;
			}
		}
		r[i] = c;
		r[i+1] = '\0';
	}
	
	printf("%s", r);
	
	return 0;
}