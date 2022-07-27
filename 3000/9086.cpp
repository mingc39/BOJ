#include <stdio.h>
#include <string.h>

int main() {
	int n;
	char string[1024];
	
	for(scanf("%d", &n); n > 0; n--) {
		scanf("%s", string);
		printf("%c%c\n", string[0], string[strlen(string) - 1]);
	}
	
	return 0;
}
