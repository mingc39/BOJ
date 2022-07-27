#include <stdio.h>

int main() {
	char string[128];
	
	while(gets(string) != NULL) printf("%s\n", string);
	
	return 0;
}
