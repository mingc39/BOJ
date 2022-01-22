#include <stdio.h>

int a[9][9];
int b[81][2];
int c;

int sudoku(int n, int v) { // ���� 0 -> n��° ��ĭ�� v �Ұ�, ���� != 0 -> n��° ��ĭ�� v ����  
	// ��ĭ�� ���� ���  
	if(n >= c) return 1;
	
	// ���� �� ĭ ��ġ �ҷ�����  
	int x = b[n][0], y = b[n][1];
	
	// (x, y)�� v�� �� �ִ��� Ȯ�� 
	for(int i = 0; i < 9; i++) {
		if(a[x][i] == v) return 0;
		if(a[i][y] == v) return 0;
		if(a[x / 3 * 3 + i / 3][y / 3 * 3 + i % 3] == v) return 0;
	} 
	
	// (x, y)�� v�� ����
	a[x][y] = v;
	
	// ��� ĭ�� �� ä������ Ȯ�� 
	if(n + 1 == c) return 1;
	
	// ���� �� ĭ ȣ��  
	for(int i = 1; i <= 9; i++) if(sudoku(n + 1, i) != 0) return 1;
	
	// (x, y)�� ���󺹱�  
	a[x][y] = 0;
	
	// ����ĭ �Ǵ� �� ���Ŀ� ���� �Ұ��� ��� 
	return 0;
}

int main() {
	c = 0;
	
	// �Է� �ް� ��ĭ ��ġ ����  
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
	
	// ù��° ĭ�� 1~9 �� �־��  
	for(int i = 1; i <= 9; i++) if(sudoku(0, i) != 0) break;
	
	// ���  
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			putchar(a[i][j] + '0');
			putchar(' ');
		}
		putchar('\n');
	}
	
	return 0;
}
