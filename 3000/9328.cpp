#include <stdio.h>

int main() {
	int tc;
	scanf("%d", &tc);
	
	while(tc--) { // ���� �ݺ� ����  
		int h, w; 
		char map[100][100], key[26] = {0,};
		
		// ���� �Է�  
		scanf("%d %d", &h, &w);
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) {
				scanf(" %c", &map[i][j]);
			}
		}
		// ���� �Է�  
		char str[32];
		scanf("%s", str);
		if(str[0] != '0') {
			for(int i = 0; str[i] != '\0'; i++) {
				key[str[i] - 'a'] = 1;
			}
		}
		
		int q[10240][2], ql = 0, qr = 0;
		int doorCnt[26] = {0,}, doorLoc[26][10000][2];
		
		// ���� ���� ���� Ž�� 
		for(int i = 0; i < h; i++) {
			if(map[i][0] != '*') {
				q[qr][0] = i;
				q[qr][1] = 0;
				if(++qr == 10240) qr = 0;
			}
			if(map[i][w - 1] != '*') {
				q[qr][0] = i;
				q[qr][1] = w - 1;
				if(++qr == 10240) qr = 0;
			}
		}
		for(int i = 1; i < w - 1; i++) {
			if(map[0][i] != '*') {
				q[qr][0] = 0;
				q[qr][1] = i;
				if(++qr == 10240) qr = 0;
			}
			if(map[h - 1][i] != '*') {
				q[qr][0] = h - 1;
				q[qr][1] = i;
				if(++qr == 10240) qr = 0;
			}
		} 
		// Ž��  
		int docs = 0;
		while(ql != qr) {
			// Ž���� ��ġ ť���� ������  
			int x, y;
			x = q[ql][0];
			y = q[ql][1];
			if(++ql == 10240) ql = 0;
			
			// �ش� ��ġ�� ���¿� ���� ����  
			if(map[x][y] == '*') {
				// �� �Ǵ� �̹� Ž�� ��  
				continue; // Ž���ϸ� �ȵ�  
			} else if(map[x][y] == '.') {
				// ���  
				map[x][y] = '*'; // �̹� Ž�� �����Ƿ� ������ Ž�� ���ϰ� ����  
			} else if(map[x][y] == '$') {
				// ����
				map[x][y] = '*'; // �̹� Ž�� �����Ƿ� ������ Ž�� ���ϰ� ���� 
				docs++; // ���� ���� ����  
			} else if(map[x][y] >= 'A' && map[x][y] <= 'Z') {
				// �� 
				int t = map[x][y] - 'A';
				map[x][y] = '*'; // �̹� Ž�� �����Ƿ� ������ Ž�� ���ϰ� ���� 
				if(key[t] == 0) { // ���谡 ���� ��� �� ��ġ ���  
					doorLoc[t][doorCnt[t]][0] = x;
					doorLoc[t][doorCnt[t]][1] = y;
					doorCnt[t]++; // �ش� ������ �� ���� ����  
					continue; // �� �������ϱ� Ž���ϸ� �ȵ�  
				} // ���� �ִ� ��쿣 ��ο� ����  
			} else if(map[x][y] >= 'a' && map[x][y] <= 'z') {
				// ����
				int t = map[x][y] - 'a';
				map[x][y] = '*'; // �̹� Ž�� �����Ƿ� ������ Ž�� ���ϰ� ���� 
				if(key[t] == 0) { // �ش� ������ ���踦 ������ ���� �ʾҴ� ���  
					key[t] = 1;
					for(int i = 0; i < doorCnt[t]; i++) { // ���谡 ��� �湮�� ������ �� ������ �ش� ������ �� Ž�� ť�� ����   
						map[doorLoc[t][i][0]][doorLoc[t][i][1]] = '.'; // �� �� �־������Ƿ� �ش� ���� ��ο� ���� �� 
						q[qr][0] = doorLoc[t][i][0];
						q[qr][1] = doorLoc[t][i][1];
						if(++qr == 10240) qr = 0;
					}
				} // �ش� ������ ���踦 ������ �־����� �ϳ� �� �� �޶����°� �����Ƿ� ��ο� ����  
			}
			
			// ���� ��ġ ť�� ���� 
			if(x + 1 < h) {
				if(map[x + 1][y] != '*') {
					q[qr][0] = x + 1;
					q[qr][1] = y;
					if(++qr == 10240) qr = 0;
				}
			}
			if(x - 1 > -1) {
				if(map[x - 1][y] != '*') {
					q[qr][0] = x - 1;
					q[qr][1] = y;
					if(++qr == 10240) qr = 0;
				}
			}
			if(y + 1 < w) {
				if(map[x][y + 1] != '*') {
					q[qr][0] = x;
					q[qr][1] = y + 1;
					if(++qr == 10240) qr = 0;
				}
			}
			if(y - 1 > -1) {
				if(map[x][y - 1] != '*') {
					q[qr][0] = x;
					q[qr][1] = y - 1;
					if(++qr == 10240) qr = 0;
				}
			}
		}
		
		// ��� 
		printf("%d\n", docs); 
	} // ���� �ݺ� �� 
	
	return 0;
}
