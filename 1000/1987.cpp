#include <stdio.h>

int stack[1024][29], pos = 0;

int main() {
	// 0~25: ���ĺ� ��� ����/ 26,27: ���� ��ġ/ 28: ���� �Ÿ�  
	int r, c, m[20][20], t[26], x, y, l;
	int max = 0;
	
	// �Է¹ޱ�  
	scanf("%d %d", &r, &c);
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			scanf(" %c", &x);
			m[i][j] = x - 'A';
		}
	}
	
	// �������� ���ÿ� ����  
	for(int i = 0; i < 28; i++) stack[pos][i] = 0;
	stack[pos][m[0][0]] = 1;
	stack[pos][28] = 1;
	pos++;
	
	// Ž��  
	while(pos > 0) {
		// �ϳ� ������  
		pos--;
		for(int i = 0; i < 26; i++) t[i] = stack[pos][i];
		x = stack[pos][26]; y = stack[pos][27];
		l = stack[pos][28];
		
		// �ִ� �Ÿ� ����  
		if(l > max) max = l;
		
		// ���� ��ġ ����  
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
	
	// ��� ���  
	printf("%d", max);
	
	return 0;
}
