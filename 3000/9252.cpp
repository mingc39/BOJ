#include <stdio.h>

int main() {
	char s1[1024], s2[1024], sr[1024];
	int lcs[1024][1024] = {0,};
	int length = 0;
	int i, j;
	
	scanf("%s %s", s1, s2);
	
	for(i = 0; s1[i] != '\0'; i++) {
		for(j = 0; s2[j] != '\0'; j++) {
			if(s1[i] == s2[j]) lcs[i + 1][j + 1] = lcs[i][j] + 1;
			else lcs[i + 1][j + 1] = lcs[i + 1][j] > lcs[i][j + 1] ? lcs[i + 1][j] : lcs[i][j + 1];
			if(length < lcs[i + 1][j + 1]) length = lcs[i + 1][j + 1];
		}
	}
	
	printf("%d", length);
	
	if(length > 0) {
		sr[length--] = '\0';
		while(lcs[i][j] != 0) {
			if(lcs[i - 1][j] == lcs[i][j]) i--;
			else if(lcs[i][j - 1] == lcs[i][j]) j--;
			else {
				i--; j--;
				sr[length--] = s1[i];
			}
		}
		printf("\n%s", sr);
	}
	
	return 0;
}
