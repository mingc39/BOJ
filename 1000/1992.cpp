#include<stdio.h>
#include<stdlib.h>

void quadTree(int N, int** img, int s, int r, int c) {
	
	if(N == 1) printf("%d", img[r][c]);
	int e = 1;
	for(int i = r; i < r + s; i++) {
		for(int j = c; j < c + s; j ++) {
			if(img[i][j] != img[r][c]) {
				e = 0;
				break;
			}
		}
		if(e != 1) break;
	}
	if(e == 1) {
		printf("%d", img[r][c]);
	} else {
		printf("(");
		quadTree(N, img, s / 2, r        , c        );
		quadTree(N, img, s / 2, r        , c + s / 2);
		quadTree(N, img, s / 2, r + s / 2, c        );
		quadTree(N, img, s / 2, r + s / 2, c + s / 2);
		printf(")");
	}
}

int main() {
	
	int N;
	int **img;
	char line[100] = {0, };
	
	scanf("%d", &N);
	img = (int**) malloc(sizeof(int*) * N);
	for(int i = 0; i < N; i++) {
		scanf("%s", line);
		img[i] = (int*) malloc(sizeof(int) * N);
		for(int j = 0; j < N; j++) {
			if(line[j] == '0') img[i][j] = 0;
			else if(line[j] == '1') img[i][j] = 1;
		}
	}
	
	quadTree(N, img, N, 0, 0);
    
	return 0;
}