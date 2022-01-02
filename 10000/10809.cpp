#include <stdio.h>

int main() {
	int p[26];
	char s[128];
	
	for(int i = 0; i < 26; i++) p[i] = -1;
	
	scanf("%s", s);
	
	for(int i = 0; s[i] != '\0'; i++)
		if(p[s[i] - 'a'] == -1) p[s[i] - 'a'] = i;
	
	for(int i = 0; i < 26; i++) printf("%d ", p[i]);
	
	return 0;
}
