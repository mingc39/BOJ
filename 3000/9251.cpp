#include <stdio.h>

int main() {
	char s1[1024], s2[1024];
	int lcs[1024][1024] = {0,};
	int length = 0;
	
	scanf("%s %s", s1, s2);
	
	for(int i = 0; s1[i] != '\0'; i++) {
		for(int j = 0; s2[j] != '\0'; j++) {
			if(s1[i] == s2[j]) lcs[i + 1][j + 1] = lcs[i][j] + 1;
			else lcs[i + 1][j + 1] = lcs[i + 1][j] > lcs[i][j + 1] ? lcs[i + 1][j] : lcs[i][j + 1];
			if(length < lcs[i + 1][j + 1]) length = lcs[i + 1][j + 1];
		}
	}
	
	printf("%d", length);
	
	return 0;
}
