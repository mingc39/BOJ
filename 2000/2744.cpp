#include <stdio.h>

int main() {
	char string[128];
	scanf("%s", string);
	
	for(int i = 0; string[i] != '\0'; i++) {
		if(string[i] <= 'Z') string[i] += 'a' - 'A';
		else if(string[i] >= 'a') string[i] -= 'a' - 'A';
	}
	
	printf("%s", string);
	
	return 0;
}
