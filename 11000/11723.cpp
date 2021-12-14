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
			set[ 1] = 1;
			set[ 2] = 1;
			set[ 3] = 1;
			set[ 4] = 1;
			set[ 5] = 1;
			set[ 6] = 1;
			set[ 7] = 1;
			set[ 8] = 1;
			set[ 9] = 1;
			set[10] = 1;
			set[11] = 1;
			set[12] = 1;
			set[13] = 1;
			set[14] = 1;
			set[15] = 1;
			set[16] = 1;
			set[17] = 1;
			set[18] = 1;
			set[19] = 1;
			set[20] = 1;
		} else if(strcmp(cmd, "empty") == 0) {
			set[ 1] = 0;
			set[ 2] = 0;
			set[ 3] = 0;
			set[ 4] = 0;
			set[ 5] = 0;
			set[ 6] = 0;
			set[ 7] = 0;
			set[ 8] = 0;
			set[ 9] = 0;
			set[10] = 0;
			set[11] = 0;
			set[12] = 0;
			set[13] = 0;
			set[14] = 0;
			set[15] = 0;
			set[16] = 0;
			set[17] = 0;
			set[18] = 0;
			set[19] = 0;
			set[20] = 0;
		}
	}
	
	return 0;
}
