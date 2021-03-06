#include <stdio.h>

int a[9][9];
int b[81][2];
int c;

int sudoku(int n, int v) { // 리턴 0 -> n번째 빈칸에 v 불가, 리턴 != 0 -> n번째 빈칸에 v 가능  
	// 빈칸이 없는 경우  
	if(n >= c) return 1;
	
	// 다음 빈 칸 위치 불러오기  
	int x = b[n][0], y = b[n][1];
	
	// (x, y)가 v일 수 있는지 확인 
	for(int i = 0; i < 9; i++) {
		if(a[x][i] == v) return 0;
		if(a[i][y] == v) return 0;
		if(a[x / 3 * 3 + i / 3][y / 3 * 3 + i % 3] == v) return 0;
	} 
	
	// (x, y)를 v로 변경
	a[x][y] = v;
	
	// 모든 칸을 다 채웠는지 확인 
	if(n + 1 == c) return 1;
	
	// 다음 빈 칸 호출  
	for(int i = 1; i <= 9; i++) if(sudoku(n + 1, i) != 0) return 1;
	
	// (x, y)를 원상복귀  
	a[x][y] = 0;
	
	// 다음칸 또는 그 이후에 진행 불가인 경우 
	return 0;
}

int sususudoku() {
	c = 0;
	
	// 입력 받고 빈칸 위치 저장  
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			scanf(" %c", &a[i][j]);
			a[i][j] -= '0';
			if(a[i][j] == 0) {
				b[c][0] = i;
				b[c][1] = j;
				c++;
			}
		}
	}
	
	// 첫번째 칸에 1~9 다 넣어보기  
	int t = 0;
	for(int i = 1; i <= 9; i++) if((t = sudoku(0, i)) != 0) break;
	
	// 모순이 없는지 확인 
	for(int x = 0; x < 9; x++) {
		for(int y = 0; y < 9; y++) {
			for(int i = 0; i < 9; i++) {
				if(a[x][i] == a[x][y] && i != y) t = 0;
				if(a[i][y] == a[x][y] && i != x) t = 0;
				if(a[x / 3 * 3 + i / 3][y / 3 * 3 + i % 3] == a[x][y] && x / 3 * 3 + i / 3 != x && y / 3 * 3 + i % 3 != y) t = 0;
			}
		}
	}
	
	// 출력  
	if(t == 0) printf("Could not complete this grid.\n\n");
	else {
		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++)
				putchar(a[i][j] + '0');
			putchar('\n');
		}
		putchar('\n');
	}
	
	return 0;
}

int main() {
	int tc;
	
	// 테스트 케이스 입력 
	scanf("%d", &tc);
	
	// 테스트 케이스만큼 문제풀이 반복  
	while(tc--) sususudoku();
	
	return 0;
}
