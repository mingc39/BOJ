#include <stdio.h>

int main() {
	int n, sqrn[223];
	for(int i = 1; i < 224; i++) sqrn[i - 1] = i * i;
	scanf("%d", &n);
	//n = 49999;
	
	// 1개로 되는지 확인
	for(int i = 0; i < 223; i++) {
		if(n < sqrn[i]) break;
		if(n == sqrn[i]) {
			printf("1");
			return 0;
		}
	} 
	
	// 2개로 되는지 확인
	for(int i = 0; i < 223; i++) {
		if(n < sqrn[i]) break;
		for(int j = i; j < 223; j++) {
			if(n < sqrn[i] + sqrn[j]) break;
			if(n == sqrn[i] + sqrn[j]) {
				printf("2");
			    return 0;
			}
		}
	} 
	
	// 3개로 되는지 확인
	for(int i = 0; i < 223; i++) {
		if(n < sqrn[i]) break;
		for(int j = i; j < 223; j++) {
			if(n < sqrn[i] + sqrn[j]) break;
			for(int k = j; k < 223; k++) {
				if(n == sqrn[i] + sqrn[j] + sqrn[k]) {
					printf("3");
					return 0;
				}
			}
		}
	} 
	
	printf("4");
	return 0;
}