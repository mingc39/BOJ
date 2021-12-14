#include <stdio.h>

int main() {
	
	int n;
	scanf("%d", &n);
	
	int num[100100];
	int s1[100100] = { 0, };
	int s2[100100] = { 0, };
	for(int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	
	int i, pos = 0;
	int max = 0, min = 0; 
	for(i = 0; i < n; i++) {
		if(max < num[i]) {
			for(int j = max + 1; j <= num[i]; j++) {
				s1[j] = 1;
			}
			s1[num[i]] = 0;
			max = min = num[i];
			pos = num[i] - 1;
			while(s1[pos] != 1) pos--;
		}
		else if(min > num[i]) {
			if(pos != num[i]) break;
			s1[num[i]] = 0;
			min = num[i];
			pos = num[i] - 1;
			while(s1[pos] != 1) pos--;
		}
		else break;
	}
	
	if(i != n) {
		printf("NO");
		return 0;
	}
	
	int j;
	max = 0, min = 0;
	for(i = 0; i < n; i++) {
		if(max < num[i]) {
			for(j = 0; j < num[i] - max; j++) printf("+\n");
			printf("-\n");
			max = min = num[i];
		}
		else if(min > num[i]) {
			printf("-\n");
			min = num[i];
		}
	}
	
	return 0;
}