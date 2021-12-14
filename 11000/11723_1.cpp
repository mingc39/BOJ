#include <stdio.h>
#include <string.h>

int main() {
	int n, x;
	char cmd[32], set[21] = {0,};
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s %d", cmd, &x);
		if(strcmp(cmd, "add") == 0) {
			set[x] = 1;
		} else if(strcmp(cmd, "remove") == 0) {
			set[x] = 0;
		} else if(strcmp(cmd, "check") == 0) {
			printf("%d\n", set[x]);
		} else if(strcmp(cmd, "toggle") == 0) {
			set[x] = 1 - set[x];
		} else if(strcmp(cmd, "all") == 0) {
			memset(set + 1, 1, sizeof(char) * 20);
		} else if(strcmp(cmd, "empty") == 0) {
			memset(set + 1, 0, sizeof(char) * 20);
		}
	}
	
	return 0;
}