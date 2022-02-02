#include <stdio.h>

int main() {
	int tc;
	scanf("%d", &tc);
	
	while(tc--) { // 테케 반복 시작  
		int h, w; 
		char map[100][100], key[26] = {0,};
		
		// 지도 입력  
		scanf("%d %d", &h, &w);
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) {
				scanf(" %c", &map[i][j]);
			}
		}
		// 열쇠 입력  
		char str[32];
		scanf("%s", str);
		if(str[0] != '0') {
			for(int i = 0; str[i] != '\0'; i++) {
				key[str[i] - 'a'] = 1;
			}
		}
		
		int q[10240][2], ql = 0, qr = 0;
		int doorCnt[26] = {0,}, doorLoc[26][10000][2];
		
		// 진입 가능 지점 탐색 
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
		// 탐색  
		int docs = 0;
		while(ql != qr) {
			// 탐색할 위치 큐에서 꺼내기  
			int x, y;
			x = q[ql][0];
			y = q[ql][1];
			if(++ql == 10240) ql = 0;
			
			// 해당 위치의 상태에 따라 연산  
			if(map[x][y] == '*') {
				// 벽 또는 이미 탐색 함  
				continue; // 탐색하면 안됨  
			} else if(map[x][y] == '.') {
				// 통로  
				map[x][y] = '*'; // 이미 탐색 했으므로 다음에 탐색 안하게 수정  
			} else if(map[x][y] == '$') {
				// 문서
				map[x][y] = '*'; // 이미 탐색 했으므로 다음에 탐색 안하게 수정 
				docs++; // 문서 개수 증가  
			} else if(map[x][y] >= 'A' && map[x][y] <= 'Z') {
				// 문 
				int t = map[x][y] - 'A';
				map[x][y] = '*'; // 이미 탐색 했으므로 다음에 탐색 안하게 수정 
				if(key[t] == 0) { // 열쇠가 없는 경우 문 위치 기록  
					doorLoc[t][doorCnt[t]][0] = x;
					doorLoc[t][doorCnt[t]][1] = y;
					doorCnt[t]++; // 해당 문자의 문 개수 증가  
					continue; // 못 열었으니까 탐색하면 안됨  
				} // 열쇠 있는 경우엔 통로와 같음  
			} else if(map[x][y] >= 'a' && map[x][y] <= 'z') {
				// 열쇠
				int t = map[x][y] - 'a';
				map[x][y] = '*'; // 이미 탐색 했으므로 다음에 탐색 안하게 수정 
				if(key[t] == 0) { // 해당 문자의 열쇠를 가지고 있지 않았던 경우  
					key[t] = 1;
					for(int i = 0; i < doorCnt[t]; i++) { // 열쇠가 없어서 방문은 했으나 못 열었던 해당 문자의 문 탐색 큐에 삽입   
						map[doorLoc[t][i][0]][doorLoc[t][i][1]] = '.'; // 열 수 있어졌으므로 해당 문이 통로와 같게 됨 
						q[qr][0] = doorLoc[t][i][0];
						q[qr][1] = doorLoc[t][i][1];
						if(++qr == 10240) qr = 0;
					}
				} // 해당 문자의 열쇠를 가지고 있었으면 하나 더 얻어도 달라지는게 없으므로 통로와 같음  
			}
			
			// 다음 위치 큐에 삽입 
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
		
		// 출력 
		printf("%d\n", docs); 
	} // 테케 반복 끝 
	
	return 0;
}
