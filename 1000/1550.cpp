#include <stdio.h>

int main() {
	int num = 0;
	char str[8];
	
	scanf("%s", str);
	for(int i = 0; str[i] != '\0'; i++) {
		num *= 16;
		if(str[i] >= 'A') num += str[i] - 'A' + 10;
		else num += str[i] - '0';
	}
	
	printf("%d", num);
	
	return 0;
}
