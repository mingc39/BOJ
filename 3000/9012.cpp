#include <stdio.h>

int trim(char* string, int length);

int main() {
	int n, l, i;
	char s[60];
	scanf("%d", &n);
	for(int k = 0; k < n; k++) {
		scanf("%s", s);
		
		for(l = 0; s[l] != '\0'; l++);
		
		while(s[0] != '\0') {
			for(i = 0; i < l; i++) {
				if(s[i] == '(' && s[i + 1] == ')') {
					s[i] = ' ';
					s[i + 1] = ' ';
					trim(s, l + 1);
					l -= 2;
					break;
				}	
			}
			if(i == l) break;
		}
			
		if(s[0] == '\0') printf("YES\n");
		else printf("NO\n");
		
	}
}

int trim(char* string, int length) {
	int pos = 0;
	for(int i = 0; i < length; i++)
		if(string[i] != ' ')
			string[pos++] = string[i];
	return pos;
}