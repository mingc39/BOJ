#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

//char r[3072 * 6145];
char *r;
int  p[12] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

void a(int center, int level, int line, int length) {
	if(level == 0) {
		r[(line*3 - 3) * length + center - 1] = '*';
		r[(line*3 - 2) * length + center - 2] = '*';
		r[(line*3 - 2) * length + center    ] = '*';
		r[(line*3 - 1) * length + center - 3] = '*';
		r[(line*3 - 1) * length + center - 2] = '*';
		r[(line*3 - 1) * length + center - 1] = '*';
		r[(line*3 - 1) * length + center    ] = '*';
		r[(line*3 - 1) * length + center + 1] = '*';
	} else {
		a(center               , level - 1, line - p[level], length);
		a(center - p[level] * 3, level - 1, line           , length);
		a(center + p[level] * 3, level - 1, line           , length);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	
	// 배열, 변수 초기화  
	int l = 0;
	for(int i = n / 3; i > 1; i /= 2) l++;
	r = (char*)malloc(sizeof(char) * 2 * n * (n + 1));
	memset(r, ' ', 2 * n * (n + 1));
	for(int i = 1; i < n; i++) {
		r[i * 2 * (n + 1) - 1] = '\n';
	}
	r[n * 2 * (n + 1) - 1] = '\0';
	
	a(n, l, n / 3, 2 * (n + 1));
	
	//printf("%s", r);
	//fwrite(r, sizeof(char), 2 * n * (n + 1) - 1, stdout);
	fputs(r, stdout);
	
	return 0;
}
