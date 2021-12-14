#include <stdio.h>

int main() {
    int a;
    int i = 0;
    int c[26] = { 0, };
    
    a = getchar();
    while(a != '\n' && a != EOF) {
    	if(a >= 'a' && a <= 'z') c[a - 'a'] = c[a - 'a'] + 1;
    	if(a >= 'A' && a <= 'Z') c[a - 'A'] = c[a - 'A'] + 1;
        a = getchar();
    }
    
    int max = 0;
    for(i = 0; i < 26; i++) {
    	//printf("%c: %d\n", i + 'A', c[i]);
    	if(c[i] > max) { a = i + 'A'; max = c[i]; }
    	else if(c[i] == max) a = '?';
	}
    
    printf("%c", a);
    return 0;
}