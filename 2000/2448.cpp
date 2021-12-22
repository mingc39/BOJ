#include <stdio.h>
#include <memory.h>

char r[3072][6145];
int  p[12] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

void a(int center, int level, int line) {
	if(level == 0) {
		r[line*3 - 3][center - 1] = '*';
		r[line*3 - 2][center - 2] = '*';
		r[line*3 - 2][center    ] = '*';
		r[line*3 - 1][center - 3] = '*';
		r[line*3 - 1][center - 2] = '*';
		r[line*3 - 1][center - 1] = '*';
		r[line*3 - 1][center    ] = '*';
		r[line*3 - 1][center + 1] = '*';
	} else {
		a(center               , level - 1, line - p[level]);
		a(center - p[level] * 3, level - 1, line           );
		a(center + p[level] * 3, level - 1, line           );
	}
}

int main() {
	int n;
	scanf("%d", &n);
	
	// 배열, 변수 초기화  
	int l = 0;
	for(int i = n / 3; i > 1; i /= 2) l++;
	for(int i = 0; i < n; i++) {
		memset(r[i], ' ', 2 * n);
		r[i][2 * n] = '\0';
	}
	
	a(n, l, n / 3);
	
	for(int i = 0; i < n; i++) {
		printf("%s\n", r[i]);
	}
	
	return 0;
}
