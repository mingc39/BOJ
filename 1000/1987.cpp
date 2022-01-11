#include <stdio.h>

int stack[1024][29], pos = 0;

int main() {
	// 0~25: 알파벳 통과 여부/ 26,27: 현재 위치/ 28: 현재 거리  
	int r, c, m[20][20], t[26], x, y, l;
	int max = 0;
	
	// 입력받기  
	scanf("%d %d", &r, &c);
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			scanf(" %c", &x);
			m[i][j] = x - 'A';
		}
	}
	
	// 시작지점 스택에 삽입  
	for(int i = 0; i < 28; i++) stack[pos][i] = 0;
	stack[pos][m[0][0]] = 1;
	stack[pos][28] = 1;
	pos++;
	
	// 탐색  
	while(pos > 0) {
		// 하나 꺼내기  
		pos--;
		for(int i = 0; i < 26; i++) t[i] = stack[pos][i];
		x = stack[pos][26]; y = stack[pos][27];
		l = stack[pos][28];
		
		// 최대 거리 갱신  
		if(l > max) max = l;
		
		// 다음 위치 삽입  
		if(x - 1 >= 0) {
			if(t[m[x - 1][y]] == 0) {
				for(int i = 0; i < 26; i++) stack[pos][i] = t[i];
				stack[pos][m[x - 1][y]] = 1;
				stack[pos][26] = x - 1; stack[pos][27] = y;
				stack[pos][28] = l + 1;
				pos++;
			}
		}
		if(x + 1 < r) {
			if(t[m[x + 1][y]] == 0) {
				for(int i = 0; i < 26; i++) stack[pos][i] = t[i];
				stack[pos][m[x + 1][y]] = 1;
				stack[pos][26] = x + 1; stack[pos][27] = y;
				stack[pos][28] = l + 1;
				pos++;
			}
		}
		
		if(y - 1 >= 0) {
			if(t[m[x][y - 1]] == 0) {
				for(int i = 0; i < 26; i++) stack[pos][i] = t[i];
				stack[pos][m[x][y - 1]] = 1;
				stack[pos][26] = x; stack[pos][27] = y - 1;
				stack[pos][28] = l + 1;
				pos++;
			}
		}
		if(y + 1 < c) {
			if(t[m[x][y + 1]] == 0) {
				for(int i = 0; i < 26; i++) stack[pos][i] = t[i];
				stack[pos][m[x][y + 1]] = 1;
				stack[pos][26] = x; stack[pos][27] = y + 1;
				stack[pos][28] = l + 1;
				pos++;
			}
		}
	}
	
	// 결과 출력  
	printf("%d", max);
	
	return 0;
}
